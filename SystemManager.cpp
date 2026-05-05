//Hala - SystemManager.cpp file

#include "SystemManager.h"
#include <iostream>
#include <sstream>

using namespace std;

SystemManager::SystemManager(LogManager* lm) { //the :: means that this belongs to the SystemManager class
    logManager = lm; //lm is what's passed in and LogManager is our private variable (we're not using a friend class because we don't want just anyone to access it.)
    failedLoginAttempts = 0; 
    isLoggedIn = false;
    hasUnsavedChanges = false;
    currentUserID = ""; //these four mean the same thing, it's the starting point of the program. " " because there is no user logged in,
  // no number because there are 0 failed login attempts, etc..
}

//this creates a unique ID for each event that happens, this is private so only WE can call it
string SystemManager::generateEventID() {
    static int counter = 100;
    counter++;
    return "EID-" + to_string(counter); //this line converts our number into a string
}
//the reason why we use static is so that i can remember it's value every time.
//so instead of resetting to 100, it would return 101 at the first instance, 102 at the second, and so on.

void SystemManager::login(string userID, string password) {
    string eid = generateEventID();
    string timestamp = "05-03-2026 10:00"; 

  //this essentially means that for every login attempt, we want WHO logged in, WHAT they typed, and WHEN they typed it
  // for now I used a placeholder for the time and date, and we are generating a unique ID for any event that happens as a result of this
  
    if (password != "pass123") { //again, I also used a placeholder for the password. This basically means if the password is NOT pass123...
        failedLoginAttempts++; //...we add 1 to the failed login attempt counter
        if (failedLoginAttempts >= 3) { //and if we reach or exceed 3 failed login attempts, it is suspicious!
            LoginEvent* e = new LoginEvent(userID, eid, timestamp, "Critical", "Failed - Brute Force Detected");
            logManager->addEvent(e);
            cout << "WARNING: Possible brute force attack detected!" << endl;
        } else {
            LoginEvent* e = new LoginEvent(userID, eid, timestamp, "Warning", "Failed Login Attempt"); //i used new because it makes a new object in our memory
            logManager->addEvent(e);
            cout << "Login failed. Try again." << endl;
        }
//therefore we are creating a critical loginevent/object which we fill in with ho did it, the event id, timestamp, severity, as well ass status
      
      
    } else {
        failedLoginAttempts = 0;
        isLoggedIn = true; //our bool is now true
        currentUserID = userID;
        LoginEvent* e = new LoginEvent(userID, eid, timestamp, "Info", "Successful Login");
        logManager->addEvent(e);
        cout << "Login successful! Welcome, " << userID << endl;
    }
} //if the password is was correct, then reset the fail counter back to zero, and store who logged in.

//this is our load file function! it handles when a user tries to load a file

void SystemManager::loadFile(string fileName) {
    string eid = generateEventID(); //we generate a unique eventID for this file event
  //and we check the following: are they even logged in first?
    string timestamp = "05-03-2026 10:00";
    if (!isLoggedIn) {
        cout << "Error: You must be logged in to load a file." << endl;
        return;
    } //if they aren't logged in, then they must be to proceed

    if (fileName == "") { 
      //we are creating a warning fileevent which means something went wrong
      //fileevent now requires the userID, eventID, timestamp, severity, the name of the file, and the "operation" type (what was the user trying to do)
        FileEvent* e = new FileEvent(currentUserID, eid, timestamp, "Warning", "Unknown", "Load Failed - No File Name Given");
        logManager->addEvent(e); //again, we are handing it to the logManager to log all events
        cout << "Error: No file name was given." << endl;
    } else  
        hasUnsavedChanges = true; //this means the user loaded a file but haven't saved yet
        FileEvent* e = new FileEvent(currentUserID, eid, timestamp, "Info", fileName, "Load Successful");
        logManager->addEvent(e); //we are creating an info fileevent (successful load) and handing it to the logManager
        cout << "File loaded successfully: " << fileName << endl;
    }
}

//this is our save file function, we use this to handle when the user tries to save a file
//its basically the same pattern as loadfile but for saving it, thats literally it.

void SystemManager::saveFile(string fileName) {
    string eid = generateEventID();
    string timestamp = "05-03-2026 10:00";

    if (!isLoggedIn) {
        cout << "Error: You must be logged in to save a file." << endl;
        return;
    }

  //pretty self-explanatory..if you're not logged in you need to be so you can save a file.
  
    if (fileName == "") {

        FileEvent* e = new FileEvent(currentUserID, eid, timestamp, "Warning", "Unknown", "Save Failed - No File Name Given");
        logManager->addEvent(e);
        cout << "Error: No file name was given." << endl;

    } else {

//the user pretty much saved successfully, so there aren't any more unsaved changes
      //ergo the "hasUnsavedChanges = false;"
      
        hasUnsavedChanges = false;
        FileEvent* e = new FileEvent(currentUserID, eid, timestamp, "Info", fileName, "Save Successful");
        logManager->addEvent(e);
        cout << "File saved successfully: " << fileName << endl;
    }
}

//this is our shutdown function which handles the system shutting down
//the cool thing about this is that we do not need any inputs, we just need to call it!

void SystemManager::shutdownSystem() {

    string eid = generateEventID();
    string timestamp = "05-03-2026 10:00";

    if (hasUnsavedChanges) {
      //if there are unsaved changes then warn the user!!
      //there is a warning severity because they could lose their work.
        ShutdownEvent* e = new ShutdownEvent(currentUserID, eid, timestamp, "Warning", "Shutdown with Unsaved Changes");
        logManager->addEvent(e);
        cout << "WARNING: You have unsaved changes! Shutting down anyway." << endl;
    } else {
  //this is now the severity of the info itself
  //we use this to shut the info down normally and most importantly cleanly
  //basically everything is fine here
        ShutdownEvent* e = new ShutdownEvent(currentUserID, eid, timestamp, "Info", "Clean Shutdown");
        logManager->addEvent(e);
        cout << "System shutting down cleanly." << endl;
    }

    isLoggedIn = false; //no one is logged in anymore
    currentUserID = ""; //clear the current user
    hasUnsavedChanges = false; //there are no more unsaved changes bc the system is off

  //basically: reset everything!

    cout << "System has shut down. Goodbye!" << endl;
}
