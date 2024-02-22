#include "Server.hpp"
#include "UI_Constants.hpp"
#include <Arduino.h>
#include <WiFi.h>
#include <AsyncTCP.h>
UI::Server::Server(){
    WiFi.softAP(UI::ssid,UI::wpa);
    IP = WiFi.softAPIP();
    server.on("/",HTTP_GET,[](AsyncWebServerRequest *request){
        request->send(200,"text/html",UI::index_html);
    });
    
    server.on("/get",HTTP_GET,[](AsyncWebServerRequest *request){
        String inMsg;
        if(request->hasParam(UI::TEMP_INPUT)){
            inMsg = request->getParam(UI::TEMP_INPUT)->value();
            //send message to the sensor object 
        }
        //Repeat for the other messages
    });

    webLog.begin();
    webLog.onEvent([](uint8_t num, WStype_t type,uint8_t *payload,size_t length){
        //Might ad things here :P   
    });
    server.onNotFound(UI::notFound);
    server.begin();
    
}   

IPAddress UI::Server::getIP(){
    return IP;                                                                                                                                                                                             
}

void UI::notFound(AsyncWebServerRequest *request){
    request->send(404,"text/plain","Page Not found");
}

void UI::Server::runWifiLoop(){
    
}

void UI::Server::sendLogMsg(String msg){
    webLog.broadcastTXT(msg);
}