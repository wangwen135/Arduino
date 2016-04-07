const byte COL_COUNT = 8;
//array to hold the data
unsigned char sequence[COL_COUNT] = {B00000001, B00000010, B00000100, B00001000, B00010000, B00100000, B01000000, B10000000};
//unsigned char sequence[COL_COUNT] = {1, 2, 4, 8, 16, 32, 64, 128};
//unsigned char sequence[COL_COUNT] = {0x01, 0x02, 0x04, 0x8, 0x10, 0x20, 0x40, 0x80};
//Define which pins will be used for the shift register control
//can be any digital pin on the Arduino

int latchPin = 13;  //Pin connected to ST_CP(pin 12) of 74HC595
int clockPin = 12; //Pin connected to SH_CP(pin 11) of 74HC595
int dataPin = 11;  //Pin connected to DS(pin 14) of 74HC595

void setup() {
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
}
void loop()
{
  for (int col = 0; col < COL_COUNT; col++)
  {
    digitalWrite(latchPin, LOW); //Pull latch LOW to send data
    shiftOut(dataPin, clockPin, MSBFIRST, sequence[col]); //Send the data
    digitalWrite(latchPin, HIGH); // Pull latch HIGH to stop sending data
    delay(200);
  }
}
