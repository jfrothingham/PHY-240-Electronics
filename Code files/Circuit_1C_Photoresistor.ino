/*
 * Circuit 1C-Photoresistor
 * Use a photoresistor to monitor how bright a room is, and turn on an LED when it gets dark
 */

int photoresistor = 0;    //create variable for photoresistor value

//change this to change how dark room needs to be for LED to turn on
int threshold = 750;      //create variable for room brightness threshold

void setup() {
  Serial.begin(9600);    //serial monitor starts communicating at 9600 baud
  pinMode(13, OUTPUT);   //set pin 13 as an output pin
}

void loop() {
  photoresistor = analogRead(A0);   //read value from photoresistor
  Serial.println(photoresistor);    //print read photoresistor value

// if the room is dark, turn on the LED. otherwise, keep it off
// wait 100ms before checking again
  if (photoresistor < threshold){
    digitalWrite(13, HIGH);
  } else {
    digitalWrite(13, LOW);
  }
  delay(100);
}
