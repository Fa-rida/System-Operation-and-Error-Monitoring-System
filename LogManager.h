//Farida - LogManager header file
//Josefina - file handling functions ( your functions go in this class because we took out the file handling class to make it just 6 classes)

#ifndef LOGMANAGER_H
#define LOGMANAGER_H
#include "SystemEvent.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;


class LogManager{
    private:
        vector<SystemEvent*>events;
        
    public:
        void addEvent(SystemEvent* genEvent); //genEvent means generated event
        
        void viewAllEvents();
        
        void searchByEventID(string eventID);
        
        void searchByUserID(string userID);
        
        void filterByType(string eventType);
        
        void filterBySeverity(string severity);
        
        void generateSummary();
        
        template <typename T> //creating a function template to count events that match the value by severity or type.
        int countEvents(T value, string category){
            int count = 0;
            for (int i = 0; i < events.size(); i++){ //looping through the vector
                if (category == "severity"){ //if the category is severity,
                    if (events.at(i)->getSeverity() == value){// and the severity value matches the given value,
                        count = count + 1;                      //increase count.
                    }
                }
                else if (category == "type"){
                    if(events.at(i)->getEventType() == value){
                        count = count + 1;
                    }
                }
            }
            return count;
        }
        
        ~LogManager();
};
#endif

#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include <string> 
using namespace std;


class LogManager;//calling on LogManager (file already exists)
 
//Handles saving event data to files and loads into files 
class FileHandler {
    public:
    //will take all events from LogManager and write them into files
        void saveToFile(LogManager* lm, string fileName);//lm is pointer to the LogManager
                                                        // and fileName is name to the file we have to save into 
    //will read all event data from a file and recreate event objects
        void loadFromFile(LogManager* lm, string fileName);//fileName is name of file to read from 
        

};

#endif
