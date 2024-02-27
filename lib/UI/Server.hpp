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
        AsyncWebSocket webLog = AsyncWebSocket("/log");
        AsyncWebSocket ghostDist = AsyncWebSocket("/dist");
        IPAddress IP;
        public:
        Server();
        ~Server() = default; 
        IPAddress getIP();
        void sendLogMsg(String msg);
        void sendGhostDist(String msg);
        void begin_server();
    };
}