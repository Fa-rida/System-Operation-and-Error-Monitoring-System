//Arashel - ShutdownEvent.cpp file


#include <iostream>
#include <string>
#include <sstream>
#include "ShutdownEvent.h"

using namespace std;
// class name 4 ShutdownEvent
// uses :: again to match the other classes + data comes from other classes
    ShutdownEvent::ShutdownEvent(string uid, string eid, string time, string sever, 
    string status) : SystemEvent(uid, eid, "Shutdown", time, sever) {
     
     // defining the variable
     shutdownStatus = status;
 }
 
 void ShutdownEvent::displayInfo() {
     SystemEvent::displayInfo();
    cout << "Shutdown Status : " << shutdownStatus << endl;
 }
 
 
 string ShutdownEvent::toFileString() {
     stringstream ss; 
     ss << SystemEvent::toFileString() << ",System Shutdown," << shutdownStatus; 
     return ss.str();
 }
 
 
 // getter function 
 string ShutdownEvent::getShutdownStatus() {
     return shutdownStatus;
 }
