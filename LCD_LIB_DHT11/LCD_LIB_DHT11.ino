#include <LiquidCrystal.h>
#include <dht11.h>

#define DHT11PIN 8

/*
 *    接线：
 *         将 LCD 的 RS, E, D4, D5, D6, D7 依序接到 12, 11, 5, 4, 3, 2 引脚上
 *         将 LCD 的 GND 及 RW 接到 GND，Vdd 接到 +5V
 *         电阻1K引脚接到 LCD 的 Vo，剩下引脚，一支接到GND
 *         DHT11接数字口8.
 *
 */

dht11 DHT11;
// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  pinMode(DHT11PIN, OUTPUT);
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
}

void loop() {
  int chk = DHT11.read(DHT11PIN);
  lcd.setCursor(0, 0);
  lcd.print("Tep: ");
  lcd.print((float)DHT11.temperature, 2);
  lcd.print("C");
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 1);
  // print the number of seconds since reset:
  lcd.print("Hum: ");
  lcd.print((float)DHT11.humidity, 2);
  lcd.print("%");
  delay(500);
}
