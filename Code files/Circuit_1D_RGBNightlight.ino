/*
 * Circuit 1D-RGB Nightlight
 * Turns an RGB LED on or off based on the light level read by a photoresistor.
 * Change colors by turning the potentiometer.
 */

//variables to store values of photoresistor and potentiometer
int photoresistor = 0;
int potentiometer = 0; 

int threshold = 800;  //controls how dark it needs to be for light to turn on

//pins driving or reading each component
//assigned here as variables for minimal code changes if wiring is changed
int RedPin = 9;
int GreenPin = 10;
int BluePin = 11;
int photoresistorPin = A0;
int potentiometerPin = A2;
void setup() {
  Serial.begin(9600); //begin serial communication

  //set pins to drive LEDs - variables used instead of hardcoded values in case wiring changes
  pinMode(RedPin, OUTPUT);
  pinMode(GreenPin, OUTPUT);
  pinMode(BluePin, OUTPUT);
}

void loop() {
  //read values from sensors - variables used instead of hardcoded values in case wiring changes
  photoresistor = analogRead(photoresistorPin);
  potentiometer = analogRead(photoresistor);

  //print measured values to serial monitor - useful for debugging and setting threshold
  Serial.print("Photoresistor value:");
  Serial.print(photoresistor);
  Serial.print("  Potentiometer value:");
  Serial.print(potentiometer);

  if(photoresistor < threshold){
    // what to do if photoresistor is measuring enough darkness to turn on LED
    //run different methods depending on potentiometer position
    //low end of dial sets LEDs to red, then goes through rainbow order as dial is turned
    if(potentiometer >= 0 && potentiometer <= 150)
      red();
    if (potentiometer > 150 && potentiometer <= 300)
      orange();
    if(potentiometer > 300 && potentiometer <= 450)
      yellow();
    if(potentiometer > 450 && potentiometer <= 600)
      green();
    if(potentiometer > 600 && potentiometer <= 750)
      cyan();
    if(potentiometer > 750 && potentiometer <= 900)
      blue();
    if(potentiometer > 900)
      magenta();
  }
  // what to do if the photoresistor isn't measuring enough darkness to turn on LED
  else {
    turnOff(); // keep the LED off
  }
  delay(500); // wait 500ms to read values and check conditions again
}


// define methods for each LED color state

void red(){
  // set LED to red
  // turns on red leg of LED at max value
  analogWrite(RedPin, 200);
  analogWrite(GreenPin, 0);
  analogWrite(BluePin, 0);
  Serial.println("  red");  //print color to serial monitor - useful for debugging
}

void orange(){
  // set LED to orange
  // turns on red leg of LED at max value and green leg at half value
  analogWrite(RedPin, 200);
  analogWrite(GreenPin, 100);
  analogWrite(BluePin, 0);
  Serial.println("  orange");  //print color to serial monitor - useful for debugging
}

void yellow(){
  // set LED to yellow
  // turns on red leg and green leg of LED at max value
  analogWrite(RedPin, 200);
  analogWrite(GreenPin, 200);
  analogWrite(BluePin, 0);
  Serial.println("  yellow");  //print color to serial monitor - useful for debugging
}

void green(){
  // set LED to green
  // turns on green leg of LED at max value
  analogWrite(RedPin, 0);
  analogWrite(GreenPin, 200);
  analogWrite(BluePin, 0);
  Serial.println("  green");  //print color to serial monitor - useful for debugging
}

void cyan(){
  // set LED to cyan
  // turns on green leg and blue leg of LED at max value
  analogWrite(RedPin, 0);
  analogWrite(GreenPin, 200);
  analogWrite(BluePin, 200);
  Serial.println("  cyan");  //print color to serial monitor - useful for debugging
}

void blue(){
  // set LED to blue
  // turns on blue leg of LED at max value
  analogWrite(RedPin, 0);
  analogWrite(GreenPin, 0);
  analogWrite(BluePin, 200);
  Serial.println("  blue");  //print color to serial monitor - useful for debugging
}

void magenta(){
  // set LED to magenta
  // turns on red leg and blue leg of LED at max value
  analogWrite(RedPin, 200);
  analogWrite(GreenPin, 0);
  analogWrite(BluePin, 200);
  Serial.println("  magenta");  //print color to serial monitor - useful for debugging
}

void turnOff(){
  // turns off LEDs
  // sets all legs to low
  analogWrite(RedPin, 0);
  analogWrite(GreenPin, 0);
  analogWrite(BluePin, 0);
}
