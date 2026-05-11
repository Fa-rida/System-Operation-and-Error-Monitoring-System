//Arashel - System event.cpp file


#include <iostream>
#include <sstream> 
#include "SystemEvent.h"
// this will have the function definitions of base class meaning
// the functions that are being used
// learned that :: is needed when it comes to implementation because
// we need to know which class the function belongs to. ex: classname::
SystemEvent::SystemEvent(string uid, string eid, string event, string eventTime, string sever) {
        userID = uid;
        eventID = eid;
        eventType = event;
        timestamp = eventTime;
        severity = sever;
}
// needs display function(polymorphism) and file string for csv. .cpp does not use virtual
// polymorphism helps with choosing which class to choose from


// this will display all data that was stored through polymorphism
    void SystemEvent::displayInfo() {
        cout << "User ID: " << userID << endl;
        cout << "Event ID: " << eventID << endl;
        cout << "Event Type: " << eventType << endl;
        cout << "Time of event: " << timestamp << endl;
        cout << "Severity: Safe|Warning|Critical: " << severity << endl;
    }
    
    
    string SystemEvent::toFileString() {
        stringstream ss;
        ss << eventID << "," << userID << "," << eventType << ","
        << severity << "," << timestamp;
        return ss.str();
    }

    bool SystemEvent::operator == (const systemEvent& other){ //operator overloading part. compares 2 event IDs to check if they are equal
        return eventID == other.eventID;
    }

    SystemEvent::~SystemEvent() {}
