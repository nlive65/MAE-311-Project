#include <Arduino.h>
#include <WiFi.h>
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>

namespace UI{
    class Server{
        private:
        String header;
        AsyncWebServer server = AsyncWebServer(80);
        IPAddress IP;
        public:
        Server();
        ~Server() = default; 
        IPAddress getIP();
        void runWifiLoop();
    };
}