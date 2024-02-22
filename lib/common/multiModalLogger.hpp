#pragma once 
#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
#include <sstream>
#include "../UI/Server.hpp"
//TODO handle SD wrapping over the normal writer since that is data only
const uint8_t LCDAddr = 0x27;
namespace common{
    class multiModalLogger{
        private:
        LiquidCrystal_I2C lcd = LiquidCrystal_I2C(LCDAddr,16,2);
        template <typename T, typename... Args>
        void logHelper(std::ostringstream& oss, const T& first, const Args&... rest){
            oss << first;
            logHelper(oss,rest...);
        }

        template<typename T>
        void logHelper(std::ostringstream& oss, const T& last){
            oss <<last;
        }
        UI::Server server;
        public:
        multiModalLogger();
        ~multiModalLogger() = default;
     
        template<typename... Args>
        void log(const Args&... args){
            std::ostringstream oss;
            logHelper(oss, args...);
            String printableStr = oss.str().c_str();
            Serial.println(printableStr);
            lcd.setCursor(0,0);
            lcd.clear();
            lcd.print(printableStr); 
            server.sendLogMsg(printableStr);
        }
};
}