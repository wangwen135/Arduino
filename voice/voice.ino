const int DO = 8;
const int AO = 0;

int ledA = 6;
int ledD = 7;

void setup() {

  pinMode(DO, INPUT);
  //pinMode(AO, INPUT);

  pinMode(ledA, OUTPUT);
  pinMode(ledD, OUTPUT);

  //Serial.begin(9600);
}

void loop() {
  int d = digitalRead(DO);

  digitalWrite(ledD , d);


  //  Serial.print(d);
  //  Serial.print("  ");
  int a = analogRead(AO);

  analogWrite(ledA, a);

  //  Serial.println( a);

  //  delay(100);

}
