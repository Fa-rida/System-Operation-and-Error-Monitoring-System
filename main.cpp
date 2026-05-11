#include <iostream>
#include <string>

#include "LogManager.h"
#include "SystemManager.h"

using namespace std;

int main()
{
    LogManager logManager;
    SystemManager systemManager(&logManager);

    int choice;

    do
    {
        cout << "\n --- WELCOME TO THE SYSTEM OPERATION AND ERROR MONITORING SYSTEM MENU. PLEASE SELECT AN OPTION FROM THE MENU ---" << endl;

        cout << "1. Login Attempt" << endl;
        cout << "2. Load File" << endl;
        cout << "3. Save File" << endl;
        cout << "4. Shutdown System" << endl;
        cout << "5. View All Events" << endl;
        cout << "6. Search By Event ID" << endl;
        cout << "7. Search By User ID" << endl;
        cout << "8. Filter By Event Type" << endl;
        cout << "9. Filter By Severity" << endl;
        cout << "10. Generate Summary" << endl;
        cout << "11. Load From File" << endl;
        cout << "12. Save to File" << endl;
        cout << "13. Exit" << endl;
        
        cout << "Enter choice: ";
        cin >> choice;

        switch(choice)
        {
             case 1:
            {
                string userID;
                string password;

                cout << "Enter User ID: ";
                cin >> userID;

                cout << "Enter Password: ";
                cin >> password;

                systemManager.login(userID, password);

                break;
            }

            case 2:
            {
                string fileName;

                cout << "Enter file name to load: ";
                cin >> fileName;

                systemManager.loadFile(fileName);

                break;
            }

            case 3:
            {
                string fileName;

                cout << "Enter file name to save: ";
                cin >> fileName;

                systemManager.saveFile(fileName);

                break;
            }

            case 4:
            {
                systemManager.shutdownSystem();
                break;
            }

            case 5:
            {
                logManager.viewAllEvents();
                break;
            }

            case 6:
            {
                string eventID;

                cout << "Enter Event ID: ";
                cin >> eventID;

                logManager.searchByEventID(eventID);

                break;
            }

            case 7:
            {
                string userID;

                cout << "Enter User ID: ";
                cin >> userID;

                logManager.searchByUserID(userID);

                break;
            }

            case 8:
            {
                string type;

                cout << "Enter Event Type (Login/File/Shutdown): ";
                cin >> type;

                logManager.filterByType(type);

                break;
            }

            case 9:
            {
                string severity;

                cout << "Enter Severity (Safe/Warning/Critical): ";
                cin >> severity;

                logManager.filterBySeverity(severity);

                break;
            }

            case 10:
            {
                logManager.generateSummary();
                break;
            }
            
            case 11:
            {
                string nameFile;
                cout << "Enter the name of the file: ";
                cin >> nameFile;
                
                logManager.loadFromFile(nameFile);
                break;
            }
            
            case 12:
            {
                string nameFile;
                cout << "Enter the name of the file: ";
                cin >> nameFile;
                
                logManager.saveToFile(nameFile);
                
                break;
            }

            case 13:
            {
                cout << "Exiting program..." << endl;
                break;
            }

            default:
            {
                cout << "Invalid choice. Try again." << endl;
            }
        }

    } while(choice != 13);

    return 0;
}
