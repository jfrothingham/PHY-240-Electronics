/*
 * Circuit 2B-ButtonTrumpet
 * Use 3 buttons to play musical notes on a buzzer
 */

// the arduino pins each component is connected to
int firstKeyPin = 2;
int secondKeyPin = 3;
int thirdKeyPin = 4;
int buzzerPin = 10;

void setup() {
  // set the connected to the buttons as input pins
  // that use the internal arduino pullup resistors to force output between 0V and Vmax
  pinMode(firstKeyPin, INPUT_PULLUP);
  pinMode(secondKeyPin, INPUT_PULLUP);
  pinMode(thirdKeyPin, INPUT_PULLUP);
  // set the pin connected to the buzzer as output pin
  // so that the arduino will drive the buzzer
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  // if the first button is pressed, buzzer will play note at 262Hz
  if(digitalRead(firstKeyPin)==LOW){
    tone(buzzerPin, 262);
  }
  // if the second button is pressed, buzzer will play note at 330Hz
  else if(digitalRead(secondKeyPin)==LOW){
    tone(buzzerPin, 330);
  }
  // if the third button is pressed, buzzer will play note at 392Hz
  else if(digitalRead(thirdKeyPin)==LOW){
    tone(buzzerPin, 392);
  }
  // if no buttons pressed, buzzer will not play anything
  else{
    noTone(buzzerPin);
  }
}
