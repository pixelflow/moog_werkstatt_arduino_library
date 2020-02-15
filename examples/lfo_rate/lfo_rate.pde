/*Werkstatt LFO Rate 
  Moog Music Inc. 2014
  Written by Chris David Howe

  Circuit consists of one 10kΩ resistor and a 2.2µf capacitor low pass filter.
*/


#include <werkstatt.h>


lfo lfo(6, A0); //initiate and name the LFO class (LFO output pin, CV input pin)

//list control voltage note names. cv notes: C1, Db , D , Eb , E, F, Gb , G, Ab , A , Bb , B, C2
int cv_notes[] = {C1, Eb , C2};


//LFO rate value corresponding to each index in notes[]. note values: w, h, ht, q, qt, e, et, sx
int rate_values[] = {q, qt, sx};


void setup() {
  }

  
void loop() {
for (int i = 0; i < ( sizeof(cv_notes)/sizeof(int) ); i++)
  {
   //iterate through the indices of each array and run the lfo.rate function 
   lfo.rate(cv_notes[i], rate_values[i]); 
   }
}




