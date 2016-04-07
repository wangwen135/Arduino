//8位接法
//接口说明：
//1、两组电源 一组是模块的电源 一组是背光板的电源 一般均使用5V供电。本次试验背光使用3.3V供电也可以工作。
//2、VL是调节对比度的引脚，串联不大于5KΩ的电位器进行调节。本次实验使用1KΩ的电阻来设定对比度。其连接分高电位与低电位接法，本次使用低电位接法，串联1KΩ电阻后接GND。
//注意：不同液晶的对比度电阻是不同的，最好是接一个电位器进行测试，本次实验使用的1KΩ电阻在其他液晶上不一定正确。
//3、RS 是很多液晶上都有的引脚 是命令/数据选择引脚 该脚电平为高时表示将进行数据操作；为低时表示进行命令操作。
//4、RW 也是很多液晶上都有的引脚 是读写选择端 该脚电平为高是表示要对液晶进行读操作；为低时表示要进行写操作。
//5、E 同样很多液晶模块有此引脚 通常在总线上信号稳定后给一正脉冲通知把数据读走，在此脚为高电平的时候总线不允许变化。
//6、D0—D7 8 位双向并行总线，用来传送命令和数据。
//7、BLA是背光源正极，BLK是背光源负极。

//尼玛 这个是RS
int DI = 12;
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
  LcdCommandWrite(0x80 + 3);
  delay(10);
  // 写入欢迎信息
  LcdDataWrite('S');
  LcdDataWrite('B');
  LcdDataWrite(' ');
  LcdDataWrite('n');
  LcdDataWrite('i');
  LcdDataWrite('u');
  LcdDataWrite(' ');
  LcdDataWrite('n');
  LcdDataWrite('i');
  LcdDataWrite('u');

  delay(10);
  LcdCommandWrite(0xc0 + 1); // 定义光标位置为第二行第二个位置
  delay(10);
  LcdDataWrite('z');
  LcdDataWrite('h');
  LcdDataWrite('e');
  LcdDataWrite(' ');
  LcdDataWrite('s');
  LcdDataWrite('h');
  LcdDataWrite('i');
  LcdDataWrite(' ');
  LcdDataWrite('c');
  LcdDataWrite('e');
  LcdDataWrite(' ');
  LcdDataWrite('s');
  LcdDataWrite('h');
  LcdDataWrite('i');
  LcdDataWrite(' ');

  delay(5000);
  LcdCommandWrite(0x01); // 屏幕清空，光标位置归零
  delay(10);
  LcdDataWrite('1');
  LcdDataWrite('2');
  LcdDataWrite('3');
  LcdDataWrite('4');
  LcdDataWrite('5');
  LcdDataWrite('6');
  LcdDataWrite('7');
  LcdDataWrite('8');
  LcdDataWrite('9');
  LcdDataWrite('0');
  LcdDataWrite('(');
  LcdDataWrite('!');
  LcdDataWrite('#');
  LcdDataWrite('%');
  LcdDataWrite('&');
  LcdDataWrite(')');

  delay(1000);
  LcdCommandWrite(0xc0); // 定义光标位置为第二行第二个位置
  delay(10);
  //显示一下温度看
  LcdDataWrite('h');
  LcdDataWrite('e');
  LcdDataWrite(' ');
  LcdDataWrite('h');
  LcdDataWrite('e');
  LcdDataWrite(' ');
  LcdDataWrite('<');
  LcdDataWrite('-');
  LcdDataWrite('_');
  LcdDataWrite('-');
  LcdDataWrite('>');

  delay(3000);
}


