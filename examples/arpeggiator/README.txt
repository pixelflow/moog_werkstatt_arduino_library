Moog Werkstatt Arpeggiator
Moog Music Inc. 2014
written by Chris David Howe


This arpeggiator example uses a single Arduino PWM output, a 10kΩ resistor, and a 2.2µf capacitor.  The analogWrite output of an Arduino is not a true analog signal so we must pass our PWM through a RC lowpass filter.  See the file "werkstatt_arpeggiator.png" for a model of our circuit.  

The arpeggiator works by cycling through two arrays at the same index. Before we can reliably use the werkstatt.h library for this task we need to CALIBRATE THE VCO EXP IN.  There will be a trimmer pot on the Werkstatt that needs to be calibrated when running the "VCO EXP Config" note array.  These need to be a perfect octave for interval accuracy.

The notes[] array holds any interval you want to access and is referenced as follows: tonic, minor2nd, major2nd, minor3rd,
major3rd, fourth, tritone, fifth, minor6th, major6th, minor7th, major7th, octave.  See reference.txt for chord and mode ideas. 


the note_values[] array holds all note duration information for each corresponding interval in the notes[] array and is referenced as follows:
w, h, q, qt, e, et, sx, sxt, th, sxf. These are defined as:
w = whole
h = half
q = quarter
qt = quarter triplet
e = eighth
et = eighth triplet
sx = sixteenth
sxt = sixteenth triplet
th = thirty second
sxf = sixty fourth






