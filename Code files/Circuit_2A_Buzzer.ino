/*
 * CIrcuit 2A-Buzzer
 * Play notes using a buzzer (i.e., a very cheap speaker
 */

int speakerPin = 10;    // buzzer connects to pin 10

void setup() {
  pinMode(speakerPin, OUTPUT);    // the arduino will output a signal to drive the speaker
}

void loop() {
  // play specific notes for specific beats
  play('g', 2);
  play('g', 1);
  play('a', 4);
  play('g', 4);
  play('C', 4);
  play('b', 4);
  play(' ', 2);   //a pause before playing next set of notes

  play('g', 2);
  play('g', 1);
  play('a', 4);
  play('g', 4);
  play('D', 4);
  play('C', 4);
  play(' ', 2);

  play('g', 2);
  play('g', 1);
  play('G', 4);
  play('E', 4);
  play('C', 4);
  play('b', 4);
  play('a', 6);
  play(' ', 2);

  play('F', 2);
  play('F', 1);
  play('E', 4);
  play('C', 4);
  play('D', 4);
  play('C', 6);

  while(true){}   // this line prevents the song from being played again by essentially
                  // "traps" the code in an always-true condition that makes it do nothing
}

void play(char note, int beats) {
  // number of available notes
  int numNotes = 14;
  // available notes (C major scale in two octaves)
  char notes[] = {'c', 'd', 'e', 'f', 'g', 'a', 'b', 'C', 'D', 'E', 'F', 'G', 'A', 'B', ' '};
  // frequencies associated with each note, in same order as notes are named in array notes[]
  int frequencies[] = {131, 147, 165, 175, 196, 220, 247, 262, 294, 330, 349, 392, 440, 494, 0};
  // variable to store the frequency of the note to play
  int currentFrequency = 0;
  // one beat = 150 milliseconds
  int beatLength = 150;

  // iterate through the list of notes until you hit the note passed as function's input parameter
  // use the array index of that note to find the associated frequency
  for(int i=0; i<numNotes; i++){
    if(notes[i]==note){
      currentFrequency = frequencies[i];
    }
  }

  // output a soundwave at given frequency through given pin for a given amount of time
  tone(speakerPin, currentFrequency, beats*beatLength);
  delay(beats*beatLength);  // wait for note to finish playing
  delay(50);  // wait 50ms before continuing code

}
