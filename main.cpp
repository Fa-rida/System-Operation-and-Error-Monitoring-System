#include <iostream>
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
        cout << "\n --- SELTS MENU ---" << endl;
        cout << "1. View All Events" << endl;
        cout << "2. Generate Summary" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                logManager.viewAllEvents();
                break;

            case 2:
                logManager.generateSummary();
                break;

            case 3:
                cout << "Exiting program..." << endl;
                break;

            default:
                cout << "Invalid choice" << endl;
        }

    } while(choice != 3);

    return 0;
}