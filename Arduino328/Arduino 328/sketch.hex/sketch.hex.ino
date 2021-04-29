//LED Licht

int brightness = 0;
int fading = 5;

void setup() {
  // put your setup code here, to run once:
  pinMode(4, INPUT_PULLUP); //Ein- und Ausschalter
  //pinMode(3, OUTPUT); //Stromzufuhr - fading
  pinMode(7, OUTPUT); //Stromzufuhr - blinking
}

void loop() {
  // for LED - blinking
  if(digitalRead(4) == LOW) {
    digitalWrite(7, HIGH);
    //delay(10); // timer
    //digitalWrite(7, LOW); // timer
    //delay(10); //timer
  } else {
    digitalWrite(7, LOW);
  }
  
  //for LED - fading
  /*if(digitalRead(4) == LOW) {
    if(brightness < 255) {
      brightness = brightness + fading;
    }
  } else {
    if (brightness > 0) {
      brightness = brightness - fading;
    }
  }
  analogWrite(3, brightness);
  delay(30);*/
}
