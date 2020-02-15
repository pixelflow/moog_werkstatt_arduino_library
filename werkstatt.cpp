/*
 werkstatt.cpp -   
 Library for the Moog Werkstatt-01
 Moog Music Inc. 2014
 Written by Chris David Howe
 */

#include "Arduino.h"
#include "werkstatt.h"
#include <stdint.h>
#include <avr/interrupt.h>
#include <avr/io.h>
#include <avr/pgmspace.h>


/* INTERFACE */

interface::interface(int interface_pin)
{
	pinMode(interface_pin, INPUT);
	_pin = interface_pin;
	
	int buttonCounter = 0;   // counter for the number of button presses
	int lastbuttonState = 0;     // previous state of the button
	
}

int interface::momentary(int min, int max)
{
	int momentaryState = digitalRead(_pin);
	int output = map(momentaryState, 0, 1, min, max);//map  values
	return output;
}

int interface::toggle(int max)
{
	int buttonState = digitalRead(_pin);
	
	// compare the buttonState to its previous state
	if (buttonState != lastbuttonState) {
		// if the state has changed, increment the counter
		if (buttonState == HIGH) {			
			buttonCounter++;
			}
			//reset buttonCounter to set maximum
			if (buttonCounter == max)
			{
				buttonCounter = 0 ;
			} 
		
	}
	// save the current state as the last state, 
	//for next time through the loop
	lastbuttonState = buttonState;
	return buttonCounter;

}

	

int interface::potentiometer(int min, int max){

	int value = analogRead(_pin);//read the potentiometer value
	int output = map(value, 0, 1023, min, max);//map  values
	return output;
	
	
};
	
/* ACCELEROMETER */

accelerometer::accelerometer(int x_pin, int y_pin, int z_pin)
{
	pinMode(x_pin, INPUT);
	pinMode(y_pin, INPUT);
	pinMode(z_pin, INPUT);
	
	int x_pulse_state = LOW;
	int y_pulse_state = LOW;
	int z_pulse_state = LOW;

	
}

void accelerometer::x_axis(int x_out, int min, int max)
{
	int x_data = analogRead(x_pin);
	
	analogWrite(x_out, map(x_data, 0, 1023, min, max));

}
				
void accelerometer::y_axis(int y_out, int min, int max)
{
	int y_data = analogRead(y_pin);
	analogWrite(y_out, map(y_data, 0, 1023, min, max));
}

void accelerometer::z_axis(int z_out, int min, int max)
{
	int z_data = analogRead(z_pin);
	analogWrite(z_out, map(z_data, 0, 1023, min, max));
};



void accelerometer::x_pulse(int x_out, int min, int max)
{ 
	
	
	int x_interval = map ( analogRead(x_pin), 0, 1023, min, max);
	
	unsigned long x_currentMillis = millis();
	
	if(x_currentMillis - x_previousMillis > x_interval) {

		x_previousMillis = x_currentMillis;   
		
		if (x_pulse_state == LOW)
			x_pulse_state = HIGH;
		else
			x_pulse_state = LOW;
		
		digitalWrite(x_out, x_pulse_state);
	}
}


void accelerometer::y_pulse(int y_out, int min, int max)
{ 
	
	
	int y_interval = map ( analogRead(y_pin), 0, 1023, min, max);
	
	unsigned long y_currentMillis = millis();
	
	if(y_currentMillis - y_previousMillis > y_interval) {
		
		y_previousMillis = y_currentMillis;   
		
		if (y_pulse_state == LOW)
			y_pulse_state = HIGH;
		else
			y_pulse_state = LOW;
		
		digitalWrite(y_out, y_pulse_state);
	}
}



void accelerometer::z_pulse(int z_out, int min, int max)
{ 
	
	
	int z_interval = map ( analogRead(z_pin), 0, 1023, min, max);
	
	unsigned long z_currentMillis = millis();
	
	if(z_currentMillis - z_previousMillis > z_interval) {
		
		z_previousMillis = z_currentMillis;   
		
		if (z_pulse_state == LOW)
			z_pulse_state = HIGH;
		else
			z_pulse_state = LOW;
		
		digitalWrite(z_out, z_pulse_state);
	}
}

/* GATE IN ENVELOPE GENERATOR */

eg::eg(int gate_pin, int eg_pin)
{
	pinMode(gate_pin, INPUT);
	pinMode(eg_pin, OUTPUT);
	
}

