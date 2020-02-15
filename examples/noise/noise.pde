/*Werkstatt Noise Generator 
  Moog Music Inc. 2014
  Written by Chris David Howe

  Circuit consists of two 10k½ potentiometers.
*/


#include <werkstatt.h>

int value;
int color;

noise noise(1); //initiate and name noise class set to output on digital pin 1
interface interface(A0); //initiate and name the interface class set to input on analog pin 0


void setup() {
}

void loop(){
   color = interface.potentiometer(1,500);//run potentiometer function and set minimum and maximum output
   noise.generate(color); //run noise generator and define noise color
}