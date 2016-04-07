int a = 2;
int b = 3;
int c = 4;
int d = 5;
int e = 6;
int f = 7;
int g = 8;
int dp = 9;

//蜂鸣器
int buzzer = A0;

void cleanAll() {
  int i;
  for (i = 2; i <= 9; i++) {
    digitalWrite(i, HIGH);
  }
}
void lightAll() {
  int i;
  for (i = 2; i <= 9; i++) {
    digitalWrite(i, LOW);
  }
}

void digital_0()
{
  lightAll();
  digitalWrite(g, HIGH);
}

void digital_1() //显示数字1
{
  cleanAll();
  digitalWrite(c, LOW);
  digitalWrite(b, LOW);
}
void digital_2() //显示数字2
{
  lightAll();
  digitalWrite(c, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(dp, HIGH);
}
void digital_3() //显示数字3
{
  lightAll();
  digitalWrite(e, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(dp, HIGH);
}
void digital_4() //显示数字4
{
  digitalWrite(c, LOW);
  digitalWrite(b, LOW);
  digitalWrite(f, LOW);
  digitalWrite(g, LOW);
  digitalWrite(dp, HIGH);
  digitalWrite(a, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(d, HIGH);
}
void digital_5() //显示数字5
{
  lightAll();

  digitalWrite(dp, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(e, HIGH);
}
void digital_6() //显示数字6
{
  lightAll();
  digitalWrite(dp, HIGH);
  digitalWrite(b, HIGH);
}
void digital_7() //显示数字7
{
  cleanAll();
  digitalWrite(a, LOW);
  digitalWrite(c, LOW);
  digitalWrite(b, LOW);
}
void digital_8() //显示数字8
{
  lightAll();
  digitalWrite(dp, HIGH);
}

void digital_9() {
  lightAll();
  digitalWrite(dp, HIGH);
  digitalWrite(e, HIGH);

}

void setup()
{
  pinMode(buzzer, OUTPUT);
  int i;
  for (i = 2; i <= 9; i++) {
    pinMode(i, OUTPUT);
    digitalWrite(i, HIGH);
  }
}

void bee() {
  int i;

  for (i = 0; i < 100; i++) //输出一个频率的声音
  {
    digitalWrite(buzzer, HIGH);
    delayMicroseconds(250);
    digitalWrite(buzzer, LOW);
    delayMicroseconds(250);
  }
  for (i = 0; i < 100; i++) //输出另一个频率的声音
  {
    digitalWrite(buzzer, HIGH);
    delayMicroseconds(500);
    digitalWrite(buzzer, LOW);
    delayMicroseconds(500);
  }

  delay(850);
  //  digitalWrite(buzzer, HIGH); //发声音
  //  digitalWrite(buzzer, LOW);
  //  delay(1000);
}

void loop()
{
 
  digital_1();
  bee();
  digital_2();
  bee();
  digital_3();
  bee();
  digital_4();
  bee();
  digital_5();
  bee();
  digital_6();
  bee();
  digital_7();
  bee();
  digital_8();
  bee();
  digital_9();
  bee();
  digital_0();
  digitalWrite(buzzer, HIGH); //发声音
  delay(1000);
  digitalWrite(buzzer, LOW);
  delay(1000);
}


