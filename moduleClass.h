/**
    Copyright (c) 2015 Stefan Krüger
    licend under MIT (see LICENSE file)
**/

//==========================================
// include guard
#ifndef moduleClass_h
#define moduleClass_h

/** Includes Core Arduino functionality **/
#if ARDUINO
    #if ARDUINO < 100
        #include <WProgram.h>
    #else
        #include <Arduino.h>
    #endif
#endif

// include used libraries
#include "libClass.h"

class moduleClass {
public:

    //==========================================
    // constructor

    moduleClass();

    virtual ~moduleClass();


    //==========================================
    // public types

    //==========================================
    // public functions

    void init();
    void update();


    uint32_t get_counter();


private:

    uint32_t counter;

    libClass internalLib;

    // libClass::cbfunc_t internalCbfunc();
    // void internalCbfunc(uint32_t counter);
    static void internalCbfunc(uint32_t counter);
};


#endif // moduleClass_h
