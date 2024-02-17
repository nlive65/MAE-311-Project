#include "multiModalLogger.hpp"


common::multiModalLogger::multiModalLogger(){
    Serial.begin(9600);
    lcd.init();
    lcd.backlight();
};


// template <typename T, typename... Args>
// void common::multiModalLogger::logHelper(std::ostringstream& oss, const T& first, const Args&... rest){
//     oss << first;
//     logHelper(oss,rest...);
// }

// template<typename T>
// void common::multiModalLogger::logHelper(std::ostringstream& oss, const T& last){
//     oss <<last;
// }

// template<typename... Args>
// void common::multiModalLogger::log(const Args&... args){
//     std::ostringstream oss;
//     logHelper(oss, args...);
//     String printableStr = oss.str();
//     Serial.print(printableStr);
//     //DO LCD_writing
// }

// template<typename... Args>
// void common::multiModalLogger::logln(const Args&... args){
//     std::ostringstream oss;
//     logHelper(oss,args...);
//     String printableStr = oss.str();
//     Serial.println(printableStr);
// }