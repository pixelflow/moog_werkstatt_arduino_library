Moog Werkstatt LED Vibrato
Moog Music Inc. 2014
written by Chris David Howe


In this tutorial we will be adding a button controlled vibrato effect using a photoresistor, LED, and Arduino microcontroller. By using an external circuit for vibrato we are able to free up our LFO for other forms of modulation.  This patch is written to be uploaded right out of the box and work, however if you want to make modifications there are several places where that is possible.  The LED pin can of course be changed, just be sure that you are select a PWM output pin.  The rate pin is set to A0 by default, if you change this be sure you select another analog input pin to ensure reading our rate potentiometer is possible. The most dynamic variables to change are the LED low, center, and high settings. 

The low variable sets what the lowest point of brightness of our LED during the vibrato fade.  Center designates what brightness the LED has when the pushbutton is not pressed. High sets the peak brightness of our LED during the vibrato fade.  By default these settings come set to create a vibrato and oscillates up and down around the fundamental frequency.  By changing these you could conceivably create vibrato that only oscillates in one direction, in a reverse order, or with a favoring of a specific direction.  