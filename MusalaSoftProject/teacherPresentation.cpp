#include <iostream>
#include <fstream>
#include <string>
#include "Data.h"
#include "Presentation.h"
#include "teamData.h"

using namespace std;

void teacherMenu()
{
    int teacherChoice;
    string line;
    ifstream myfile;
    myfile.open("currentAcc.txt", ios::in);

    cout << "                    +------------------------------------------------------+" << endl;
    cout << "                    |                                                      |" << endl;
    cout << "                    |                        TEACHER                       |" << endl;
    cout << "                    |                                                      |" << endl;
    cout << "                    +------------------------------------------------------+" << endl;
    cout << "                    |                                                      |" << endl;
    cout << "                    |     Please, select a option from the ones below:     |" << endl;
    cout << "                    |                                                      |" << endl;
    cout << "                    |                                                      |" << endl;
    cout << "                    |               1. Check the teams you are in          |" << endl;
    cout << "                    |                                                      |" << endl;
    cout << "                    |               9. Back                                |" << endl;
    cout << "                    |                                                      |" << endl;
    cout << "                    +------------------------------------------------------+" << endl;

    cout << "\n                                   Enter your selection: ";
    while (!(cin >> teacherChoice))
    {
        cout << "\n                       Not an integer, try again: "; cin >> teacherChoice;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    while (teacherChoice != 1 && teacherChoice != 9)
    {
        cout << "                       Invalid input, try again:";
        while (!(cin >> teacherChoice))
        {
            cout << "\n                          Not an integer, try again: "; cin >> teacherChoice;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    switch (teacherChoice)
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

    case 9:
        mainMenu();
        break;
    }
}

void teacherRegisterMenu()
{
    TEACHER name, surname, date, email, id, password;
    int choose;
    ofstream myFile;
    myFile.open("teachers.txt", ios::app);

    system("cls");

    cout << "                    +------------------------------------------------------+" << endl;
    cout << "                    |                                                      |" << endl;
    cout << "                    |                       Register                       |" << endl;
    cout << "                    |                                                      |" << endl;
    cout << "                    +------------------------------------------------------+" << endl;
    cout << "                    |                                                      |" << endl;
    cout << "                    |            Please, enter your account data:          |" << endl;
    cout << "                    |                                                      |" << endl;
    cout << "                    +------------------------------------------------------+" << endl << endl;

    cout << "                                         Name: ";
    cin >> name.name;

    cout << "\n                                         Surname: ";
    cin >> surname.surname;

    cout << "\n                      !!!Your password MUST be between 5 and 10 symbols!!!" << endl;
    cout << "                                         Password: ";
    cin >> password.password;

    while (password.password.length() > 10 || password.password.length() < 5)
    {
        cout << "\n                           Invalid input, please try again: "; cin >> password.password;
    }

    cout << "\n                                         Email: ";
    cin >> email.email;

    while (!isEmailValid(email.email.c_str()))
    {
        cout << "\n                           Invalid email, try again: "; cin >> email.email;
    }
    cout << endl;

    id.id = "4";

    myFile << name.name << "," << surname.surname << "," << email.email << "," << id.id << "," << endl;
    myFile.close();

    cout << "\n                              Type 1 to back: ";
    while (!(cin >> choose))
    {
        cout << "\n                        Not an integer, please try again: "; cin >> choose;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    while (choose != 1)
    {
        cout << "\n                             Invalid input, try again: ";
        while (!(cin >> choose))
        {
            cout << "\n                     Not an integer, please try again: "; cin >> choose;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    switch (choose)
    {
    case 1:
        mainMenu();
        break;
    }
}