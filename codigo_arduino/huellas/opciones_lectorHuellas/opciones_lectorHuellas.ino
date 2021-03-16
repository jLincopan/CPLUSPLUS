/*
Rojo: 5.5v / Verde: pin 16 / Blanco: pin 17 / Negro: GND / 
*/

#include <Adafruit_Fingerprint.h>

HardwareSerial puertoLector(2); //Usamos uno de los 3 puertos seriales (UARTS) que trae la placa integrados en el hardware
                                //El numerito es para indicar el UART que usaremos (0 = UART 1, 1 = UART2,
                                //2 = UART 3), los demás no se pueden usar (0 creo que es el que se utiliza en la
                                //comunicación serial normal, 1 no se puede usar sin modificar las librerías que trae
                                //el esp32)
                                
                                //https://docs.google.com/spreadsheets/d/12qL3ui2BkSn91O0ISJU8QIL2mcG-r_vlX0briknA2QQ/edit#gid=1401515447

Adafruit_Fingerprint finger = Adafruit_Fingerprint(&puertoLector); //creamos un objeto Adafruit_Fingerprint y le pasamos
                                                                   //un puntero hacia el objeto que maneja el puerto serial
                                                                   //que definimos antes

uint8_t id;

void setup()  
{
  Serial.begin(9600);
  while (!Serial);
  delay(100);
  Serial.println("\n\nLector de huellas\n\n");

  // set the data rate for the sensor serial port
  finger.begin(57600);
  
  if (finger.verifyPassword()) {
    Serial.println("¡Lector de huellas detectado!, listo para funcionar\n");
  } else {
    Serial.println("El lector de huellas no pudo ser detectado :(");
    while (1) { delay(1); }
  }
}

//Función para leer números desde el teclado
uint8_t leerNumero(void) {
  uint8_t num = 0;
  
  while (num == 0) {
    while (! Serial.available());
    num = Serial.parseInt();
  }
  return num;
}

void loop() {
  
  Serial.println("Elija una opción:");
  Serial.println("                  1) Registrar una nueva huella digital");
  Serial.println("                  2) Descargar los datos de un registro\n");

  byte opcion = leerNumero();

  switch (opcion) {
    
    case 0:
          Serial.println("Opción no válida\n\n");
          break;
    case 1:
         registrarDedo();
         break;
    
    case 2:
         Serial.println("Ingrese la ID de la huella dactilar que desea descargar");
         byte id = leerNumero();
         descargarModelo(id);
         break;
  }
}

uint8_t registrarDedo() {

  int p = -1;
  Serial.println("¡Preparado para registrar huellas dactilares!");
  Serial.println("Por favor, ingrese la ID (de 1 a 127) con la que quiere registrar este dedo...");
  
  id = leerNumero();
  
  if (id == 0) {// ID #0 not allowed, try again!
     return p;
  }
  
  Serial.print("Registrando ID #");
  Serial.println(id);
  Serial.println();
  
  Serial.print("Esperando dedo para registrar\n");
  
  while (p != FINGERPRINT_OK) {  
    p = finger.getImage();
    switch (p) {
    case FINGERPRINT_OK:
      Serial.println("Imagen tomada");
      break;
    case FINGERPRINT_NOFINGER:
      Serial.print(".");
      break;
    case FINGERPRINT_PACKETRECIEVEERR:
      Serial.println("Error de comunicaciones\n");
      break;
    case FINGERPRINT_IMAGEFAIL:
      Serial.println("Error de imagen\n");
      break;
    default:
      Serial.println("Error desconocido\n");
      break;
    }
  }

  // OK success!

  p = finger.image2Tz(1);
  switch (p) {
    case FINGERPRINT_OK:
      Serial.println("Imagen procesada");
      break;
    case FINGERPRINT_IMAGEMESS:
      Serial.println("Imagen demasiado borrosa\n");
      return p;
    case FINGERPRINT_PACKETRECIEVEERR:
      Serial.println("Error de comunicaciones\n");
      return p;
    case FINGERPRINT_FEATUREFAIL:
      Serial.println("No se pudo identificar características de huella dactilar\n");
      return p;
    case FINGERPRINT_INVALIDIMAGE:
      Serial.println("No se pudo identificar características de huella dactilar\n");
      return p;
    default:
      Serial.println("Error desconocido\n");
      return p;
  }
  
  Serial.println("Remueva el dedo del sensor\n");
  delay(2000);
  
  p = 0;
  while (p != FINGERPRINT_NOFINGER) { //No deja avanzar hasta que se saque el dedo
    p = finger.getImage();
  }
  
  p = -1;
  Serial.println("Coloque el mismo dedo otra vez");
  
  while (p != FINGERPRINT_OK) {
    p = finger.getImage();
    switch (p) {
    case FINGERPRINT_OK:
      Serial.println("Imagen tomada");
      break;
    case FINGERPRINT_NOFINGER:
      Serial.print(".");
      break;
    case FINGERPRINT_PACKETRECIEVEERR:
      Serial.println("Error de comunicaciones\n");
      break;
    case FINGERPRINT_IMAGEFAIL:
      Serial.println("Error de imagen\n");
      break;
    default:
      Serial.println("Error desconocido\n");
      break;
    }
  }

  // OK success!

  p = finger.image2Tz(2);
  switch (p) {
    case FINGERPRINT_OK:
      Serial.println("Imagen procesada");
      break;
    case FINGERPRINT_IMAGEMESS:
      Serial.println("Imagen demasiado borrosa\n");
      return p;
    case FINGERPRINT_PACKETRECIEVEERR:
      Serial.println("Error de comunicaciones\n");
      return p;
    case FINGERPRINT_FEATUREFAIL:
      Serial.println("No se pudo identificar características de huella dactilar\n");
      return p;
    case FINGERPRINT_INVALIDIMAGE:
      Serial.println("No se pudo identificar características de huella dactilar\n");
      return p;
    default:
      Serial.println("Error desconocido\n");
      return p;
  }
  
  // OK converted!
  Serial.print("Creando modelo para #");  Serial.println(id);
  
  p = finger.createModel();
  if (p == FINGERPRINT_OK) {
    Serial.println("¡Las huellas coinciden!");
  } else if (p == FINGERPRINT_PACKETRECIEVEERR) {
    Serial.println("Error de comunicaciones\n");
    return p;
  } else if (p == FINGERPRINT_ENROLLMISMATCH) {
    Serial.println("Las huellas no coinciden\n");
    return p;
  } else {
    Serial.println("Error desconocido\n");
    return p;
  }   
  
  Serial.print("ID "); Serial.println(id);
  p = finger.storeModel(id);
  if (p == FINGERPRINT_OK) {
    Serial.println("¡Guardado!\n");
    return p;
  } else if (p == FINGERPRINT_PACKETRECIEVEERR) {
    Serial.println("Error de comunicaciones\n");
    return p;
  } else if (p == FINGERPRINT_BADLOCATION) {
    Serial.println("No se puede almacenar en esa ubicación\n");
    return p;
  } else if (p == FINGERPRINT_FLASHERR) {
    Serial.println("Error de escritura en la memoria flash\n");
    return p;
  } else {
    Serial.println("Error desconocido\n");
    return p;
  }
}

