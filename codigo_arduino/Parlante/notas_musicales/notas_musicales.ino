/*
pequeño programa que toca las notas musicales con un parlante conectado ( el pin D0 y D1 hacen interferencia con el
puerto serial)

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

byte parlante = D3; // el pin del parlante

void setup() {
  pinMode(parlante, INPUT);
  Serial.begin(9600);
}

void loop() {

for (int i = 0; i < 7; i++) { //recorre todas las notas en el array
  tone(parlante, escala_4[i]);
  delay(400);
  }
 
}
