#include <iostream>
#include <string>
#include <fstream>
#include "Data.h"
#include "adminPresentation.h"
#include "studentPresentation.h"

using namespace std;

void emailMenu()
{
    ofstream myfile("email.txt", ios::app);
    ifstream myFile("currentAcc.txt", ios::in);
    EMAIL name, description;
    string nothing, line;
    int choose;

    system("cls");

    cout << "                    +------------------------------------------------------+" << endl;
    cout << "                    |                                                      |" << endl;
    cout << "                    |                         Email                        |" << endl;
    cout << "                    |                                                      |" << endl;
    cout << "                    +------------------------------------------------------+" << endl;

    getline(cin, nothing);
    cout << "\n                                 Enter your name: "; getline(cin, name.name);

    if (myFile.is_open())
    {
        while (getline(myFile, line))
        {
        }
        myFile.close();
    }

    while (line != name.name)
    {
        cout << "\n                         Invalid name, try again!"; getline(cin, name.name);
    }

    cout << "\n                                 Enter a description: "; getline(cin, description.description);

    myfile << name.name << "," << description.description << "," << endl;

    cout << "                              Type 1 to back: ";
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
        system("cls");
        scrumMasterMenu();
        break;
    }
}

void viewEmails()
{
    ifstream myFile("email.txt");
    STUDENT students;
    int choose;
    string line, tokens[7], help;

    cout << "\n     +------------------------------------------------------+" << endl;
    cout << "     |                                                      |" << endl;
    cout << "     |                         Emails                       |" << endl;
    cout << "     |                                                      |" << endl;
    cout << "     +------------------------------------------------------+" << endl << endl;

    cout << "                From:          Descriptions:" << endl << endl;

    if (myFile.is_open())
    {
        while (myFile.good())
        {
            getline(myFile, tokens[0]);

            tokenize(tokens[0], tokens, ',');

            help = tokens[0];

            if (help == "") {}
            else
            {
                if (help[0] == '\n')
                {
                    help.erase(0, 1);
                }
                cout << "   Email:    " << tokens[0] << "    " << tokens[1] << endl << endl;
            }
        }
    }

    cout << "                               Type 1 to back: ";
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
        system("cls");
        adminMenu();
        break;
    }
}