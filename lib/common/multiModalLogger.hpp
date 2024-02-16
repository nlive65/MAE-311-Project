#pragma once 
#include <Arduino.h>

namespace common{
    
    class multiModalLogger{
        private:
        //LiquidCrystal lcd;
        public:
        multiModalLogger();
        ~multiModalLogger() = default;
        template <typename... Args>
        void log(Args&&... args);
        
        template <typename... Args>
        void logln(Args&&... args);
    };
}