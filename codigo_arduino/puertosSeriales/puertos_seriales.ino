void setup() {
  Serial1.begin(57600, 16, 17);
  Serial2.begin(9600);
}

void loop() {
  while (Serial1.available() == 1) {

    Serial2.println(char(Serial1.read()));
    
    }
}
