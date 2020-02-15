/*Werkstatt Arpeggiator 
  Moog Music Inc. 2014
  Written by Chris David Howe

  Circuit consists of one 10kΩ resistor and a 2.2µf capacitor low pass filter.
*/

#include <werkstatt.h>

arpeggiator arpeggiator(6); //initiate and name the arpeggiator class (Output pin)

/* 
notes are assigned in intervals: tonic, minor2nd, major2nd, minor3rd,
major3rd, fourth, tritone, fifth, minor6th, major6th, minor7th,
major7th, octave. 
*/
  int notes[] = {tonic, octave}; // VCO EXP config


// note values: w, h, q, qt, e, et, sx, sxt, th, sxf 
  int note_values[] = {e, e}; //VCO EXP config

  
void setup() {
}      


void loop() {
for (int i = 0; i < ( sizeof(notes)/sizeof(int) ); i++)
  {
   //define a BPM and run the arpeggiator.play function  
   arpeggiator.play(140, notes[i], note_values[i]); 
   }
}
 




