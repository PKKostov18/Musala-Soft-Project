#include <iostream>
#include <fstream>
#include <string>
#include "Presentation.h"
#include "emails.h"
#include "adminData.h"
#include "adminPresentation.h"
#include "studentData.h"
#include "teacherData.h"
#include "teamData.h"

using namespace std;

void adminMenu()
{
    int adminChoice;

    cout << "                    +------------------------------------------------------+" << endl;
    cout << "                    |                                                      |" << endl;
    cout << "                    |                         ADMIN                        |" << endl;
    cout << "                    |                                                      |" << endl;
    cout << "                    +------------------------------------------------------+" << endl;
    cout << "                    |                                                      |" << endl;
    cout << "                    |     Please, select a option from the ones below:     |" << endl;
    cout << "                    |                                                      |" << endl;
    cout << "                    |                                                      |" << endl;
    cout << "                    |                   1. Manage accounts                 |" << endl;
    cout << "                    |                                                      |" << endl;
    cout << "                    |                   2. Manage teams                    |" << endl;
    cout << "                    |                                                      |" << endl;
    cout << "                    |                   3. School                          |" << endl;
    cout << "                    |                                                      |" << endl;
    cout << "                    |                   4. Inbox                           |" << endl;
    cout << "                    |                                                      |" << endl;
    cout << "                    |                   9. Log out                         |" << endl;
    cout << "                    |                                                      |" << endl;
    cout << "                    +------------------------------------------------------+" << endl;

    cout << "\n                                   Enter your selection: ";
    while (!(cin >> adminChoice))
    {
        cout << "\n                       Not an integer, try again: "; cin >> adminChoice;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    while (adminChoice != 1 && adminChoice != 2 && adminChoice != 3 && adminChoice != 4 && adminChoice != 9)
    {
        cout << "                       Invalid input, try again:";
        while (!(cin >> adminChoice))
        {
            cout << "\n                          Not an integer, try again: "; cin >> adminChoice;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    switch (adminChoice)
    {
    case 1:
        system("cls");
        manageAccountsMenu();
        break;

    case 2:
        system("cls");
        manageTeamsMenu();
        break;

    case 3:
        system("cls");
        viewMenu();
        break;

    case 4:
        system("cls");
        viewEmails();
        break;

    case 9:
        mainMenu();
        break;
    }
}

void viewMenu()
{
    int viewChoose;

    system("cls");

    cout << "                    +------------------------------------------------------+" << endl;
    cout << "                    |                                                      |" << endl;
    cout << "                    |                         View                         |" << endl;
    cout << "                    |                                                      |" << endl;
    cout << "                    +------------------------------------------------------+" << endl;
    cout << "                    |                                                      |" << endl;
    cout << "                    |             Choose which you want to see:            |" << endl;
    cout << "                    |                                                      |" << endl;
    cout << "                    |                1. List of all students               |" << endl;
    cout << "                    |                                                      |" << endl;
    cout << "                    |                2. List of all teachers               |" << endl;
    cout << "                    |                                                      |" << endl;
    cout << "                    |                3. List of all teams                  |" << endl;
    cout << "                    |                                                      |" << endl;
    cout << "                    |                4. Reports                            |" << endl;
    cout << "                    |                                                      |" << endl;
    cout << "                    |                5. School information                 |" << endl;
    cout << "                    |                                                      |" << endl;
    cout << "                    |                9. Back                               |" << endl;
    cout << "                    |                                                      |" << endl;
    cout << "                    +------------------------------------------------------+" << endl;

    cout << "                                   Enter your selection: ";
    while (!(cin >> viewChoose))
    {
        cout << "\n                       Not an integer, try again: "; cin >> viewChoose;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    while (viewChoose != 1 && viewChoose != 2 && viewChoose != 3 && viewChoose != 4 && viewChoose != 9)
    {
        cout << "                       Invalid input, try again:";
        while (!(cin >> viewChoose))
        {
            cout << "\n                          Not an integer, try again: "; cin >> viewChoose;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    switch (viewChoose)
    {
    case 1:
        system("cls");
        displayStudents();
        break;

    case 2:
        system("cls");
        displayTeachers();
        break;

    case 3:
        system("cls");
        displayTeams();
        break;

    case 4:
        system("cls");
        reports();
        break;

    case 5:
        system("cls");
        break;

    case 9:
        system("cls");
        adminMenu();
        break;
    }
}

void reports()
{
    int choose;

    system("cls");

    cout << "                    +-----------------------------------------------------------------+" << endl;
    cout << "                    |                                                                 |" << endl;
    cout << "                    |                             Reports                             |" << endl;
    cout << "                    |                                                                 |" << endl;
    cout << "                    +-----------------------------------------------------------------+" << endl;
    cout << "                    |                                                                 |" << endl;
    cout << "                    |                  Choose which you want to see:                  |" << endl;
    cout << "                    |                                                                 |" << endl;
    cout << "                    |                                                                 |" << endl;
    cout << "                    | 1. A list of the students who participate in a particular team  |" << endl;
    cout << "                    |                                                                 |" << endl;
    cout << "                    | 2. A list of the teachers who do not have an allocated team     |" << endl;
    cout << "                    |                                                                 |" << endl;
    cout << "                    | 3. A list of the teams which are not full of four students      |" << endl;
    cout << "                    |                                                                 |" << endl;
    cout << "                    |                             9. Back                             |" << endl;
    cout << "                    |                                                                 |" << endl;
    cout << "                    +-----------------------------------------------------------------+" << endl;

    cout << "                                          Enter your selection: ";
    while (!(cin >> choose))
    {
        cout << "\n                               Not an integer, try again: "; cin >> choose;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    while (choose != 1 && choose != 2 && choose != 3 && choose != 9)
    {
        cout << "                               Invalid input, try again:";
        while (!(cin >> choose))
        {
            cout << "\n                               Not an integer, try again: "; cin >> choose;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    switch (choose)
    {
    case 1:
        system("cls");
        break;

    case 2:
        system("cls");
        break;

    case 3:
        system("cls");
        break;

    case 9:
        system("cls");
        adminMenu();
        break;
    }
}

void manageAccountsMenu()
{
    int choice;

    system("cls");

    cout << "                    +------------------------------------------------------+" << endl;
    cout << "                    |                                                      |" << endl;
    cout << "                    |                    Manage accounts                   |" << endl;
    cout << "                    |                                                      |" << endl;
    cout << "                    +------------------------------------------------------+" << endl;
    cout << "                    |                                                      |" << endl;
    cout << "                    |     Please, select a option from the ones below:     |" << endl;
    cout << "                    |                                                      |" << endl;
    cout << "                    |                   1. Delete account                  |" << endl;
    cout << "                    |                                                      |" << endl;
    cout << "                    |                   2. Edit account password           |" << endl;
    cout << "                    |                                                      |" << endl;
    cout << "                    |                   9. Back                            |" << endl;
    cout << "                    |                                                      |" << endl;
    cout << "                    +------------------------------------------------------+" << endl;

    cout << "\n                                   Enter your selection: ";
    while (!(cin >> choice))
    {
        cout << "\n                       Not an integer, try again: "; cin >> choice;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    while (choice != 1 && choice != 2 && choice != 9)
    {
        cout << "                       Invalid input, try again:";
        while (!(cin >> choice))
        {
            cout << "\n                          Not an integer, try again: "; cin >> choice;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    switch (choice)
    {
    case 1:
        system("cls");
        deleteAccount();
        break;

    case 2:
        system("cls");
        editPassword();
        break;

    case 9:
        system("cls");
        adminMenu();
        break;
    }
}

void manageTeamsMenu()
{
    int choice;

    system("cls");

    cout << "                    +------------------------------------------------------+" << endl;
    cout << "                    |                                                      |" << endl;
    cout << "                    |                      Manage teams                    |" << endl;
    cout << "                    |                                                      |" << endl;
    cout << "                    +------------------------------------------------------+" << endl;
    cout << "                    |                                                      |" << endl;
    cout << "                    |     Please, select a option from the ones below:     |" << endl;
    cout << "                    |                                                      |" << endl;
    cout << "                    |                   1. Delete team                     |" << endl;
    cout << "                    |                                                      |" << endl;
    cout << "                    |                   2. Edit team name                  |" << endl;
    cout << "                    |                                                      |" << endl;
    cout << "                    |                   3. Edit team status                |" << endl;
    cout << "                    |                                                      |" << endl;
    cout << "                    |                   9. Back                            |" << endl;
    cout << "                    |                                                      |" << endl;
    cout << "                    +------------------------------------------------------+" << endl;

    cout << "\n                                   Enter your selection: ";
    while (!(cin >> choice))
    {
        cout << "\n                       Not an integer, try again: "; cin >> choice;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    while (choice != 1 && choice != 2 && choice != 3 && choice != 9)
    {
        cout << "                       Invalid input, try again:";
        while (!(cin >> choice))
        {
            cout << "\n                          Not an integer, try again: "; cin >> choice;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    switch (choice)
    {
    case 1:
        system("cls");
        deleteTeams();
        break;

    case 2:
        system("cls");
        editTeamName();
        break;

    case 3:
        system("cls");
        editTeamStatus();
        break;

    case 9:
        system("cls");
        adminMenu();
        break;
    }
}