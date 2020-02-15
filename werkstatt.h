/*
 werkstatt.h -   
 Library for the Moog Werkstatt-01
 Moog Music Inc. 2014
 Written by Chris David Howe
*/

#include "Arduino.h"
#include <stdint.h>
#include <avr/interrupt.h>
#include <avr/io.h>
#include <avr/pgmspace.h>


#ifndef werkstatt_h
#define werkstatt_h


/* INTERFACE */

class interface
{
public:
	interface(int interface_pin);
	int momentary(int min, int max);
	int toggle(int max);
	int potentiometer(int min, int max);
private:
	int buttonCounter;
	int lastbuttonState;
	int _pin;
};

/* ACCELEROMETER */

class accelerometer
{
public:
	accelerometer(int x_pin, int y_pin, int z_pin);
	
	void x_axis(int x_out, int min, int max);
	void y_axis(int y_out, int min, int max);
	void z_axis(int z_out, int min, int max);
	
	void x_pulse(int x_out, int min, int max);
	void y_pulse(int y_out, int min, int max);
	void z_pulse(int z_out, int min, int max);
	
	int x_data;	
	int y_data;	
	int z_data;
	
	int x_out;
	int y_out;
	int z_out;
	
	int x_pin;
	int y_pin;
	int z_pin;
	
private:

	int axis;
	int interval;
	
	unsigned long x_previousMillis;
	unsigned long y_previousMillis;
	unsigned long z_previousMillis;
	
	int x_pulse_state;
	int y_pulse_state;
	int z_pulse_state;

};

/* GATE IN ENVELOPE GENERATOR */

class eg
{
public:
	eg (int gate_pin, int eg_pin);
	void trigger(int attack, int decay);
	

	
private:
	int eg_pin;
	int gate_pin;
	int attack;
	int decay;
	int egValue;
};

/* NOISE */

class noise
{
public:
    noise(int noise_pin);
    void generate(int noise_color);
private:
    int _pin;
	int _color;
	unsigned long int reg;
	unsigned long int newr;
	unsigned char lobit;
	unsigned char b31, b29, b25, b24;
};

/* ARPEGGIATOR */

class arpeggiator
{
public:
	arpeggiator(int arp_pin);
	void play(float bpm, int note, int note_values);
private:
	int _pin;
	float _bpm;
};

/* LFO RATE QUANTIZER*/

class lfo
{
public:
	lfo(int lfo_pin, int cv_pin);
	void rate(int cv_note, int rate);
	int cv_pin;
private:
	int _pin;
	int _cv;
	int cv_note;
	int rate_value;
};



/*VIBRATO*/

class vibrato 
{
public:
	vibrato(int led_pin, int rate_pin);
//	void on(int button, int min, int max);
	void rate(int min, int max, int bottom, int top);
	int led_pin;
	int rate_pin;
	int button;
private:
	int _led;
	int _pin;
	int _rate;
};




//Arpeggiator define

#define tonic 0
#define minor2nd 5
#define major2nd 10
#define minor3rd 15
#define major3rd 20
#define fourth 25
#define tritone 30
#define fifth 35
#define minor6th 40
#define major6th 45
#define minor7th 50
#define major7th 55
#define octave 60
#define octave2 120

#define w 0
#define h 1
#define q 2
#define qt 3
#define e 4
#define et 5
#define sx 6
#define sxt 7
#define th 8
#define sxf 9
	
//LFO Quantizer define

#define C1 0
#define Db 1
#define D 2
#define Eb 3
#define E 4
#define F 5
#define Gb 6
#define G 7
#define Ab 8
#define A 9
#define Bb 10
#define B 11
#define C2 12


//Wavetable define

#define speakerPin 11
#define INTERRUPT_PERIOD 512
#define FINT (F_CPU / INTERRUPT_PERIOD) // 16kHz?
#define FS (FINT)


#define sine 0
#define sawtooth 1
#define triangle 2
#define square 3


//Accelerometer define

#endif