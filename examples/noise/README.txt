Moog Werkstatt Noise
Moog Music Inc. 2014
written by Chris David Howe


This noise generator example uses an Arduino digital output, an Arduino analog input, and 2x 10kΩ resistors. Our digital output sends the noise signal to the Werkstatt, which is passed through one of our 10kΩ potentiometers for signal mixing.  Our other 10kΩ potentiometer is hooked to the Arduino's 5V+ line, an analog input, and ground.  This will give us a value of 0-1023 depending on how far the potentiometer is turned to control the "color" of our noise.  See the file "werkstatt_noise.png" for a model of our circuit.  

The noise generator works by sending a randomized bit stream over an Arduino digital output.  I am mapping the incoming ADC 0-1023 data to a 1-3000 range. This proves for a more dynamic "color" range. The "color" refers to the tone or timbre, in this instance it has a bit crush and low pass effect. 