//Buzzer

#include "pitches.h"
#include "arduino-timer.h"

//timer created
auto timer = timer_create_default();


// notes in the melody
int melody[] = { NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4 };


// note durations
int noteDurations[] = { 2, 2, 2, 2, 4, 4, 4, 4 };


void repeat_sound(void *) {
  for (int thisNote = 0; thisNote < 8; thisNote++) {

      int noteDuration = 1000 / noteDurations[thisNote];
      //tone(8, melody[thisNote], noteDuration); //with Button
      tone(9, melody[thisNote], noteDuration); //with Timer

      int pauseBetweenNotes = noteDuration;
      delay(pauseBetweenNotes);
      //noTone(8); //with Button
      noTone(9); //with Timer
  }
  return true; 
}



void setup() {
  pinMode(9, OUTPUT);
  timer.every(3000, repeat_sound); //repeat timer
}



void loop() {
  timer.tick(); // to make the timer tick
}
