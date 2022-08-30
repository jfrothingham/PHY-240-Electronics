/*
 * Circuit 3B-Distance Sensor
 * Control the color of an RGB LED using an ultrasonic distance sensor
 */

// constant-value integers to store pin connections for sensor and LED legs
const int trigPin = 11;
const int echoPin = 12;
const int redPin = 3;
const int greenPin = 5;
const int bluePin = 6;
// float variable to store distance value
float distance = 0;

void setup() {
  // begin serial communication at 9600 baud
  Serial.begin(9600);
  // set sensor trigger pin as output and sensor echo pin as input
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  // set LED pins as output
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop() {
  // measure distance between sensor and any detected object
  distance = getDistance();
  // print distance in inches
  Serial.print(distance);
  Serial.println(" in");

  // if object detected less than 10 inches away, set LED to red
  if(distance <= 10){
    analogWrite(redPin, 255);
    analogWrite(greenPin, 0);
    analogWrite(bluePin, 0);

  // if object detected 10-20 inches away, set LED to yellow-orange
  } else if(10 < distance && distance < 20){
    analogWrite(redPin, 255);
    analogWrite(greenPin, 50);
    analogWrite(bluePin, 0);

  // if no object detected within 20 inches, set LED to green  
  } else{
    analogWrite(redPin, 0);
    analogWrite(greenPin, 255);
    analogWrite(bluePin, 0);
  }
  delay(50);  // wait 50ms before checking again - gives time to actually run code
}

//------------FUNCTIONS-------------

float getDistance(){
 // variables to store measured time between signal echos and calculated distance values
  float echoTime;
  float calculatedDistance;

  // output a pulse signal on trigger pin
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // measure time between pulses on echo pin
  echoTime = pulseIn(echoPin, HIGH);

  // convert from time to distance in inches
  calculatedDistance = echoTime/148.0;

  return calculatedDistance;
}
