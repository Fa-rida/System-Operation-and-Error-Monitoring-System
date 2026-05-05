//Farida - LogManager.cpp file
//Josefina - Implementation of the file functions.

#include "LogManager.h"
#include "SystemEvent.h"
#include <iostream>
#include <fstream>
#include <string>




        void LogManager::addEvent(SystemEvent* genEvent){ //adds events to the vector
            if (genEvent != nullptr){ //checking to see if the event object pointer received is empty
                events.push_back(genEvent);
                cout << "event added successfully" << endl;
            }
            else {
                cout << "invalid event object" << endl;
            }
        }
        
        void LogManager::viewAllEvents(){ //prints out all the events
            if (events.empty()){
                cout << "No events available" << endl;
            }
            else {
                for(int i = 0; i < events.size(); i++ ){
                    events.at(i)->displayInfo();
                }
            }
        }
        
        void LogManager::searchByEventID(string eventID){
            bool found;
            found = false;
            for (int j = 0; j < events.size(); j++) { //loop to check if there are events with that ID
                if (events.at(j)->getEventID() == eventID){
                    found = true;
                    events.at(j)->displayInfo(); //using the arrow operator to call the function because the object is a pointer.
                }
            }
            if (found == false) {
                cout << "Event not found" << endl;
            }
        }
        
        void LogManager::searchByUserID(string userID){
            bool found;
            found = false;
            for (int p = 0; p < events.size(); p++){
                if (events.at(p)->getUserID() == userID){
                    found = true;
                    events.at(p)->displayInfo();
                }
            }
            if (found == false){
                cout << "No events found for this user" << endl;
            }
        }
        
        void LogManager::filterByType(string eventType){//filtering by event type (file, shutdown, login or...)
            bool found;
            found = false;
            for (int b = 0; b < events.size(); b++){ //looping through the vector
                if (events.at(b)->getEventType() == eventType){ // an if condition nested in the for loop to compare event types.
                    found = true;
                    events.at(b)->displayInfo();
                }
            }
            if (found == false){
                cout << "No matching results for this event type" << endl;
            }
        }
        
        void LogManager::filterBySeverity(string severity){
            bool found;
            found = false;
            for (int k = 0; k < events.size(); k++){
                if (events.at(k)->getSeverity() == severity){// an if condition nested in the for loop to compare severity levels.
                    found = true;
                    events.at(k)->displayInfo();
                }
            }
            if (found == false){
                cout << "No matching results for this severity level" << endl;
            }
        }
        
        
        void LogManager::generateSummary(){
            int totalEvents = events.size();  
            int safeEvents = countEvents("Safe", "severity");  
            int warningEvents = countEvents("Warning", "severity");  
            int criticalEvents = countEvents("Critical", "severity");
            int loginEvents = countEvents("Login", "type");  
            int fileEvents = countEvents("File", "type");  
            int shutdownEvents = countEvents("Shutdown", "type");
            
           
            cout << "Total Events: " << totalEvents << endl;
            cout << "Safe Events: " << safeEvents << endl;
            cout << "Warning Events: " << warningEvents << endl;
            cout << "Critical Events: " << criticalEvents << endl;
            cout << "Login Events: " << loginEvents << endl;
            cout << "File Events: " << fileEvents << endl;
            cout << "Shutdown Events: " << shutdownEvents << endl;
        }
        
        LogManager::~LogManager(){
            for (int d = 0; d < events.size(); d++){ //this helps delete stuff from memory to free up space
                delete events.at(d);
            }
            events.clear(); //deletes elements in the vector
        }
        
        
        
        
        
        
        
        
