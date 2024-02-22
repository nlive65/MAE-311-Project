#pragma once
#include <Arduino.h>
#include <WiFi.h>
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include <WebSocketsServer.h>

namespace UI{
    void notFound(AsyncWebServerRequest *request);
    class Server{
        private:
        String header;
        AsyncWebServer server = AsyncWebServer(80);
        WebSocketsServer webLog = WebSocketsServer(81);
        IPAddress IP;

        
        public:
        Server();
        ~Server() = default; 
        IPAddress getIP();
        void runWifiLoop();
        void sendLogMsg(String msg);
    };
}