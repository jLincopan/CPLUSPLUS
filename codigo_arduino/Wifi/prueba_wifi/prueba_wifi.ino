#include <ESP8266WiFi.h>
#include <WiFiUdp.h>

//datos para conectarse a la red WiFi
const char* ssid = "SmartChoice_Javier";
const char* contrasena = "988867494";

//creando una estructura de la clase WiFiUDP
WiFiUDP udp;
unsigned int puerto_local = 9999; //puerto en que la placa escuchara
char paquete_entrante[255]; //inicializando un array para almacenar los paquetes entrantes
char respuesta[] = "Paquete recibido baby";

byte ledRojo = D5;
byte ledVerde = D6;
byte ledAzul = D7;

void setup() {
  pinMode(ledRojo, OUTPUT);
  pinMode(ledVerde, OUTPUT);
  pinMode(ledAzul, OUTPUT);
  
  Serial.begin(115200); //inicializando puerto serial
  WiFi.begin(ssid, contrasena); //conectando a la red wifi

  Serial.printf("\nConectando");
  /*bucle que se ejecuta hasta que la placa establezca una conexión*/
  while (WiFi.status() != WL_CONNECTED) { 
    Serial.print(".");
    delay(100);
    } 
    
  Serial.println("\nConexión establecida");
  udp.begin(puerto_local);
  Serial.printf("Escuchando, dirección IP asignada en la red: %s, puerto de escucha %d", WiFi.localIP().toString().c_str(), puerto_local);
}

void loop() {
  
  int tamanoPaquete = udp.parsePacket();
  digitalWrite(ledRojo, HIGH);
  digitalWrite(ledVerde, HIGH);
  digitalWrite(ledAzul, HIGH);

   
  if (tamanoPaquete) {
    Serial.printf("\nRecibidos %d bytes desde %s, puerto %d", tamanoPaquete, udp.remoteIP().toString().c_str(), udp.remotePort());
  analogWrite(ledRojo, -255);
  analogWrite(ledVerde, -255);
  analogWrite(ledAzul, 0);
  
    //enviando una respuesta a la dirección IP que envió el paquete
    udp.beginPacket(udp.remoteIP(), 60000);
    udp.write("led encendido baby");
    udp.endPacket();
    delay(100);
    }
   
}
