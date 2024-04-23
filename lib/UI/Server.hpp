#pragma once
#include <Arduino.h>
#include <WiFi.h>
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include <WebSocketsServer.h>
#include "../common/dataPacket.hpp"

namespace UI{
    //Definition for the 404 error for the server
    void notFound(AsyncWebServerRequest *request);
    class Server{
        private:
        String header;//Unused
        AsyncWebServer server = AsyncWebServer(80);//Creates the web server
        AsyncWebSocket webLog = AsyncWebSocket("/log");//Creates the websocket for the log
        AsyncWebSocket ghostDist = AsyncWebSocket("/dist");//Unused
        IPAddress IP;//IP address of the arduino
        public:
        Server();//Default constructor
        ~Server() = default; //Default destructor
        IPAddress getIP();//definitions of functions that are implemented in the c++ file
        void sendLogMsg(String msg);
        void sendGhostDist(String msg);//unused
        void begin_server();
        int recordDB(common::packet msg);
    };
}