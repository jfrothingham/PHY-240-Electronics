/*
 * Circuit 1B-Potentiometer
 * Changes how fast an LED blinks, based on a potentiometer input
 */

int potPosition;        //create global variable - can be used in loop

void setup() {
  Serial.begin(9600);   //begin serial communication at 9600 bits/sec
  pinMode(13, OUTPUT);  //set pin 13 as an output
}

void loop() {
  potPosition = 2*analogRead(A0);   //read the signal on pin A0 (range from 0-2046)
  Serial.println(potPosition);    //print the read voltage in the serial monitor

  digitalWrite(13, HIGH);         //output HIGH on pin 13, turning LED on
  delay(potPosition);             //delay by an amount determined by potentiometer position

  digitalWrite(13, LOW);          //output LOW on pin 13, turning LED off
  delay(potPosition);             //delay by an amount determined by potentiometer position
}
