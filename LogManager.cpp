//farida - logManager.cpp File
//josefina - file handling
#include "LogManager.h"
#include "SystemEvent.h"
#include "FileEvent.h"
#include "LoginEvent.h"
#include "ShutdownEvent.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>



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
        
        
       
//saveToFile() is to be able to save all events from LogManager into a file.
void LogManager :: saveToFile(string fileName){
    
    ofstream file(fileName); //this is an output file stream object and
                            //this opens the file for writing
    if(!file.is_open()){   // this tracks if file was successfully opened
        cout<<"Error saving file.\n";
        return;
        
    }
    // loops through the events that are stored in LogManger
    for(auto e : events){
        file << e->toFileString() <<endl; //writes it in the file
        
    }
    file.close(); // created so the file automatically closes when function ends
    cout << "Events saved successfully." << endl;
}

//LoadFromFile() is mean to read events from a file and recreates events objects
void LogManager :: loadFromFile(string fileName){
 
    //this is to create input file stream objects and reads file
    ifstream file(fileName);
    
    if(!file.is_open()){  //to make sure it is successfullu opened
        cout<<"Error opening file.\n";
        return;
    }
    
    string line; //will help store one line from a file at a time
        //getline(ss,type, ','); //getline will be either login,system or shutdown 

        //Login event
    while(getline(file,line)){ 
        stringstream ss(line); //string type; // meant to be able to store event (Login, system and Shutdown)
        
        string uid, eid, type, severity, timestamp;
        getline(ss,eid,',');//event id comes first here because that's the format used when saving to file but it comes second in the other parts because thats the constructor order.
        getline(ss,uid,',');
        getline(ss,type,',');
        getline(ss,severity,',');
        getline(ss,timestamp,',');
        
        SystemEvent* event = nullptr; //this pointer used to store any event object created
        
        //Login event
        if(type == "Login"){
          string loginStatus;
          getline(ss,loginStatus,',');
          //creates a new LoginEvent
          event = new LoginEvent(uid, eid, timestamp, severity, loginStatus);
          
        } 
        
        //File Event
        
        else if(type == "File"){
            string fileName, operationType;
            getline(ss, fileName, ','); //getting the file name and operation type because they are event specific data
            getline(ss, operationType, ',');//and were not included in the general getlines
            
            event = new FileEvent(uid, eid, timestamp, severity, fileName, operationType);
        }
            
        //Shutdown Event 
        
        else if(type == "Shutdown"){
            string shutdownStatus;
            getline(ss, shutdownStatus, ',');
            
            event = new ShutdownEvent(uid, eid, timestamp, severity, shutdownStatus);
        }
        
        // will run if the events types do no match 
        else{
            cout<<"Unknown event type: "<< type <<endl;
            continue;
        }
        //adds the newly created event object into the LogMangeranager vector
        addEvent(event);
    }
    
   file.close(); // closes file automatically
   cout << "Logs loaded successfully" << endl;
}

vector<SystemEvent*> LogManager::getEvents(){
    return events;
}
