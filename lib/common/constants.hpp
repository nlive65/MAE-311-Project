//All numerical constants for the common framework of the project
#pragma once 
#include <stdint.h>
#include <Arduino.h>
#define ADC_RESOLUTION 3.3/4095

namespace common{
    //Unused
    static double THERM_TV;
    static double MAGx_TV = 0;
    static double MAGy_TV = 0;
    static double MAGz_TV = 0;
    static bool calibrateSignal = false;
    //multiModalLogger logger_;
}