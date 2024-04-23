#pragma once 
#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
#include <sstream>
#include "../UI/Server.hpp"
#include "dataPacket.hpp"
//Class to handle all external logging and data sending

const uint8_t LCDAddr = 0x27;//I2C address for the lcd screen
namespace common{
    class multiModalLogger{
        private:
        //Variable to hold the LCD interface
        LiquidCrystal_I2C lcd = LiquidCrystal_I2C(LCDAddr,16,2);

        //These functions handle the indefinite arguments and puts it into the string one at a time
        template <typename T, typename... Args>
        void logHelper(std::ostringstream& oss, const T& first, const Args&... rest){
            //Inserts the current argument into the string
            oss << first;
            logHelper(oss,rest...);
        }

        template<typename T>
        void logHelper(std::ostringstream& oss, const T& last){
            oss <<last;
        }

        //Instance of the web server
        UI::Server server;
        public:
        multiModalLogger();
        ~multiModalLogger() = default;

        //Takes any number of inputs
        template<typename... Args>
        void log(const Args&... args){
            //Create String 
            std::ostringstream oss;
            //Sends the other arguments passed to be passed to the string
            logHelper(oss, args...);
            //Converts the string stream to a normal string
            String printableStr = oss.str().c_str();
            //Sends that string to the server, serial and lcd
            Serial.println(printableStr);
            lcd.setCursor(0,0);
            lcd.clear();
            lcd.print(printableStr); 
            server.sendLogMsg(printableStr);
        }
        
        void sendData(packet data){
            //Formats the data packet into a string 
            String PrintableStr = data.type + ","  + String(data.time) + "," + String(data.magData.x,3) + "," + String(data.magData.y,3) +"," + String(data.magData.z,3) + "," +String(data.thermData,1);
            //Sends the string over the serial and the log websocket
            Serial.println(PrintableStr);
            server.sendLogMsg(PrintableStr);
            //Sends the data to the database
            int response = server.recordDB(data);
            //Prints the database response
            Serial.print("SQL Response: ");
            Serial.println(response);
            Serial1.println(PrintableStr);
        }
        //Logger initializer definition
        void init_logger();

        //Unused
        void sendUpdatedDistance(double distance){
            String newDist = String(distance,3);
            server.sendGhostDist(newDist);
            log("Updated Ghost Distance");
        }
};
}