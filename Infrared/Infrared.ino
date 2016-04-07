#include "InfraredRemote.h"

int ledPin = 8;

void setup()
{
  Serial.begin(9600);
  pinMode(IR_IN, INPUT); //设置红外接收引脚为输入

  pinMode(ledPin, OUTPUT);

  Serial.flush(); //清除串口缓冲器内容函数。
  timer1_init();//定时器初始化
}
void loop()
{
  remote_decode(); //译码
  Deal_Print();
  //remote_deal();

  digitalWrite(ledPin, HIGH);
  delay(100);
  digitalWrite(ledPin, LOW);
}
void Deal_Print()
{
  if ( adrL_code == 0x45 )
  {
    Serial.println("ON/OFF");
  }
  else if ( adrL_code == 0x46)
  {
    Serial.println("CH");
  }
  else if ( adrL_code == 0x47 )
  {
    Serial.println("MENU");
  }
  else if ( adrL_code == 0x44 )
  {
    Serial.println("TEST");
  }
  else if ( adrL_code == 0x40 )
  {
    Serial.println("+");
  }
  else if ( adrL_code == 0x43 )
  {
    Serial.println("Return");
  }
  else if ( adrL_code == 0x07 )
  {
    Serial.println("Left");
  }
  else if ( adrL_code == 0x15)
  {
    Serial.println("Play");
  }
  else if ( adrL_code == 0x09 )
  {
    Serial.println("Right");
  }
  else if ( adrL_code == 0x16)
  {
    Serial.println("0");
  }
  else if ( adrL_code == 0x19)
  {
    Serial.println("-");
  }
  else if ( adrL_code == 0x0d)
  {
    Serial.println("C");
  }
  else if ( adrL_code == 0x0c)
  {
    Serial.println("1");
  }
  else if ( adrL_code == 0x18 )
  {
    Serial.println("2");
  }
  else if ( adrL_code == 0x5e )
  {
    Serial.println("3");
  }
  else if (adrL_code == 0x08 )
  {
    Serial.println("4");
  }
  else if ( adrL_code == 0x1c )
  {
    Serial.println("5");
  }
  else if ( adrL_code == 0x5a )
  {
    Serial.println("6");
  }
  else if ( adrL_code == 0x42)
  {
    Serial.println("7");
  }
  else if ( adrL_code == 0x52)
  {
    Serial.println("8");
  }
  else if ( adrL_code == 0x4a)
  {
    Serial.println("9");
  }

  adrL_code = 0x00;
}

