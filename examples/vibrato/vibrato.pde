/* Photoresistor Vibrato
This sketch controls an LED fade rate which in turn
controls the VCO EXP IN for a vibrato effect
Written by Chris David Howe
Moog Music Inc. 2014 */

//import required libraries
#include <werkstatt.h>

int LED = 6;//LED PWM pin
interface button(2);//call and name our interface class to read a button on digital pin 2
vibrato vibrato (LED, A0);//call the vibrato class and pass the LED PWN pin info as well as our 
//rate control potentiometer analog pin designation

int low = 0; //floor of brightness for our LED
int center = 127; //constant brightness
int high = 255;//most bright
 
void setup() {
}      

void loop(){  

  int pushbutton = button.momentary(0,1);//read the button and name it 
  
  if (pushbutton == 1) //if the button is pressed turn on vibrato
  {
       vibrato.rate(1,15, low, high); // vibrato.rate(minimum fade delay, maximum fade delay, lowest brightness factor, highest brightness factor)
  }
    else
    {
          analogWrite(LED, center); //if the button is not pressed keep the LED on at the center brightness factor 
    }      
}




 
