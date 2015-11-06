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
#include "moduleClass.h"

// include used libraries
#include "libClass.h"

//==========================================
// constructor

moduleClass::moduleClass() {
    counter = 0;
}

moduleClass::~moduleClass() {
    // nothing to do here
}


//==========================================
// public functions

void moduleClass::init() {
    counter = 0;
    //******************************************
    // init myLib
    //******************************************
        internalLib.init();
        internalLib.set_duration(3000);
        internalLib.set_callbackfunc(internalCbfunc);
}

void moduleClass::update() {
    counter = counter +1;

    internalLib.update();
}


uint32_t moduleClass::get_counter() {
    return counter;
}

//==========================================
// private functions

libClass::cbfunc_t moduleClass::internalCbfunc() {
    Serial.print(F("internalCbfunc - counter:"));
    Serial.println(counter);
}
