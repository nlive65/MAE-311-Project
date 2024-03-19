#include "multiModalLogger.hpp"


common::multiModalLogger::multiModalLogger(){
    
};

void common::multiModalLogger::init_logger(){
    Serial.begin(9600);
    lcd.init();
    lcd.backlight();
    server.begin_server();
    this->log("IP ",server.getIP());
    Serial.print("IP ");
    Serial.println(server.getIP());
    Serial1.begin(9600);
    Serial1.println("Time(ms),MagX,MagY,MagZ,Temp(C),Voltage(v)");
}
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