#include "maximilian.h"

maxiOsc s1, s2, s3, s4, s5;

void setup() {
}

void play(double *output) {
    
    // a phasor that produces floating point values from 0 to 100 at a frequnecy of 0.0166 Hz
    // Let's make it take 1 minute (60 seconds) to reach from 0 to 100
    // For it to take one minute we divide 60 by 3600 to get 0.0166666667
    double phasor = s1.phasor(0.0166, 0, 100); // 0.016
    
   // double s_2 = s2.phasor(0.01, 0.01, 2); // use to modulate saw if desired
    
    // A saw wave at 0.1 Hz (in-audible) goes between -1 and 1, takes 10 secs to climb from -1 to 0, and 10 secs other way
    double saw = s2.saw(0.1);
    
    // A sinewave, set to 80Hz, but modulated using the phasor (0-100), which we multiply by the saw (-1.0 to 1.0)
    // max mod Index = 100, min mod index = -100
    // So, the sinewave frequency goes between -50 and 50 ( what does a negative number in the frequency argument mean?)
    double mod = s3.sinewave(50+(saw*phasor));

    // if we listen to s_4 it sounds like a tone going up in pitch, then abruptly going down and climbing up again
    // How fast the tone climbs is defined by the saw-wave. We could modulate this value with another phasor to make
    // the 'acceleration' time change over time.
    
    // but we don't stop here,
    // The frequency of a new sinewave is modulated by s_4, lending it a thick FM tone:
    double sine = s4.sinewave(100+(mod*100));

    // the result is a bit like a car accelerating. ..and stalling
    // the effect of the negative -50 can really be heard when we hear the frequency reach the low end and start to wobble
    
    output[0]= sine*0.5;
    output[1]=output[0];
}

// To Sum up:
/*
 A sinewave at 100Hz, modulated by another sinewave (-50 to 50 Hz), the frequency of which is also modulated using
 the values produced from mulitplying the saw-wave with the phasor - the phasor climbs for 1 minute, the saw-wave
 climbs for 10 seconds, then descends for 10. So there is an overall ascending frequency movement with dips throughout.
 */
