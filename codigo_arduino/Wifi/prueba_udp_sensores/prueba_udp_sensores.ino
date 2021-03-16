#include <OneWire.h>
#include <DallasTemperature.h>
#include <WiFi.h>
#include <WiFiUdp.h>
#include <DHT.h>

#define pin_temperatura 22
#define pin_humedad 0
#define tipo_sensor DHT11

DHT sensor_humedad(pin_humedad, tipo_sensor); //creamos un objeto de la clase DHT, y le asignamos características (pin y tipo de sensor)
OneWire bus_datos(pin_temperatura); //especificando cual es nuestro bus de datos (solo del sensor de temperatura)
DallasTemperature sensor_temperatura(&bus_datos);

//Datos de la red WIFI
const char* ssid = "SmartChoice_Javier";
const char* password = "988867494";

const char* ip_destino = "192.168.0.109";
const int puerto_destino = 15000;

String datos = "";

WiFiUDP udp;

void conectar() {
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(100);
    }

  //Inicializando udp y un buffer de transferencia
  udp.begin(puerto_destino);  
    
  }

  void enviarDatos(String dat) {
    
    udp.beginPacket(ip_destino, puerto_destino);
    udp.print(dat);
    udp.endPacket();
    }

void setup() {
  conectar();
  sensor_humedad.begin(); //inicializamos el sensor de humedad
  sensor_temperatura.begin(); //inicializando el sensor de temperatura
}

void loop() {
  // Leemos la humedad relativa
  float humedad = sensor_humedad.readHumidity();
  datos = "Humedad: ";
  datos.concat(humedad);
  datos = datos + " % ";
  
  // Leemos la temperatura en grados centígrados (por defecto)
  sensor_temperatura.requestTemperatures();
  float temperatura = sensor_temperatura.getTempCByIndex(0); //el número es para identificar los sensores de temperatura cuando hay varios conectados

  datos = datos + "Temperatura: ";
  datos.concat(temperatura);
  datos = datos + " *C";
  
  if ((!isnan(temperatura)) && (!isnan(humedad))) {
    enviarDatos(datos);
    delay(1000);
    }
    else {
      }
  datos = "";
}
