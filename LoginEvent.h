// //Arashel - LoginEvent header file


// #include <iostream>
// #include <string>
// #include "SystemEvent.h"
// #ifndef LOGINEVENT_H
// #define LOGINEVENT_H

// // class name 2: LoginEvent - used for the login attempts
// using namespace std;

// // because it is part of inheritance plan, instead of using basic
// // class LoginEvent {, we are putting them together.
// // loginEvent is a derived class (child)

// class LoginEvent : public SystemEvent { //  guided by inheritance plan slides 
//     private: 
//     string loginStatus; //  this will help store login data info
//     // + does not need string SystemEvent because it already is
    
    
//     // used notes for polymorphism and chatGPT to explain what I was missing and
//     // how to write it with no errors
   
//     public: 
//     LoginEvent(string uid, string eid, string eventTime, string sever, string lstatus);
    
//     void displayInfo() override;
    
//     string toFileString() override;
    
    
// };

// #endif

#ifndef LOGINEVENT_H
#define LOGINEVENT_H

#include "SystemEvent.h"
#include <string>

using namespace std;

class LoginEvent : public SystemEvent
{
private:
    string loginStatus;

public:
    LoginEvent(string eventID, string userID, string severity,
               string timestamp, string status);

    void displayInfo() override;

    string toFileString() override;
};

#endif