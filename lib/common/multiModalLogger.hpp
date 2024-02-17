#pragma once 
#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
#include <sstream>

//TODO handle SD wrapping over the normal writer since that is data only
namespace common{
    class multiModalLogger{
        private:
        LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27,16,2);
        template <typename T, typename... Args>
        void logHelper(std::ostringstream& oss, const T& first, const Args&... rest){
            oss << first;
            logHelper(oss,rest...);
        }

        template<typename T>
        void logHelper(std::ostringstream& oss, const T& last){
            oss <<last;
        }
        public:
        multiModalLogger();
        ~multiModalLogger() = default;
     
        template<typename... Args>
        void log(const Args&... args){
            std::ostringstream oss;
            logHelper(oss, args...);
            String printableStr = oss.str().c_str();
            Serial.print(printableStr);
            //DO LCD_writing
        }

        template<typename... Args>
        void logln(const Args&... args){
            std::ostringstream oss;
            logHelper(oss,args...);
            String printableStr = oss.str().c_str();
            Serial.println(printableStr);
        }
};
}