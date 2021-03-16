/*Código que hace que un parlante toque las notas músicales una a una cada vez que recibe un paquete UDP*/


#include <ESP8266WiFi.h>
#include <WiFiUdp.h>

/*
do4 = 261.63, posicion 0 en el array
re4 = 293.66
mi4 = 329.63
fa4 = 349.23
sol4 = 320
la4 = 440
si4 = 493.88, posicion 6 en el array
*/
//                   do=0  re=1     mi=2   fa=3   sol=4 la=5   si=6
float escala_4[] = {261.63, 293.66, 329.63, 349.23, 392, 440, 493.88}; //array que contiene las frecuencias de las notas musicales (e Hz)
int contador = 0;
long potencia_recibida;


//datos para conectarse a la red WiFi
const char* ssid = "SmartChoice_Javier";
const char* contrasena = "988867494";

//creando una estructura de la clase WiFiUDP
WiFiUDP udp;
unsigned int puerto_local = 9999; //puerto en que la placa escuchara
char paquete_entrante[255]; //inicializando un array para almacenar los paquetes entrantes
char respuesta[] = "Paquete recibido baby";

byte parlante = D5;

void setup() {
  pinMode(parlante, OUTPUT);
  
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
  potencia_recibida = WiFi.RSSI();
  Serial.printf(" Potencia señal: %ld", potencia_recibida); 
}

void loop() {
  
  int tamanoPaquete = udp.parsePacket();
  
  if (contador > 6) { //para empezar con las notas de nuevo después de llegar a la última
     contador = 0;
     }
     
  if (tamanoPaquete) {
    Serial.printf("\nRecibidos %d bytes desde %s, puerto %d", tamanoPaquete, udp.remoteIP().toString().c_str(), udp.remotePort());
    Serial.printf (" Potencia señal WIFI: %ld", potencia_recibida);
    tone(parlante, escala_4[contador]);
    delay(200);
    noTone(parlante);
    contador++;
    
    //enviando una respuesta a la dirección IP que envió el paquete
    udp.beginPacket(udp.remoteIP(), 60000);
    udp.write("Parlante encendido baby");
    udp.endPacket();
    }
   
}
