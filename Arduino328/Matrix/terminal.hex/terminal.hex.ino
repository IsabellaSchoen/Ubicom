// Including the required Arduino libraries
#include <MD_Parola.h>
#include <MD_MAX72xx.h>
#include <SPI.h>

// Uncomment according to your hardware type
//#define HARDWARE_TYPE MD_MAX72XX::FC16_HW
#define HARDWARE_TYPE MD_MAX72XX::GENERIC_HW

// Defining size, and output pins
#define MAX_DEVICES 1
#define CS_PIN 10

// Create a new instance of the MD_Parola class with hardware SPI connection
MD_Parola myDisplay = MD_Parola(HARDWARE_TYPE, CS_PIN, MAX_DEVICES);

void setup() {
  // Intialize the object
  myDisplay.begin();

  // Set the intensity (brightness) of the display (0-15)
  myDisplay.setIntensity(15);

  // Clear the display
  myDisplay.displayClear();
}

void text() {
  //myDisplay.setTextAlignment(PA_CENTER);
  //myDisplay.print(String("Hello world!"));
  if(myDisplay.displayAnimate())
    myDisplay.displayText("Hello world!", PA_CENTER, myDisplay.getSpeed(), myDisplay.getPause(), PA_SCROLL_DOWN, PA_SCROLL_UP);
}

void loop() {
  text();
}
