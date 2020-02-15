This is a library for the Moog Werkstatt-01
  ----> http://www.moogmusic.com/products/werkstatt/werkstatt-¿1-moogfest-2014-kit

Written by Chris David Howe for Moog Music Inc. 

MIT license, all text above must be included in any redistribution

Download and rename the uncompressed folder moog_werkstatt. Check that the moog_werkstatt folder contains werkstatt.cpp and werkstatt.h.

Place the moog_werkstatt library folder your <arduinosketchfolder>/libraries/ folder. You may need to create the libraries subfolder if its your first library. Restart the IDE.

This library is currently under development now in version 1.0 

***** CLASSES/FUNCTIONS *****

interface name(int input pin)
	interface.toggle(int maximum)
	interface.momentary(int minimum, int maximum)
	interface.potentiometer(int minimum, int maximum)

arpeggiator name(int output PWM pin)
	arpeggiator.play(int BPM, int notes[], int note_values[])

lfo name(int output PWM pin, int input analog pin)
	lfo.rate(notes[], note_values[])

noise name(int output digital pin)
	noise.generate(int noise color) 


