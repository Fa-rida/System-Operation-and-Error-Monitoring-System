//Arashel - LoginEvent header file


#include <iostream>
#include <string>
#include "SystemEvent.h"
#ifndef LOGINEVENT_H
#define LOGINEVENT_H

// class name 2: LoginEvent - used for the login attempts
using namespace std;

// because it is part of inheritance plan, instead of using basic
// class LoginEvent {, we are putting them together.
// loginEvent is a derived class (child)

class LoginEvent : public SystemEvent { //  guided by inheritance plan slides 
    private: 
    string loginStatus; //  this will help store login data info
    // + does not need string SystemEvent because it already is
    
    
    // used notes for polymorphism and chatGPT to explain what I was missing and
    // how to write it with no errors
   
    public: 
    LoginEvent(string uid, string eid, string time, string sever, string lstatus);
    
    void displayInfo() override;
    
    string toFileString() override;
    
    
};
#endif
