#include <LedControl.h>

#include <MD_MAX72xx.h>
#include <SPI.h>

#define CLK_PIN   13  // or SCK
#define DATA_PIN  11  // or MOSI
#define CS_PIN    10  // or SS

const int numDevices = 2;      // number of MAX7219s

LedControl lc = LedControl(11, 13, 10, numDevices); //DATA | CLK | CS/LOAD | number of matrices



void setup()
{
  lc.shutdown(0,false);       //The MAX72XX is in power-saving mode on startup
  lc.shutdown(1,false);       //The MAX72XX is in power-saving mode on startup
  lc.setIntensity(0,8);       // Set the brightness to default value
  lc.setIntensity(1,8);       // Set the brightness to default value
  lc.clearDisplay(0);         // and clear the display
  lc.clearDisplay(1);         // and clear the display
}



void emojisOnMatrix() {

  byte happy[16]=   {0x3C,0x42,0xA5,0x81,0xA5,0x99,0x42,0x3C,0x00,0x66,0x99,0x81,0x81,0x42,0x24,0x18};
    byte neutral[16]= {0x3C,0x42,0xA5,0x81,0xBD,0x81,0x42,0x3C,0x00,0x00,0x66,0x5A,0x42,0x24,0x18,0x00};
    byte sad[16]=     {0x3C,0x42,0xA5,0x81,0x99,0xA5,0x42,0x3C,0x00,0x00,0x24,0x3C,0x24,0x18,0x00,0x00};
  
  display(happy);
  delay(500);
  display(neutral);
  delay(500);
  display(sad);
  delay(500);
}

void display(byte character[]) {
  for(int i=0; i<16; i++)
  {
    lc.setRow(1,i,character[i]);
    lc.setRow(0,i,character[i+8]);
  }
}


void loop() {
  emojisOnMatrix();
}
