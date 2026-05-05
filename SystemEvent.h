//Arashel - System event header
// systemEvent class header



#include <iostream>
#include <string> // being used for userID, eventID etc
#include <sstream>
#ifndef SYSTEMEVENT_H
#define SYSTEMEVENT_H // these are used for .h files
// class name 1 = SystemEvent

using namespace std;

class SystemEvent {
    //SystemEvent is also the base class part of inheritance. Which is why we are 
    // using protected class since the other classes need access to the data below. 
    // meaning "inheritance" - takes from it
    
    protected: // using protected because we are using inheritance
    string userID; // Example: EID-101. Labels
    string eventID; // Example: UID-105. Labels
    string eventType; // login, saving, loading
    string timestamp; // when it happened
    string severity; // severity level - high moderate
    
    public: //names
    SystemEvent (string uid, string eid, string event, string eventTime, string sever);
    virtual void displayInfo();
    virtual string toFileString();
    virtual ~SystemEvent();
    
    string getUserID() {
        return userID;
    }
    string getEventID() {
        return eventID;
    }
    string getEventType() {
        return eventType;
    }
    string getTimestamp() {
        return timestamp;
    }
    string getSeverity() {
        return severity;
    }
    
    
}; // always for classes
#endif   // needs to be used when using ifndef/define

