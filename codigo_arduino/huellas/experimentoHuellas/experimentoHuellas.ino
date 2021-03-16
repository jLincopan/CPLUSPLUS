#include "/home/javier/Escritorio/Programacion/Arduino/Adafruit_Fingerprint(experimento).cpp"
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
  
  while (1) {
    
     if (finger.verifyPassword()) {
      
       Serial.println("¡Lector de huellas detectado!, listo para funcionar\n");
       break;
       
     } else {
      
       Serial.println("El lector de huellas no pudo ser detectado :(");
       delay(100); }
  }
}

void loop() {
  
  delay(10000);
  tomarImagen();

}

void tomarImagen() {
  
  //Cabecera
  puertoLector.write((uint8_t)highByte(0xef01));
  puertoLector.write((uint8_t)lowByte(0xef01));

  //Dirección del sensor
  puertoLector.write((uint8_t)0xff);
  puertoLector.write((uint8_t)0xff);
  puertoLector.write((uint8_t)0xff);
  puertoLector.write((uint8_t)0xff);

  //tipo de paquete, 0x01 corresponde a un comando
  puertoLector.write((uint8_t)0x01);
  
  //Longitud del paquete
  puertoLector.write((uint8_t)highByte(0x0003));
  puertoLector.write((uint8_t)lowByte(0x0003));
  
  //Sección de datos
  puertoLector.write((uint8_t)0x01);

  //Checksum
  puertoLector.write((uint8_t)highByte(0x0005));
  puertoLector.write((uint8_t)lowByte(0x0005));}
