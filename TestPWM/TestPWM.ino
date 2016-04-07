const int a1 = 9;
const int a2 = 10;

void setup() {
  pinMode(a1, OUTPUT);
  pinMode(a2, OUTPUT);

}

void loop() {
  digitalWrite(a2, LOW);

  for (int i = 0; i < 255; i++) {
    analogWrite(a1, i);
    delay(50);
  }
  delay(1000);


  digitalWrite(a1, LOW);

  for (int i = 0; i < 255; i++) {
    analogWrite(a2, i);
    delay(50);
  }
  delay(1000);


}
