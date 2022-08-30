/*
 * PHY 240 Spring 2021 Final Project -- Constellation Projection Lamp
 * 
 * This code allows users to change the projection color based on buttons.
 * It also ties rotation of the lamp's internal lighting mechanism to a potentiometer,
 * allowing users to "spotlight" different zodiac constellations.
 * 
 * Julia Frothingham
 */

// import libraries to control LED array and servo
#include <Adafruit_NeoPixel.h>
#include <Servo.h>

// assign pins and other constants
int LED_PIN = 6;
int LED_COUNT = 64;

int SERVO_PIN = 10;
int POT_PIN = A0;

int RED_PIN = 2;
int GREEN_PIN = 3;
int BLUE_PIN = 4;
int WHITE_PIN = 5;

// create LED array board object
Adafruit_NeoPixel board(LED_COUNT, LED_PIN, NEO_GRB);

// create servo object
Servo rot;

// variables to store pot position, servo position, color setting
int potPos;
int servoPos=0;
int setting = 0;

// custom color definitions
// these colors are too strong
//uint32_t red = board.Color(255, 0, 0);
//uint32_t green = board.Color(0, 255, 0);
//uint32_t blue = board.Color(0, 0, 255);

// these colors are toned down a bit
uint32_t magenta = board.Color(255, 0, 100);
uint32_t teal = board.Color(0, 100, 255);
uint32_t forest = board.Color(100, 255, 10); 
uint32_t white = board.Color(255, 255, 255);

void setup() {
  // setup required for LED array
  Serial.begin(9600);
  board.begin();
  board.show();
  
  // setup required for servo
  rot.attach(SERVO_PIN);

  // use pins connected to buttons as inputs w/ arduino pullup resistor
  pinMode(RED_PIN, INPUT_PULLUP);
  pinMode(GREEN_PIN, INPUT_PULLUP);
  pinMode(BLUE_PIN, INPUT_PULLUP);
  pinMode(WHITE_PIN, INPUT_PULLUP);
}

void loop() {
  // read the position of the potentiometer
  potPos = analogRead(POT_PIN);
  
  // map the read potentiometer position from a range of 0-1023 to a range of 80-100
  // for a continuous-rotations servo, ~90 is a speed of 0
  // store the converted value in servoSpeed
  servoSpeed = map(potPos, 0, 1023, 80, 100);
  
  // change the speed and/or direction at which the servo rotates
  rot.write(servoSpeed);
  Serial.println(potPos); // for debugging

  // determine if a button has been pressed to change LED colors
  setting = checkButtons(WHITE_PIN, RED_PIN, GREEN_PIN, BLUE_PIN);

  // set the LED colors
  if(setting == 0){board.fill(white, 0, LED_COUNT-1);}  // white light
  if(setting == 1){board.fill(magenta, 0, LED_COUNT-1);}  // red light
  if(setting == 2){board.fill(forest, 0, LED_COUNT-1);}  // green light
  if(setting == 3){board.fill(teal, 0, LED_COUNT-1);}  // blue light
  
  // apply LED color change
  board.show();
}


// custom function to indicate which button is pressed
int checkButtons(int pin1, int pin2, int pin3, int pin4){
  if(digitalRead(pin1)==LOW){return 0;}
  if(digitalRead(pin2)==LOW){return 1;}
  if(digitalRead(pin3)==LOW){return 2;}
  if(digitalRead(pin4)==LOW){return 3;}
}
