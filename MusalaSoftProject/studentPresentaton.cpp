#include <iostream>
#include <fstream>
#include <string>
#include "Presentation.h"
#include "teamData.h"
#include "teamPresentation.h"
#include "studentData.h"
#include "emails.h"

using namespace std;

void scrumMasterMenu()
{
    int teamChoice;
    string line;
    ifstream myfile;
    myfile.open("currentAcc.txt", ios::in);

    cout << "                    +------------------------------------------------------+" << endl;
    cout << "                    |                                                      |" << endl;
    cout << "                    |                     SCRUM MASTER                     |" << endl;
    cout << "                    |                                                      |" << endl;
    cout << "                    +------------------------------------------------------+" << endl;
    cout << "                    |                                                      |" << endl;
    cout << "                    |     Please, select a option from the ones below:     |" << endl;
    cout << "                    |                                                      |" << endl;
    cout << "                    |                                                      |" << endl;
    cout << "                    |                    1. Create a team                  |" << endl;
    cout << "                    |                                                      |" << endl;
    cout << "                    |                    2. Check for missing teammate     |" << endl;
    cout << "                    |                                                      |" << endl;
    cout << "                    |                    3. Check your team                |" << endl;
    cout << "                    |                                                      |" << endl;
    cout << "                    |                    4. Email to the admin             |" << endl;
    cout << "                    |                                                      |" << endl;
    cout << "                    |                    9. Log out                        |" << endl;
    cout << "                    |                                                      |" << endl;
    cout << "                    +------------------------------------------------------+" << endl;

    cout << "\n                                   Enter your selection: ";
    while (!(cin >> teamChoice))
    {
        cout << "\n                       Not an integer, try again: "; cin >> teamChoice;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    while (teamChoice != 1 && teamChoice != 2 && teamChoice != 3 && teamChoice != 4 && teamChoice != 9)
    {
        cout << "                       Invalid input, try again:";
        while (!(cin >> teamChoice))
        {
            cout << "\n                          Not an integer, try again: "; cin >> teamChoice;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    switch (teamChoice)
    {
    case 1:
        system("cls");
        teamRegisterMenu();
        break;

    case 2:
        system("cls");
        if (myfile.is_open())
        {
            while (getline(myfile, line))
            {
                checkForMissingMember(line);
            }
            myfile.close();
        }
        break;

    case 3:
        system("cls");
        if (myfile.is_open())
        {
            while (getline(myfile, line))
            {
                displayYourTeam(line);
            }
            myfile.close();
        }
        break;

    case 4:
        system("cls");
        emailMenu();
        break;

    case 9:
        system("cls");
        mainMenu();
        break;
    }
}

void frontEndMenu()
{
    int frontChoice;
    string line;
    ifstream myfile;
    myfile.open("currentAcc.txt", ios::in);

    cout << "                    +------------------------------------------------------+" << endl;
    cout << "                    |                                                      |" << endl;
    cout << "                    |                       FRONT-END                      |" << endl;
    cout << "                    |                                                      |" << endl;
    cout << "                    +------------------------------------------------------+" << endl;
    cout << "                    |                                                      |" << endl;
    cout << "                    |     Please, select a option from the ones below:     |" << endl;
    cout << "                    |                                                      |" << endl;
    cout << "                    |                                                      |" << endl;
    cout << "                    |                 1. Check your team                   |" << endl;
    cout << "                    |                                                      |" << endl;
    cout << "                    |                 2. Check for missing teammate        |" << endl;
    cout << "                    |                                                      |" << endl;
    cout << "                    |                 9. Log out                           |" << endl;
    cout << "                    |                                                      |" << endl;
    cout << "                    +------------------------------------------------------+" << endl;

    cout << "\n                                   Enter your selection: ";
    while (!(cin >> frontChoice))
    {
        cout << "\n                       Not an integer, try again: "; cin >> frontChoice;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    while (frontChoice != 1 && frontChoice != 2 && frontChoice != 9)
    {
        cout << "                       Invalid input, try again:";
        while (!(cin >> frontChoice))
        {
            cout << "\n                          Not an integer, try again: "; cin >> frontChoice;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    switch (frontChoice)
    {
    case 1:
        system("cls");
        if (myfile.is_open())
        {
            while (getline(myfile, line))
            {
                displayYourTeam(line);
            }
            myfile.close();
        }
        break;

    case 2:
        system("cls");
        if (myfile.is_open())
        {
            while (getline(myfile, line))
            {
                checkForMissingMember(line);
            }
            myfile.close();
        }
        break;

    case 9:
        mainMenu();
        break;
    }
}

void backEndMenu()
{
    int backChoice;
    string line;
    ifstream myfile;
    myfile.open("currentAcc.txt", ios::in);

    cout << "                    +------------------------------------------------------+" << endl;
    cout << "                    |                                                      |" << endl;
    cout << "                    |                       BACK-END                       |" << endl;
    cout << "                    |                                                      |" << endl;
    cout << "                    +------------------------------------------------------+" << endl;
    cout << "                    |                                                      |" << endl;
    cout << "                    |     Please, select a option from the ones below:     |" << endl;
    cout << "                    |                                                      |" << endl;
    cout << "                    |                                                      |" << endl;
    cout << "                    |                 1. Check your team                   |" << endl;
    cout << "                    |                                                      |" << endl;
    cout << "                    |                 2. Check for missing teammate        |" << endl;
    cout << "                    |                                                      |" << endl;
    cout << "                    |                 9. Log out                           |" << endl;
    cout << "                    |                                                      |" << endl;
    cout << "                    +------------------------------------------------------+" << endl;

    cout << "\n                                   Enter your selection: ";
    while (!(cin >> backChoice))
    {
        cout << "\n                       Not an integer, try again: "; cin >> backChoice;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    while (backChoice != 1 && backChoice != 2 && backChoice != 9)
    {
        cout << "                       Invalid input, try again:";
        while (!(cin >> backChoice))
        {
            cout << "\n                          Not an integer, try again: "; cin >> backChoice;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }


    switch (backChoice)
    {
    case 1:
        system("cls");
        if (myfile.is_open())
        {
            while (getline(myfile, line))
            {
                displayYourTeam(line);
            }
            myfile.close();
        }
        break;

    case 2:
        system("cls");
        if (myfile.is_open())
        {
            while (getline(myfile, line))
            {
                checkForMissingMember(line);
            }
            myfile.close();
        }
        break;

    case 9:
        mainMenu();
        break;
    }
}

void QAEngineerMenu()
{
    int QAChoice;
    string line;
    ifstream myfile;
    myfile.open("currentAcc.txt", ios::in);

    cout << "                    +------------------------------------------------------+" << endl;
    cout << "                    |                                                      |" << endl;
    cout << "                    |                      QA ENGINEER                     |" << endl;
    cout << "                    |                                                      |" << endl;
    cout << "                    +------------------------------------------------------+" << endl;
    cout << "                    |                                                      |" << endl;
    cout << "                    |     Please, select a option from the ones below:     |" << endl;
    cout << "                    |                                                      |" << endl;
    cout << "                    |                                                      |" << endl;
    cout << "                    |                 1. Check your team                   |" << endl;
    cout << "                    |                                                      |" << endl;
    cout << "                    |                 3. Check for missing teammate        |" << endl;
    cout << "                    |                                                      |" << endl;
    cout << "                    |                 9. Log out                           |" << endl;
    cout << "                    |                                                      |" << endl;
    cout << "                    +------------------------------------------------------+" << endl;

    cout << "\n                                   Enter your selection: ";
    while (!(cin >> QAChoice))
    {
        cout << "\n                       Not an integer, try again: "; cin >> QAChoice;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    while (QAChoice != 1 && QAChoice != 2 && QAChoice != 3 && QAChoice != 9)
    {
        cout << "                       Invalid input, try again:";
        while (!(cin >> QAChoice))
        {
            cout << "\n                          Not an integer, try again: "; cin >> QAChoice;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }


    switch (QAChoice)
    {
    case 1:
        system("cls");
        if (myfile.is_open())
        {
            while (getline(myfile, line))
            {
                displayYourTeam(line);
            }
            myfile.close();
        }
        break;

    case 2:
        system("cls");
        break;

    case 3:
        system("cls");
        if (myfile.is_open())
        {
            while (getline(myfile, line))
            {
                checkForMissingMember(line);
            }
            myfile.close();
        }
        break;

    case 9:
        mainMenu();
        break;
    }
}