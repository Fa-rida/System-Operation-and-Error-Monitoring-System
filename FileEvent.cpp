//Arashel - FileEvent.cpp file


#include <iostream>
#include <sstream> // because we are using stringstream
#include <string>
#include "FileEvent.h"


using namespace std;

// :: wthis is used for which class the data belongs to
   FileEvent::FileEvent(string uid, string eid, string eventTime, string sever, 
      string fName, string opType) : SystemEvent(uid, eid, "File", eventTime, sever)
{
    // the base class variables + new variables for FileEvent
    
    fileName = fName; 
    operationType = opType;
    
}

 
   void FileEvent::displayInfo() { // same idea as the other two classes
       SystemEvent::displayInfo();
       cout << "File Name: " << fileName << endl;
       cout << "Operation Type: " << operationType << endl;
   }
   
   string FileEvent::toFileString() {
       stringstream ss;
       ss << SystemEvent::toFileString() << "," << fileName << "," << operationType;
       return ss.str();
       
   }
   
   // these will be the getter functions (Members)
   string FileEvent::getFileName() { 
       return fileName;

   }
   string FileEvent::getOperationType() {
       return operationType;
   }

  
  
