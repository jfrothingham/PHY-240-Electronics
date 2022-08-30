/*
 * Circuit 3A-Servo
 * Move a servo attached to pin 9 so that its angle matches a potentiometer attached to A0.
 */

#include <Servo.h>   //import servo control library
Servo myservo;      //create a servo object called myservo

// variables to store potentiometer and servo postions
int potPosition;
int servoPosition;

// assign pin connections to variables - minimal code changes if wiring changed
int motorPin = 9;
int potPin = A0;

void setup() {
  // specify that servo myservo is connected to motorPin
  myservo.attach(motorPin);
}

void loop() {
  // read the position of the potentiometer
  potPosition = analogRead(potPin);

  // map the read potentiometer position from a range of 0-1023 to a range of 20-160
  // store the converted value in servoPosition
  servoPosition = map(potPosition, 0, 1023, 20, 160);

  // move the servo to the specified position in degrees
  myservo.write(servoPosition);
}
