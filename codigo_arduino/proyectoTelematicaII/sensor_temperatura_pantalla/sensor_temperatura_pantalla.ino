//requiere las bibliotecas oneWire, dallasTemperature y u8x8 (este último es para la pantalla)
#include <OneWire.h>
#include <DallasTemperature.h>
#include <U8x8lib.h>

//sensor de temperatura
#define pin_temperatura 22


//pantalla (modelo), creamos un objeto y le asignamos características (sus pines)
U8X8_SSD1306_128X64_NONAME_SW_I2C pantalla(/* clock=*/ 15, /* data=*/ 4, /* reset=*/ 16);


OneWire bus_datos(pin_temperatura);
DallasTemperature sensor_temperatura(&bus_datos);

void setup() {
 Serial.begin(9600); //inicializamos el puerto serial
 sensor_temperatura.begin(); //inicializamos el sensor
 
 pantalla.begin(); //inicializando la pantalla 
 pantalla.setFont(u8x8_font_pxplusibmcgathin_r); //estableciendo la fuente de letras a usar

}

void loop() {
  
  sensor_temperatura.requestTemperatures();

  // Leemos la temperatura en grados centígrados (por defecto)
  float temperatura = sensor_temperatura.getTempCByIndex(0); //el número es para identificar los sensores cuando hay varios conectados
  
  //mostrando por el puerto serial                                                                         
  Serial.print(" %\t");
  Serial.print("Temperatura: ");
  Serial.print(temperatura);
  Serial.println(" *C ");

  //mostrando por la pantalla
  pantalla.drawString(0, 0, "Datos:");
  pantalla.drawString(0, 2, "Temp: "); //temperatura
  pantalla.setCursor(6, 2);
  pantalla.print(temperatura);
  pantalla.drawString(12, 2, "C*");
  

}