uint8_t descargarModelo(uint16_t id) {
  Serial.println("------------------------------------");
  Serial.print("Intentando cargar modelo #"); Serial.println(id);
  uint8_t p = finger.loadModel(id);
  
  switch (p) {
    case FINGERPRINT_OK:
      Serial.print("Modelo "); Serial.print(id); Serial.println(" cargado");
      break;
    case FINGERPRINT_PACKETRECIEVEERR:
      Serial.println("Error de comunicaciones");
      return p;
    case 12: 
      Serial.println("El modelo solicitado no está registrado");
      return p;
    default:
      Serial.print("Error desconocido: "); Serial.println(p);
      return p;
  }

  // OK success!

  Serial.print("Intentando descargar el modelo #"); Serial.println(id);
  p = finger.getModel();
  switch (p) {
    case FINGERPRINT_OK:
      Serial.print("Transfiriendo "); Serial.print("modelo #"); Serial.println(id);
      break;
   default:
      Serial.print("Error desconocido: "); Serial.println(p);
      return p;
  }
  
  // one data packet is 267 bytes. in one data packet, 11 bytes are 'usesless' :D
  uint8_t bytesReceived[534]; // 2 data packets
  memset(bytesReceived, 0xff, 534);

  //recibiendo los datos!
  uint32_t starttime = millis();
  int i = 0;
  
  while (i < 534 && (millis() - starttime) < 20000) {
      if (puertoLector.available()) {
          bytesReceived[i++] = puertoLector.read();
      }
  }
  
  Serial.print(i); Serial.println(" bytes leídos.");
  Serial.println("Decodificando paquete...\n");

  uint8_t fingerTemplate[512]; // the real template
  memset(fingerTemplate, 0xff, 512);

  // filtering only the data packets
  int uindx = 9, index = 0;
  while (index < 534) {
      while (index < uindx) ++index;
      uindx += 256;
      while (index < uindx) {
          fingerTemplate[index++] = bytesReceived[index];
      }
      uindx += 2;
      while (index < uindx) ++index;
      uindx = index + 9;
  }


  //Imprimiendo los datos
  
  for (int i = 0; i < 512; ++i) {
      Serial.print("0x");
      printHex(fingerTemplate[i], 2);
      Serial.print(" ");
  }
  
  Serial.println("\nCompletado\n");

  /* para imprimir los datos en 16 filas de 16 columnas
  uint8_t templateBuffer[256];
  memset(templateBuffer, 0xff, 256);  //zero out template buffer
  int index=0;
  uint32_t starttime = millis();
  while ((index < 256) && ((millis() - starttime) < 1000))
  {
    if (mySerial.available())
    {
      templateBuffer[index] = mySerial.read();
      index++;
    }
  }
  
  Serial.print(index); Serial.println(" bytes read");
  
  //dump entire templateBuffer.  This prints out 16 lines of 16 bytes
  for (int count= 0; count < 16; count++)
  {
    for (int i = 0; i < 16; i++)
    {
      Serial.print("0x");
      Serial.print(templateBuffer[count*16+i], HEX);
      Serial.print(", ");
    }
    Serial.println();
  }*/
}



void printHex(int num, int precision) {
    char tmp[16];
    char format[128];
 
    sprintf(format, "%%.%dX", precision);
 
    sprintf(tmp, format, num);
    Serial.print(tmp);
}
