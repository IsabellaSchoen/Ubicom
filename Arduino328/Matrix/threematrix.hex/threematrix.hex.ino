#include <LedControl.h>

#define CLK_PIN   13  // or SCK
#define DATA_PIN  11  // or MOSI
#define CS_PIN    10  // or SS

const int numDevices = 3;      // number of MAX7219s

LedControl lc = LedControl(11, 13, 10, numDevices); //DATA | CLK | CS/LOAD | number of matrices



const byte numbers[10][8] = {
 {//0
  B00111100,
  B01000010,
  B01000010,
  B01000010,
  B01000010,
  B01000010,
  B01000010,
  B00111100
 },
 {//1
  B00011100,
  B00111100,
  B01101100,
  B11001100,
  B00001100,
  B00001100,
  B00001100,
  B00001100
 },
 {//2
  B00111110,
  B01111110,
  B11000110,
  B10000110,
  B00001100,
  B00011000,
  B00111111,
  B01111111
 },
 {//3
  B01111110,
  B11000110,
  B10000110,
  B00011000,
  B00011000,
  B10000110,
  B11000110,
  B01111110
 },
 {//4
  B00011000,
  B00110000,
  B01100000,
  B11001100,
  B11111111,
  B11111111,
  B00001100,
  B00001100
 },
 {//5
  B01111110,
  B01000000,
  B01000000,
  B01000000,
  B01111110,
  B00000010,
  B00000010,
  B01111110
 },
 {//6
  B00011110,
  B00100000,
  B01000000,
  B01000000,
  B01111100,
  B01000010,
  B01000010,
  B00111100
 },
 {//7
  B11111111,
  B11111111,
  B00000110,
  B00001100,
  B01111110,
  B00110000,
  B01100000,
  B11000000
 },
 {B01111110,
  B01000010,
  B01000010,
  B01111110,
  B01111110,
  B01000010,
  B01000010,
  B01111110},
 {B01111110,
  B01000010,
  B01000010,
  B01111110,
  B00000010,
  B00000010,
  B00000010,
  B01111110}
};




void setup()
{
  //Serial.begin(9600);
  //pinMode(11, OUTPUT);
  //pinMode(10, OUTPUT);
  //pinMode(13, OUTPUT);
  lc.shutdown(0,false);
  lc.shutdown(1,false);
  lc.shutdown(2,false);
  lc.setIntensity(0,15);
  lc.setIntensity(1,15);
  lc.setIntensity(2,15);
  lc.clearDisplay(0);
  lc.clearDisplay(1);
  lc.clearDisplay(2);
}



int min = 0; //nur Zahlen von  0 bis...
int max = 128; //...128

void loop() {
  int n = 0;
  
  for(int i=min; i<=max; i++)
  {
    n = i % 10; //für die letzte Zahl 
    for(int r=0; r<8; r++) {
      lc.setRow(0,r,numbers[n][r]);
    }

    n = i/10 % 10; //für die mittlere Zahl 
    for(int r=0; r<8; r++) {
      lc.setRow(1,r,numbers[n][r]);
    }

    n = i/100 % 10; //für die vordere Zahl 
    for(int r=0; r<8; r++) {
      lc.setRow(2,r,numbers[n][r]);
    }
    delay(100);
  }
}
