/**
    Copyright (c) 2015 Stefan Krüger
    licend under MIT (see LICENSE file)
**/

//==========================================
// include guard
#ifndef libClass_h
#define libClass_h

/** Includes Core Arduino functionality **/
#if ARDUINO
    #if ARDUINO < 100
        #include <WProgram.h>
    #else
        #include <Arduino.h>
    #endif
#endif

class libClass {
public:

    //==========================================
    // constructor

    libClass();
    libClass(uint32_t duration_new);

    virtual ~libClass();


    //==========================================
    // public types

    // typedef void (*cbfunc_t) (libClass *pInstance);
    typedef void (*cbfunc_t) (uint32_t counter);


    //==========================================
    // public functions

    void init();
    void update();

    void set_callbackfunc(cbfunc_t callbackfunc_new);
    void set_duration(uint32_t duration_new);

private:

    uint32_t lastAction;
    uint32_t duration;
    uint32_t counter;

    bool cbfunc_valid;
    cbfunc_t callbackfunc;



};

// typedef void (libCalss::*cbfunc_t)(libClass *pInstance);

#endif // libClass_h
