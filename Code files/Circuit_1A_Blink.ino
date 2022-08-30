/*
 * Circuit 1A-Blink
 * Turns on LED connected to pin 13 on and off. Repeats forever
 */

void setup() {
  pinMode(13, OUTPUT);  // set pin 13 as an output
}

void loop() {
  digitalWrite(13, HIGH);  // force pin 13 to output HIGH, turning on LED
  delay(2000);             // pause 2000ms
  digitalWrite(13, LOW);  // force pin 13 to output LOW, turning off LED
  delay(2000);           // pause 2000ms

}
