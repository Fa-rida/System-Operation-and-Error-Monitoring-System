//Hala - SystemManager header file
#ifndef SYSTEMMANAGER_H
#define SYSTEMMANAGER_H //We use #ifndef and #define to stop this file from being copy-pasted twice in our program
#include <string>
#include "LoginEvent.h"
#include "FileEvent.h"
#include "ShutdownEvent.h" //We are including all the classes because we are creating the objects
#include "LogManager.h" //we also include log manager because after an event is created in must be logged/stored

using namespace std;

class SystemManager {

private:
    string currentUserID; //stores who is currently logged in, ex: "UID-607"
    int failedLoginAttempts; //counts how many times there is a failed login attempt to predict a brute force attack
    bool isLoggedIn; 
    bool hasUnsavedChanges; //both of these bools do the same thing: is someone logged in? did the user load a file but not save it?
    LogManager* logManager; //we are pointing to the logmanager class

public:

    SystemManager(LogManager* lm);  //a constructor than runs automatically, lm is an alias for the log manager we recieve
    void login(string userID, string password); //this is our login function which needs a userID
    void loadFile(string fileName);
    void saveFile(string fileName); //these handle saving and loading a file; pretty self explanatory
    void shutdownSystem(); //this handles the system shutting down, we just call it and our system shuts down

private:

    string generateEventID();

}; //don't forget the semi-colon at the end :P

#endif // we use this as well (alongside #define and #ifndef) for the same purpose
