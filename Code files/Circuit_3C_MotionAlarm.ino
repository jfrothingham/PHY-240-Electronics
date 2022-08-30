/*
 * Circuit 3C-Motion Alarm
 * Control the color of an RGB LED using an ultrasonic distance sensor.
 * When an object is close to the sensor, buzz the buzzer and wiggle the servo motor.
 */

#include <Servo.h>  //import servo control library

// assign pin connections to variables - minimal code changes if wiring changed
const int trigPin = 11;
const int echoPin = 12;
const int redPin = 3;
const int greenPin = 5;
const int bluePin = 6;
const int buzzerPin = 10;
float distance = 0;

Servo myservo;  //create a servo object called myservo

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);

  myservo.attach(9);   // specify that servo myservo is connected to motorPin
}

void loop() {
  // measure distance between sensor and any detected object
  distance = getDistance();
  // print distance in inches
  Serial.print(distance);
  Serial.println(" in");

  // if object detected less than 10 inches away
  // set LED to red, move servo back and forth, and play a repeated tone
   if(distance <= 10){
    analogWrite(redPin, 255);
    analogWrite(greenPin, 0);
    analogWrite(bluePin, 0);
    
    //play a tone and move the servo to 10 degrees
    tone(buzzerPin, 272);
    myservo.write(10);
    delay(100);   // pause for 100ms
    //stop the tone and move the servo to 150 degrees
    noTone(buzzerPin);
    myservo.write(150);
    delay(100);   // pause for 100ms

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
  delay(50); // wait 50ms before checking again - gives time to actually run code
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
