#include "multiModalLogger.hpp"
//#include <LiquidCrystal.h>

common::multiModalLogger::multiModalLogger(){
    Serial.begin(9600);
    Serial1.begin(9600); // Change based on Serial for SD card
    //lcd = LiquidCrystal(1,2,3,4,5,6);
    //lcd.begin(16,2);
};




