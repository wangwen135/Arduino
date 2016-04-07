#include <dht11.h>
dht11 DHT11;
#define DHT11PIN 13

int RW = 11;

int Enable = 2;

//这里是D0 - D7
int DB[] = {3, 4, 5, 6, 7, 8, 9, 10};//使用数组来定义总线需要的管脚

void LcdCommandWrite(int value) {
  // 定义所有引脚
  int i = 0;
  for (i = DB[0]; i <= DI; i++) //总线赋值
  {
    digitalWrite(i, value & 01); //因为1602液晶信号识别是D7-D0(不是D0-D7)，这里是用来反转信号。
    value >>= 1;
  }

  //输出一个高脉冲
  digitalWrite(Enable, LOW);
  delayMicroseconds(1);
  digitalWrite(Enable, HIGH);
  delayMicroseconds(1);
  digitalWrite(Enable, LOW);
  delayMicroseconds(1);
}

void LcdDataWrite(int value) {
  // 定义所有引脚
  int i = 0;
  digitalWrite(DI, HIGH);
  digitalWrite(RW, LOW);
  for (i = DB[0]; i <= DB[7]; i++) {
    digitalWrite(i, value & 01);
    value >>= 1;
  }

  //输出一个高脉冲
  digitalWrite(Enable, LOW);
  delayMicroseconds(1);
  digitalWrite(Enable, HIGH);
  delayMicroseconds(1);
  digitalWrite(Enable, LOW);
  delayMicroseconds(1);
}

void setup (void) {
  int i = 0;
  for (i = Enable; i <= DI; i++) {
    pinMode(i, OUTPUT);
  }
  delay(100);
  // 短暂的停顿后初始化LCD
  // 用于LCD控制需要

  //##功能设置，采用8位方式的数据传输

  LcdCommandWrite(0x38); // 设置为8-bit接口，2行显示，5x7文字大小
  delay(64);
  //  LcdCommandWrite(0x38);
  //  delay(50);
  //  LcdCommandWrite(0x38);
  //  delay(20);


  //##设置输入模式，显示的字符不动，光标右移，AC+1
  LcdCommandWrite(0x06); // 输入方式设定
  // 自动增量，没有显示移位
  delay(20);
  LcdCommandWrite(0x0E); // 显示设置
  // 开启显示屏，光标显示，无闪烁
  delay(20);
  LcdCommandWrite(0x01); // 屏幕清空，光标位置归零
  //delay(100);
  //LcdCommandWrite(0x80); // 显示设置

  delay(20);

}
void loop (void) {
  LcdCommandWrite(0x01); // 屏幕清空，光标位置归零
  delay(10);
  LcdCommandWrite(0x80);
  delay(10);
  int chk = DHT11.read(DHT11PIN);

  // 温度
  LcdDataWrite('T');
  LcdDataWrite(':');

  if (chk == DHTLIB_OK) {
    int tp = DHT11.temperature;

    LcdDataWrite(tp / 10 + 0x30);
    LcdDataWrite(tp % 10 + 0x30);
    LcdDataWrite('C');
  }

  delay(10);
  LcdCommandWrite(0xc0 ); // 定义光标位置为第二行第二个位置
  delay(10);
  LcdDataWrite('H');
  LcdDataWrite(':');

  if (chk == DHTLIB_OK) {
    int hm = DHT11.humidity;

    LcdDataWrite(hm / 10 + 0x30);
    LcdDataWrite(hm % 10 + 0x30);
    LcdDataWrite('%');
  }
  LcdDataWrite(' ');

  delay(1000);
}


