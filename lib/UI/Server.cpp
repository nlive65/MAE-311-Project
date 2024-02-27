#include "Server.hpp"
#include "UI_Constants.hpp"
#include <Arduino.h>
#include <WiFi.h>
#include <AsyncTCP.h>
#include "../common/constants.hpp"
UI::Server::Server(){
    
    
}   

IPAddress UI::Server::getIP(){
    return IP;                                                                                                                                                                                             
}

void UI::notFound(AsyncWebServerRequest *request){
    request->send(404,"text/plain","Page Not found");
}

void UI::Server::sendLogMsg(String msg){
    webLog.textAll(msg);
}

void UI::Server::sendGhostDist(String msg){
    ghostDist.textAll(msg);
}

void UI::Server::begin_server(){
    WiFi.mode(WIFI_STA);
    WiFi.begin("Student5","Go Chargers!");
    while(WiFi.status() != WL_CONNECTED){
        delay(1000);
    }
    IP = WiFi.localIP();
    server.on("/",HTTP_GET,[](AsyncWebServerRequest *request){
        request->send(200,"text/html",UI::index_html);
    });
    
    server.on("/get",HTTP_GET,[](AsyncWebServerRequest *request){
        String inMsg;
        if(request->hasParam(UI::TEMP_INPUT)){
            inMsg = request->getParam(UI::TEMP_INPUT)->value();
            common::THERM_TV = inMsg.toDouble();
            Serial.println("made it here");
            //send message to the sensor object 
            //Make offset as global var 
        }
        else if(request->hasParam(UI::MAGx_INPUT)){
            inMsg = request->getParam(UI::MAGx_INPUT)->value();
            common::MAGx_TV = inMsg.toDouble();
        }
        else if(request->hasParam(UI::MAGy_INPUT)){
            inMsg = request->getParam(UI::MAGy_INPUT)->value();
            common::MAGy_TV = inMsg.toDouble();
        }
        else if (request->hasParam(UI::MAGz_INPUT)){
            inMsg = request->getParam(UI::MAGz_INPUT)->value();
            common::MAGz_TV = inMsg.toDouble();
        }
        else if (request->hasParam(UI::CALIBRATE)){
            inMsg = request->getParam(UI::CALIBRATE)->value();
            common::calibrateSignal = true;
        }
        request->send(200,"text/html",index_html);
    });

    webLog.onEvent([](AsyncWebSocket *server, AsyncWebSocketClient *client, AwsEventType type, void *arg, uint8_t *data, size_t len){
        //Might ad things here :P   
    });

    ghostDist.onEvent([](AsyncWebSocket *socketServer, AsyncWebSocketClient *client, AwsEventType type,void *arg, size_t len){
        //May put things here too ^_^
    });
    server.onNotFound(UI::notFound);
    server.addHandler(&webLog);
    server.addHandler(&ghostDist);
    server.begin();
}