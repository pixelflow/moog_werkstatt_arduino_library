Moog Werkstatt LFO rate
Moog Music Inc. 2014
written by Chris David Howe


This LFO rate example uses an Arduino PWM output, Arduino analog input, a 10kΩ resistor, and a 2.2µf capacitor.  The analogWrite output of an Arduino is not a true analog signal so we must pass our PWM through a RC lowpass filter.  We are using the Werkstatt CV OUT to Arduino analog in to determine what note is being pressed.  See the file "werkstatt_lforate.png" for a model of our circuit.  

The LFO rate quantizer works by cycling through two arrays at the same index.  LFO rate value will change in direct correlation to what control voltage (CV) note is being pressed. 

The notes[] array holds any note you want to access on the Werkstatt keyboard and is referenced as follows: C1, Db , D , Eb , E, F, Gb , G, Ab , A , Bb , B, C2.

the note_values[] array holds all LFO rate value information for each corresponding CV input in the notes[] array and is referenced as follows:
w, h, q, qt, e, et, sx . These are defined as:
w = whole
h = half
q = quarter
qt = quarter triplet
e = eighth
et = eighth triplet
sx = sixteenth


