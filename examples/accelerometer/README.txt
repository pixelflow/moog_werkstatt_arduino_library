Moog Werkstatt Accelerometer
Moog Music Inc. 2014
written by Chris David Howe


In this project we will be integrating an accelerometer to measure movement in three dimensions with our Werkstatt using an Arduino microcontroller.  An accelerometer is a device that measures acceleration in three dimensions and outputs a corresponding voltage. First we will see in the the sketch that our accelerometer class is called and named with input arguments that set the three analog inputs for ADXL335 data capture. The included accelerometer.pde sketch has two functions we can experiment with and these are defined as n_axis and n_pulse.   The variable n changes as we select what dimension we want to call to manipulate our control voltage.  


N_axis functions are scalable one to one mappings of incoming accelerometer data.  Input arguments for this function are as follows; (PWM out pin, minimum output PWM, maximum output PWM).  Functions of this type need to be run through a low pass filter for the best results as discussed earlier. 


N_pulse functions send digital on/off pulses at specific MS intervals based on captured sensor data. Input arguments for functions of this type are as follows; (digital out pin, minimum output MS, maximum output MS).