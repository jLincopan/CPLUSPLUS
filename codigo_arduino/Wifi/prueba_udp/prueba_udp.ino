#include <WiFi.h>
#include <WiFiUdp.h>

const char* ssid = "SmartChoice_Javier";
const char* password = "988867494";

const char* ip_destino = "192.168.0.104";
const int puerto_destino = 5005;

WiFiUDP udp;

void conectar() {
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(100);
    Serial.print(".");
    }
  Serial.print("");
  Serial.print("Conectado a: ");
  Serial.println(ssid);

  Serial.print("Dirección IP: ");
  Serial.println(WiFi.localIP());

  //Inicializando udp y un buffer de transferencia
  udp.begin(puerto_destino);  
    
  }

  void enviarDatos() {
    uint8_t buffer[50] = "Hola k ase";

    udp.beginPacket(ip_destino, puerto_destino);
    udp.write(buffer, 11);
    udp.endPacket();
    memset(buffer, 0, 50);
    }
  
void setup() {
  Serial.begin(9600);
  conectar();

}

void loop() {
  enviarDatos();
}
