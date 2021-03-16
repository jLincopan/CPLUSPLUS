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
void setup()  
{
  Serial.begin(9600);
  while (!Serial);  
  delay(100);
  Serial.println("\n\nLector de huellas");

  // set the data rate for the sensor serial port
  finger.begin(57600);
  
  if (finger.verifyPassword()) {
    Serial.println("¡Lector de huellas detectado!");
  } else {
    Serial.println("El lector de huellas no pudo ser detectado :(");
    while (1) { delay(1); }
  }

  finger.getTemplateCount();
  Serial.print("El sensor contiene: "); Serial.print(finger.templateCount); Serial.println(" huellas registradas");
  Serial.println("Esperando dedo...");
}

void loop()
{
  verificarHuella();
  delay(50);            //don't ned to run this at full speed.
}

uint8_t verificarHuella() {
  
  uint8_t p = finger.getImage();
  switch (p) {
    case FINGERPRINT_OK:
      Serial.println("\nImagen tomada");
      break;
    case FINGERPRINT_NOFINGER:
      Serial.print(".");
      return p;
    case FINGERPRINT_PACKETRECIEVEERR:
      Serial.println("\nError de comunicaciones");
      return p;
    case FINGERPRINT_IMAGEFAIL:
      Serial.println("\nError de imagen");
      return p;
    default:
      Serial.println("\nError desconocido");
      return p;
  }

  // OK success!

  p = finger.image2Tz();
  switch (p) {
    case FINGERPRINT_OK:
      Serial.println("Imagen procesada");
      break;
    case FINGERPRINT_IMAGEMESS:
      Serial.println("Imagen demasiado borrosa");
      return p;
    case FINGERPRINT_PACKETRECIEVEERR:
      Serial.println("Error de comunicaciones");
      return p;
    case FINGERPRINT_FEATUREFAIL:
      Serial.println("No se pudo encontrar características de huella digital");
      return p;
    case FINGERPRINT_INVALIDIMAGE:
      Serial.println("No se pudo encontrar características de huella digital");
      return p;
    default:
      Serial.println("Error desconocido");
      return p;
  }
  
  // OK converted!
  p = finger.fingerFastSearch();
  if (p == FINGERPRINT_OK) {
    Serial.println("La huella se encuentra en la base de datos");
  } else if (p == FINGERPRINT_PACKETRECIEVEERR) {
    Serial.println("Error de comunicaciones");
    return p;
  } else if (p == FINGERPRINT_NOTFOUND) {
    Serial.println("La huella no se encuentra en la base de datos");
    return p;
  } else {
    Serial.println("Error desconocido");
    return p;
  }   
  
  // found a match!
  Serial.print("ID  de la huella: #"); Serial.print(finger.fingerID); 
  Serial.print(", con una certeza de: "); Serial.print(finger.confidence); Serial.println("%\n"); 

  return 0;
}
