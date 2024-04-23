#include "Server.hpp"
#include "UI_Constants.hpp"
#include <Arduino.h>
#include <WiFi.h>
#include <AsyncTCP.h>
#include "../common/constants.hpp"
#include <HTTPClient.h>
#include "secret.hpp"
#include <sstream>
//Default constructor
UI::Server::Server(){
    
    
}   

//Returns the IP address of the board
IPAddress UI::Server::getIP(){
    return IP;                                                                                                                                                                                             
}

//Sets a response if the webpage can't be served but a connection occurs
void UI::notFound(AsyncWebServerRequest *request){
    request->send(404,"text/plain","Ghost has taken Webpage");
}

//Publish to the log websocket for any connected device to receive 
void UI::Server::sendLogMsg(String msg){
    webLog.textAll(msg);

}
//Unused
void UI::Server::sendGhostDist(String msg){
    ghostDist.textAll(msg);
}

void UI::Server::begin_server(){
    //Sets up the internet connection
    WiFi.mode(WIFI_STA);
    WiFi.begin("Student5","Go Chargers!");
    while(WiFi.status() != WL_CONNECTED){
        delay(1000);
    }
    IP = WiFi.localIP();

    //When the server recieves a request for the webpage
    server.on("/",HTTP_GET,[](AsyncWebServerRequest *request){
        request->send(200,"text/html",UI::index_html);//Send the webpage
    });
    //Unused
    server.on("/get",HTTP_GET,[](AsyncWebServerRequest *request){
        String inMsg;
        if(request->hasParam(UI::TEMP_INPUT)){
            inMsg = request->getParam(UI::TEMP_INPUT)->value();
            common::THERM_TV = inMsg.toDouble();
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
        request->send(200,"text/html",UI::index_html);
    });
    //Creates an event handler for the log websocket
    webLog.onEvent([](AsyncWebSocket *server, AsyncWebSocketClient *client, AwsEventType type, void *arg, uint8_t *data, size_t len){
        //Might ad things here :P   
    });

    ghostDist.onEvent([](AsyncWebSocket *server, AsyncWebSocketClient *client, AwsEventType type, void *arg, uint8_t *data, size_t len){
        //May put things here too ^_^
    });
    //Adds the handlers onto the server and starts hosting it
    server.onNotFound(UI::notFound);
    server.addHandler(&webLog);
    server.addHandler(&ghostDist);  
    server.begin();
}

int UI::Server::recordDB(common::packet msg){
    //Converts the packet into a json format and sends it to the backend over an HTTP request
    std::stringstream ss;//String to store the data
    //converts to json
    ss << "{";
    ss << "\"PacketType\":\"" << msg.type <<"\",";
    ss << "\"MagX\":" << msg.magData.x <<",";   
    ss << "\"MagY\":" << msg.magData.y <<",";
    ss << "\"MagZ\":" << msg.magData.z <<",";
    ss << "\"Temp\":" << msg.thermData <<",";
    ss << "\"time\":" << msg.time <<"";
    ss << "}";
    //Converts the json to a string to put into the request
    std::string jsonData = ss.str();
    String payload= String(jsonData.c_str());
    HTTPClient http;
    //Begins the request
    http.begin(UI::SQL_API);

    http.addHeader("Content-Type","application/json");

    int response = http.POST(payload);//Sends the request and listens for the response

    return(response);
}