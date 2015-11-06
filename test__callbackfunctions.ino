/**
    Copyright (c) 2015 Stefan Krüger
    licend under MIT (see LICENSE file)
**/
/**
    test for callbackfunctions in 'libraries'
    in combination with modularisation of an project with classes

**/

#import "moduleClass.h"

moduleClass myModule;
// moduleClass myModule(with parameter);


#import "libClass.h"

libClass myLib(10000);




//****************************************************************************
// my global function

void test_cbf(uint32_t counter) {
    Serial.print(F("test_cbf - counter:"));
    Serial.println(counter);
}

//****************************************************************************
// setup
void setup() {

    //******************************************
    // init serial
    //******************************************

        // for ATmega32U4 devices:
        #if defined (__AVR_ATmega32U4__)
            //wait for arduino IDE to release all serial ports after upload.
            delay(2000);
        #endif

        Serial.begin(115200);

        // for ATmega32U4 devices:
        #if defined (__AVR_ATmega32U4__)
            // Wait for Serial Connection to be Opend from Host or 6second timeout
            unsigned long ulTimeStamp_Start = millis();
            while( (! Serial) && ( (millis() - ulTimeStamp_Start) < 6000 ) ) {
                1;
            }
        #endif

        Serial.println();
        Serial.println(F("test_callbackfunctions.ino"));
        Serial.print(F("  version: "));
        Serial.print(F(__DATE__));
        Serial.print(F("  "));
        Serial.print(F(__TIME__));
        Serial.println();

    //******************************************
    // init myModule
    //******************************************
        myModule.init();

    //******************************************
    // init myLib
    //******************************************
        myLib.init();
        myLib.set_callbackfunc(test_cbf);
}

//****************************************************************************
// loop
void loop() {
    myModule.update();
    myLib.update();
}
