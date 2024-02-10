#include "Server.hpp"
#include "UI_Constants.hpp"
#include <Arduino.h>
#include <WiFi.h>

UI::Server::Server(){
    server = WiFiServer(80);
    WiFi.softAP(UI::ssid,UI::wpa);
    IP = WiFi.softAPIP();
    server.begin();
}   

IPAddress UI::Server::getIP(){
    return IP;                                                                                                                                                                                             
}


void UI::Server::runWifiLoop(){
    WiFiClient client = server.available();
    if(client){
        Serial.println("New Client Connected");
        String currentLine = "";
        while(client.connected()){
            if(client.available()){
                char c = client.read();
                Serial.println("Byte received");
                header+=c;
                if(c=='\n'){
                    if(currentLine.length()==0){
                        client.println("HTTP/1.1 200 OK");
                        client.println("Content-type:text/html");
                        client.println("Connection: Close");
                        client.println();
                    }
                }
            }
        }
    }
}