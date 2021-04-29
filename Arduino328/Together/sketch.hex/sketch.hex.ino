//Together

#include "pitches.h"


int melody[] = { NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4 };


int noteDurations[] = { 2, 2, 4, 4, 6, 6, 8, 8 };


void setup() {
  pinMode(4, INPUT_PULLUP);
  pinMode(7, OUTPUT);
}


void making_sound() {
  for (int thisNote = 0; thisNote < 8; thisNote++) {
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(11, melody[thisNote], noteDuration);
    int pauseBetweenNotes = noteDuration;
    delay(pauseBetweenNotes);
    noTone(11);
  }
}
  

void loop() {
  if(digitalRead(4) == LOW) {
    //making_sound();
    digitalWrite(7, HIGH);
    making_sound();
  } else {
    digitalWrite(7, LOW);
  }
}
