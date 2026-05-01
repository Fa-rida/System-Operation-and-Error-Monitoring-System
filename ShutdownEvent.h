//Arashel - ShutdownEvent header file


#include <iostream>
#include <string>
#include "SystemEvent.h"
#ifndef SHUTDOWNEVENT_H //for the h file
#define SHUTDOWNEVENT_H

using namespace std;


// this is inheritance from the SystemEvent
  class ShutdownEvent : public SystemEvent { 
    
    private: // because its events from the system should be private
    string shutdownStatus;
    // these are the new variable + the rest are from the base class
    
    
    public: 
    ShutdownEvent(string uid, string eid, string time, string sever, string status);
   //status
    
    
    
  void displayInfo() override; //override like the other classes

  string toFileString() override;
    // member function shutdownstatus
  string getShutdownStatus();
    
};

#endif
