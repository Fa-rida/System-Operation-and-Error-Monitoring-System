//Arashel - FileEvent header file


#include <iostream>
#include <string>
#include "SystemEvent.h"
#ifndef FILEEVENT_H
#define FILEEVENT_H // needed for the .h files. all caps.

using namespace std;

class FileEvent : public SystemEvent { // : inheritance = related
    private: 
    string fileName;
    string operationType; 
    
    public:
    FileEvent(string uid, string eid, string time, string sever, string fileName, string operationType);


    void displayInfo() override;
    string toFileString() override;
    
    string getFileName(); // getter functions because they come from private and protected data members
    string getOperationType();
    
};
#endif
    
