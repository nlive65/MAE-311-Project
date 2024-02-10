#include <Arduino.h>
#include <WiFi.h>

namespace UI{
    class Server{
        private:
        String header;
        WiFiServer server;
        IPAddress IP;
        public:
        Server();
        ~Server() = default; 
        IPAddress getIP();
        void runWifiLoop();
    };
}