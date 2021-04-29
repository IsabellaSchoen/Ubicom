#include <DallasTemperature.h>
#include <OneWire.h>
#include <LedControl.h>

#define CLK_PIN   13
#define DATA_PIN  11
#define CS_PIN    10

#define MAX_DEVICES 2

// in which PIN the temperature is plugged
#define SENSOR_PIN 8

//DATA | CLK | CS/LOAD | number of matrices
LedControl lc = LedControl(11, 13, 10, MAX_DEVICES);

// setup a oneWire instance to communicate with any OneWire 
//devices (not just Maxim/Dallas temperature ICs)
OneWire oneWire(SENSOR_PIN); 

// pass oneWire to DallasTemperature library        
DallasTemperature sensors(&oneWire); 




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
 },//8
 {B01111110,
  B01000010,
  B01000010,
  B01111110,
  B01111110,
  B01000010,
  B01000010,
  B01111110
 },//9
 {B01111110,
  B01000010,
  B01000010,
  B01111110,
  B00000010,
  B00000010,
  B00000010,
  B01111110}
};



void setup() {
  // initialize the sensor
  sensors.begin();
  lc.shutdown(0,false);
  lc.shutdown(1,false);
  lc.setIntensity(0,15);
  lc.setIntensity(1,15);
  lc.clearDisplay(0);
  lc.clearDisplay(1);
}

void loop() {
  sensors.requestTemperatures();

  // get the temperature from the first sensor only
  float tempCelsius = sensors.getTempCByIndex(0);

  int temp = (int) tempCelsius;

  delay(100);

  while (temp != -127) {
    sensors.requestTemperatures();
    tempCelsius = sensors.getTempCByIndex(0);

    int last = temp % 10; //für die letzte Zahl 
    for(int r=0; r<8; r++) {
      lc.setRow(0,r,numbers[last][r]);
    }

    int first = temp/10 % 10; //für die erste
    for(int r=0; r<8; r++) {
      lc.setRow(1,r,numbers[first][r]);
    }
  }
}
