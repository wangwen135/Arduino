int a = 2; 
int b = 3; 
int c = 4; 
int d = 5; 
int e = 6; 
int f = 7; 
int g = 8; 
int dp = 9;

void digital_1(void) //显示数字1
{
  unsigned char j;
  digitalWrite(c, HIGH); //给数字接口5 引脚高电平，点亮c 段
  digitalWrite(b, HIGH); //点亮b 段
  for (j = 7; j <= 11; j++) //熄灭其余段
    digitalWrite(j, LOW);
  digitalWrite(dp, LOW); //熄灭小数点DP 段
}
void digital_2(void) //显示数字2
{
  unsigned char j;
  digitalWrite(b, HIGH);
  digitalWrite(a, HIGH);
  for (j = 9; j <= 11; j++)
    digitalWrite(j, HIGH);
  digitalWrite(dp, LOW);
  digitalWrite(c, LOW);
  digitalWrite(f, LOW);
}
void digital_3(void) //显示数字3
{
  unsigned char j;
  digitalWrite(g, HIGH);
  digitalWrite(d, HIGH);
  for (j = 5; j <= 7; j++)
    digitalWrite(j, HIGH);
  digitalWrite(dp, LOW);
  digitalWrite(f, LOW);
  digitalWrite(e, LOW);
}
void digital_4(void) //显示数字4
{
  digitalWrite(c, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
  digitalWrite(dp, LOW);
  digitalWrite(a, LOW);
  digitalWrite(e, LOW);
  digitalWrite(d, LOW);
}
void digital_5(void) //显示数字5
{
  unsigned char j;
  for (j = 7; j <= 9; j++)
    digitalWrite(j, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(dp, LOW);
  digitalWrite(b, LOW);
  digitalWrite(e, LOW);
}
void digital_6(void) //显示数字6
{
  unsigned char j;
  for (j = 7; j <= 11; j++)
    digitalWrite(j, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(dp, LOW);
  digitalWrite(b, LOW);
}
void digital_7(void) //显示数字7
{
  unsigned char j;
  for (j = 5; j <= 7; j++)
    digitalWrite(j, HIGH);
  digitalWrite(dp, LOW);
  for (j = 8; j <= 11; j++)
    digitalWrite(j, LOW);
}
void digital_8(void) //显示数字8
{
  unsigned char j;
  for (j = 5; j <= 11; j++)
    digitalWrite(j, HIGH);
  digitalWrite(dp, LOW);
}
void setup()
{
  int i;
  for (i = 2; i <= 9; i++) {
    pinMode(i, OUTPUT);
    digitalWrite(i, LOW);
  }
}
void loop()
{
  digital_1();//显示数字1
  delay(2000);//延时2s
  digital_2();//显示数字2
  delay(1000); //延时1s
  digital_3();//显示数字3
  delay(1000); //延时1s
  digital_4();//显示数字4
  delay(1000); //延时1s
  digital_5();//显示数字5
  delay(1000); //延时1s
  digital_6();//显示数字6
  delay(1000); //延时1s
  digital_7();//显示数字7
  delay(1000); //延时1s
  digital_8();//显示数字8
  delay(1000); //延时1s
}


