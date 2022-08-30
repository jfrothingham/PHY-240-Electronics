/*
 * Circuit 2B-ButtonTrumpet
 * Use 3 buttons to play musical notes on a buzzer
 */

// the arduino pins each component is connected to
int firstKeyPin = 2;
int secondKeyPin = 3;
int thirdKeyPin = 4;
int buzzerPin = 10;

// variable to store state
int inputSum = 0;

// array of frequencies for each pitch
int freq[] = {0, 262, 294, 330, 349, 392, 440, 494};

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
  //determine the combination of buttons pressed
  inputSum = readInputs(firstKeyPin, secondKeyPin, thirdKeyPin);
  
  if(inputSum > 0){
    // if any buttons are pressed, play tone 
    // frequency depends on combination of buttons pressed
    tone(buzzerPin, freq[inputSum]);

    // reset state variable
    inputSum = 0;
  } else {
    // if no buttons are pressed, don't play a tone
    noTone(buzzerPin);
  }
}

//define custom function to read button combination and determine state
int readInputs(int one, int two, int three){
  int sum = 0;
  if(digitalRead(one)==LOW){sum+=1;} // equivalent to 001 in binary
  if(digitalRead(two)==LOW){sum+=2;} // equivalent to 010 in binary
  if(digitalRead(three)==LOW){sum+=4;} // equivalent to 100 in binary

  return sum;
}
