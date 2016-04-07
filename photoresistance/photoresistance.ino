int flame = A0;
int Beep = 7;
int val = 0;
void setup() {
  pinMode(Beep, OUTPUT);
  pinMode(flame, INPUT);
  Serial.begin(9600);
}
void loop() {
  val = analogRead(flame);
  Serial.println(val);
  if (val >= 300)
  {
    //digitalWrite(Beep, HIGH);

    tone(Beep, val);

  } else {
    //digitalWrite(Beep, LOW);
    noTone(Beep);
  }

  delay(500);
}

