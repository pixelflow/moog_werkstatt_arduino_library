#include <werkstatt.h>

accelerometer acc(A0, A1, A2); //call and name the accelerometer class listing three analog inputs (x, y, z)


void setup(){
}

void loop(){

       acc.x_axis(9, 0, 1000); //n_axis functions are scalable one to one mappings of incoming data (analog out pin, minimum output pwm, maximum output pwm)
       acc.y_axis(10, 0, 1000);
       acc.z_axis(11, 0, 1000);
    
       acc.x_pulse(1, 255, 1024); //n_pulse functions send digital on/off pulses at specific ms intervals based on capture sensor data (digital out pin, minimum output ms, maximum output ms)
       acc.y_pulse(2, 25, 150);
       acc.z_pulse(3, 0, 25);
    
}
