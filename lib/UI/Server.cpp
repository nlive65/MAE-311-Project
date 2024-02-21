#include "Server.hpp"
#include "UI_Constants.hpp"
#include <Arduino.h>
#include <WiFi.h>
#include <AsyncTCP.h>

UI::Server::Server(){
    WiFi.softAP(UI::ssid,UI::wpa);
    IP = WiFi.softAPIP();
}   

IPAddress UI::Server::getIP(){
    return IP;                                                                                                                                                                                             
}


void UI::Server::runWifiLoop(){
    
}