void eg::trigger(int attack, int decay)
{
	
	int gate = digitalRead(gate_pin);
	
	if (gate == HIGH) //if the button is pressed turn on vibrato
	{
		
		// fade in from 0 to 255 in steps of 5 points:
		for(int egValue = 0 ; egValue <= 255; egValue +=5) { 
			
			// sets the value (range from 0 to 255):
			analogWrite(eg_pin, egValue);         
			
			// wait for time in milliseconds to see the dimming effect    
			delay(attack);                            
		} 
		
	}
    else
    {
		if (egValue > 0)
			
			// fade out from 0 to 255 in steps of 5 points:
			for(int egValue = 255 ; egValue >= 0; egValue -=5) { 
				
				// sets the value (range from 0 to 255):
				analogWrite(eg_pin, egValue);         
				
				// wait for time in milliseconds to see the dimming effect    
				delay(decay); 
			} 
			
		else {
			
			analogWrite(eg_pin, 0);
		}
	
		
    }      
	
}




/* NOISE */

noise::noise(int noise_pin)
{
	pinMode(noise_pin, OUTPUT);
	_pin = noise_pin;
	reg = 0x55aa55aaL; //The seed for the bitstream. 
	
}
void noise::generate(int noise_color)
{
    b31 = (reg & (1L << 31)) >> 31;
	b29 = (reg & (1L << 29)) >> 29;
	b25 = (reg & (1L << 25)) >> 25;
	b24 = (reg & (1L << 24)) >> 24;
	lobit = b31 ^ b29 ^ b25 ^ b24;
	newr = (reg << 1) | lobit;
	reg = newr;
	digitalWrite (_pin, reg & 1);
	delayMicroseconds (noise_color);
};





/* ARPEGGIATOR */

arpeggiator::arpeggiator(int arp_pin)
{
	pinMode(arp_pin, OUTPUT);
	_pin = arp_pin;
	
}
void arpeggiator::play(float bpm, int note, int note_values)
{
	_bpm = bpm;
	float _q = 1/_bpm*60000; //BPM to milliseconds formula, gives us our quarter note value 
	
	//calculate note durations based on BPM
	float _w = 4*_q; //whole notes
	float _h = _q*2; //half notes
	float _qt = (_q/3)*2; //quarter note triplets
	float _e = _q/2; // eighth notes
	float _et = (_e/3)*2; // eigth note triplets
	float _sx = _q/4; //sixteenth notes
	float _sxt = (_sx/3)*2; //sixteenth note triplets
	float _th = _q/8; //thrity-second notes
	float _sxf = _q/16; //sixty-fourth notes
	
	float _values[] = {_w, _h, _q, _qt, _e, _et, _sx, _sxt, _th, _sxf};

	analogWrite(_pin, note);
	delay(_values[note_values]);

};





/* LFO RATE QUANTIZER*/

lfo::lfo(int lfo_pin, int cv_pin)
{
	pinMode(lfo_pin, OUTPUT);
	_pin = lfo_pin;
	
	pinMode(cv_pin, INPUT);
	
}

void lfo::rate(int cv_note ,int rate_value)
{
	
	int _cv = analogRead(cv_pin);
	int cv_array[13] = {0, 50, 120, 180, 250, 310, 380, 440, 500, 570, 640, 700, 750};
	int _lfo_rate[] = {0, 66, 105, 133, 170 , 201, 235, 255};

	if (_cv >= cv_array[cv_note] && _cv < cv_array[cv_note+1]) 
	{ 
		//do something when note is triggered//
		analogWrite(_pin, _lfo_rate[rate_value] );
	}

	
};




/* LED VIBRATO*/

vibrato::vibrato(int led_pin, int rate_pin)

{
	pinMode(led_pin, OUTPUT);
	_pin = led_pin;
	
	pinMode(rate_pin, INPUT);
	
}



	void vibrato::rate(int min, int max, int bottom, int top)
	
	{
		
		int _rate = map(analogRead(rate_pin), 0, 1023, min, max);
		
		// fade in from 0 to 255 in steps of 5 points:
		for(int fadeValue = bottom ; fadeValue <= top; fadeValue +=5) { 
			
			// sets the value (range from 0 to 255):
			analogWrite(_pin, fadeValue);         
			
			// wait for time in milliseconds to see the dimming effect    
			delay(_rate);                            
		} 
		
		// fade out from 0 to 255 in steps of 5 points:
		for(int fadeValue = top ; fadeValue >= bottom; fadeValue -=5) { 
			
			// sets the value (range from 0 to 255):
			analogWrite(_pin, fadeValue);         
			
			// wait for time in milliseconds to see the dimming effect    
			delay(_rate);                            
		} 
	
	
};





	
	




