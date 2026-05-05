//Arashel - LoginEvent.cpp file


#include <iostream>
#include <sstream>
#include "LoginEvent.h"

using namespace std;

        LoginEvent::LoginEvent(string uid, string eid, string eventTime, string sever, string lstatus)
        : SystemEvent(uid, eid, "Login", eventTime, sever)
        {
            loginStatus = lstatus;  // new variable
        }
        
        void LoginEvent::displayInfo() {
        SystemEvent::displayInfo(); // this is from SystemEvent - the base class
        cout << "Login Status: " << loginStatus << endl;
    }
    
    string LoginEvent::toFileString() {
        stringstream ss;
        ss << SystemEvent::toFileString() << "," << loginStatus;
        return ss.str();
    }
    
    
