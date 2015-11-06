/**
    Copyright (c) 2015 Stefan Krüger
    licend under MIT (see LICENSE file)
**/

/** Includes Core Arduino functionality **/
#if ARDUINO
    #if ARDUINO < 100
        #include <WProgram.h>
    #else
        #include <Arduino.h>
    #endif
#endif

// include own header file
#include "libClass.h"

//==========================================
// constructor

libClass::libClass() {
    cbfunc_valid = false;
    lastAction = 0;
    counter = 0;
    duration = 2000;
}

libClass::libClass(uint32_t duration_new) {
    cbfunc_valid = false;
    lastAction = 0;
    counter = 0;
    duration = duration_new;
}

libClass::~libClass() {
    // nothing to do here
}


//==========================================
// public functions

void libClass::init() {
    lastAction = millis();
}

void libClass::update() {
    uint32_t current_duration = (millis() - lastAction);
    if (current_duration >= duration) {
        // reset
        lastAction = millis();

        counter = counter +1;

        // run callback function
        if (cbfunc_valid) {
            // callbackfunc(this);
            callbackfunc(counter);
        }
    }
}


void libClass::set_duration(uint32_t duration_new) {
    duration = duration_new;
}

void libClass::set_callbackfunc(cbfunc_t callbackfunc_new) {
    callbackfunc = callbackfunc_new;
    cbfunc_valid = true;
}
