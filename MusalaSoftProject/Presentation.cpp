#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#include "Data.h"
#include "Presentation.h"
#include "Struct.h"

using namespace std;

void mainMenu()
{
	int choice;

    cout << "+------------------------------------------------------+" << endl;
    cout << "|                                                      |" << endl;
    cout << "|                        PGKPI                         |" << endl;
    cout << "|                                                      |" << endl;
    cout << "+------------------------------------------------------+" << endl;
    cout << "|                                                      |" << endl;
    cout << "|     Please, select a option from the ones below:     |" << endl;
    cout << "|                                                      |" << endl;
    cout << "|                                                      |" << endl;
    cout << "|                                                      |" << endl;
    cout << "|                      1. Login                        |" << endl;
    cout << "|                                                      |" << endl;
    cout << "|                      2. Register                     |" << endl;
    cout << "|                                                      |" << endl;
    cout << "|                      9. Exit                         |" << endl;
    cout << "|                                                      |" << endl;
    cout << "|                                                      |" << endl;
    cout << "+------------------------------------------------------+" << endl;

    cout << "              Enter your selection:"; cin >> choice;
	
    switch (choice) 
    {
       case 1: loginMenu();
            break;

       case 2: registerMenu();
            break;

       case 9:
            break; 
    }


    while (choice != 1 && choice != 2 && choice != 9)
    {
        cout << "              Invalid input, try again:"; cin >> choice;
    }
}

void loginMenu()
{
    STUDENT username, password;
    string result = "invalidAccount";
    char choice;
    int choose;

    system("cls");

    cout << "\n               Do you have an account?" << endl;
	cout << "                 Y/N: "; cin >> choice;

    while (choice != 'Y' && choice != 'N')
    {
        cout << "Invalid input, try again: "; cin >> choice;
    }

    if (choice == 'Y')
    {
        cout << "+------------------------------------------------------+" << endl;
        cout << "|                                                      |" << endl;
        cout << "|                         Login                        |" << endl;
        cout << "|                                                      |" << endl;
        cout << "+------------------------------------------------------+" << endl;
        cout << "|                                                      |" << endl;
        cout << "|            Please, enter your account data:          |" << endl;
        cout << "|                                                      |" << endl;
        cout << "+------------------------------------------------------+" << endl << endl;
        cout << "                  Enter your name: ";
        cin >> username.name;
        cout << endl;
        cout << "                  Enter your password: ";
        cin >> password.password;
        cout << endl;
        result = checkAcc(username, password);

        while (result == "invalidAccount")
        {
            cout << "                  Enter your name: ";
            cin >> username.name;
            cout << endl;
            cout << "                  Enter your password: ";
            cin >> password.password;
            cout << endl;
            result = checkAcc(username, password);
        }

        /*
        if (checkAcc(username, password) == "1") // check the account
		{
            
		}
		*/
		cout << endl;

    }else
    {
        system("cls");

        cout << "\n                                 If you don't have an account, back to register!" << endl;
		cout << "                                              Type 1 to back: "; 
		while (!(cin >> choose))
		{
			cout << "\n                             Not an integer, please try again: "; cin >> choose;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}

		while (choose != 1)
		{
			cout << "\n                                      Invalid input, try again: "; 
			while (!(cin >> choose))
			{
				cout << "\n                             Not an integer, please try again: "; cin >> choose;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
		}

		switch (choose)
		{
			case 1: mainMenu();
				break;
		}
    }
}

void registerMenu()
{
    STUDENT username, password, surname, classname, email, role;
    string c_password;
    ofstream myFile;
    int id = 0;
    myFile.open("students.txt", ios::app);

    system("cls");

    cout << "+------------------------------------------------------+" << endl;
    cout << "|                                                      |" << endl;
    cout << "|                       Register                       |" << endl;
    cout << "|                                                      |" << endl;
    cout << "+------------------------------------------------------+" << endl;
    cout << "|                                                      |" << endl;
    cout << "|            Please, enter your account data:          |" << endl;
    cout << "|                                                      |" << endl;
    cout << "+------------------------------------------------------+" << endl << endl;
    cout << "                   Enter your name: ";
    cin >> username.name;

    cout << "                   Enter your surname: ";
    cin >> username.surname;

    cout << "                   Enter your password: ";
    cin >> password.password;

    cout << "                   Enter your class" << endl;
    cout << "                   Example - 10A: ";
    cin >> classname.classname;

    cout << "                   Enter your email: ";
    cin >> email.email;
    cout << endl;

    cout << "                   Choose your role between:           " << endl << endl;
    cout << "                    1. Back-end                        " << endl;
    cout << "                    2. Front-end                       " << endl;
    cout << "                    3. Scrum Master                    " << endl;
    cout << "                    4. QA engineer                     " << endl;
    cout << "                    Type your choice: ";
    getline(cin, role.role);
    cout << endl;

    while (role.role != "Back-end" && role.role != "Front-end" && role.role != "Scrum Master" && role.role != "QA engineer")
    {
        cin.clear();
        cout << "        Invalid input, please try again: "; getline(cin, role.role);
    }
    
    if(role.role == "Scrum Master")
    {
        id = 1;
    }

    myFile << username.name << "," << username.surname << "," << password.password << ","  << classname.classname << "," << email.email << "," << role.role << "," << id << "," << endl;
    myFile.close();
}