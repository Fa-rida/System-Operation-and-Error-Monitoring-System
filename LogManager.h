//farida - logmanager.h file
//josefina - file handling

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
        
        vector<SystemEvent*> getEvents();
        
        void viewAllEvents();
        
        void searchByEventID(string eventID);
        
        void searchByUserID(string userID);
        
        void filterByType(string eventType);
        
        void filterBySeverity(string severity);
        
        void generateSummary();
        
        void saveToFile(string fileName);// will take all events from LogManager and write them into files
        
        void loadFromFile(string fileName);//will read all events data from a file recreat event odject
        
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
