#include <U8x8lib.h>

//entrada del potenciometro
byte pot = 0;
byte voltajeBateria = 13;
byte pin_actLectura = 21;
float pot_val;
float datos;
U8X8_SSD1306_128X64_NONAME_SW_I2C pantalla(/* clock=*/ 15, /* data=*/ 4, /* reset=*/ 16);

void setup() {
  pinMode(pot, INPUT);
  pinMode(pin_actLectura, OUTPUT);
  pinMode(voltajeBateria, OUTPUT);
  Serial.begin(9600); //inicializando puerto serial
  pantalla.begin(); //inicializando la pantalla 
 pantalla.setFont(u8x8_font_pxplusibmcgathin_r); //estableciendo la fuente de letras a usar
}

void loop() {
    

    digitalWrite(pin_actLectura, LOW);
    delay(500);
    datos = analogRead(voltajeBateria)/495.79611650485;
    pantalla.setCursor(0, 0);
    pantalla.print(datos);
    //delay(5000);

}
