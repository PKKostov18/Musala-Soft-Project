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

    system("cls");

    cout << "                    +------------------------------------------------------+" << endl;
    cout << "                    |                                                      |" << endl;
    cout << "                    |                        PGKPI                         |" << endl;
    cout << "                    |                                                      |" << endl;
    cout << "                    +------------------------------------------------------+" << endl;
    cout << "                    |                                                      |" << endl;
    cout << "                    |     Please, select a option from the ones below:     |" << endl;
    cout << "                    |                                                      |" << endl;
    cout << "                    |                                                      |" << endl;
    cout << "                    |                                                      |" << endl;
    cout << "                    |                      1. Login                        |" << endl;
    cout << "                    |                                                      |" << endl;
    cout << "                    |                      2. Register                     |" << endl;
    cout << "                    |                                                      |" << endl;
    cout << "                    |                      9. Exit                         |" << endl;
    cout << "                    |                                                      |" << endl;
    cout << "                    |                                                      |" << endl;
    cout << "                    +------------------------------------------------------+" << endl;

    cout << "                                   Enter your selection: "; 
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
       case 1: loginMenu();
            break;

       case 2: registerMenu();
            break;

       case 9:
            break; 
    }
}

void loginMenu()
{
    STUDENT username, password;
    string result = "invalidAccount";
    char choice;
    int choose;

    system("cls");

    cout << "\n                                      Do you have an account?" << endl;
	cout << "                                                 Y/N: "; cin >> choice;

    while (choice != 'Y' && choice != 'N')
    {
        cout << "                                Invalid input, try again: "; cin >> choice;
    }

    if (choice == 'Y')
    {
        system("cls");

        while (result == "invalidAccount")
        {
            
            cout << "                    +------------------------------------------------------+" << endl;
            cout << "                    |                                                      |" << endl;
            cout << "                    |                         Login                        |" << endl;
            cout << "                    |                                                      |" << endl;
            cout << "                    +------------------------------------------------------+" << endl;
            cout << "                    |                                                      |" << endl;
            cout << "                    |            Please, enter your account data:          |" << endl;
            cout << "                    |                                                      |" << endl;
            cout << "                    +------------------------------------------------------+" << endl << endl;
            cout << "                                     Enter your name: ";
            cin >> username.name;
            cout << endl;
            cout << "                                     Enter your password: ";
            cin >> password.password;
            cout << endl;
            result = checkAcc(username, password);
        }

        if (checkAcc(username, password) == "Please try to login again!") 
        {
            loginMenu();
        }
        else
        {
           
        }
		cout << endl;

    }else
    {
        system("cls");

        cout << "\n                        If you don't have an account, back to register!" << endl;
		cout << "                                         Type 1 to back: "; 
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

    cout << "                    +------------------------------------------------------+" << endl;
    cout << "                    |                                                      |" << endl;
    cout << "                    |                       Register                       |" << endl;
    cout << "                    |                                                      |" << endl;
    cout << "                    +------------------------------------------------------+" << endl;
    cout << "                    |                                                      |" << endl;
    cout << "                    |            Please, enter your account data:          |" << endl;
    cout << "                    |                                                      |" << endl;
    cout << "                    +------------------------------------------------------+" << endl << endl;

    cout << "                                   Enter your name: ";
    cin >> username.name;

    cout << "                                   Enter your surname: ";
    cin >> username.surname;

    cout << "\n                      !!!Your password MUST be between 5 and 10 symbols!!!" << endl;
    cout << "                                   Enter your password: ";
    cin >> password.password;

    while (password.password.length() > 10 || password.password.length() < 5)
    {
        cout << "\n                           Invalid input, please try again: "; cin >> password.password;
        
    }
    cout << endl;

    cout << "                                   Enter your class" << endl;
    cout << "                                   Example - 10A: ";
    cin >> classname.classname;

    isClassnameValid(classname.classname);

    cout << "                                   Enter your email: ";
    cin >> email.email;

    while (!isEmailValid(email.email.c_str()))
    {
        cout << "\n                           Invalid email, try again: "; cin >> email.email;
    }
    cout << endl;

    cout << "                                Choose your role between:           " << endl << endl;
    cout << "                                     1. Back-end                        " << endl;
    cout << "                                     2. Front-end                       " << endl;
    cout << "                                     3. Scrum Master                    " << endl;
    cout << "                                     4. QA engineer                     " << endl;
    cout << "                                   Type your choice: ";
    getline(cin, role.role);
    cout << endl;

    while (role.role != "Back-end" && role.role != "Front-end" && role.role != "Scrum Master" && role.role != "QA engineer")
    {
        cout << "                         Invalid input, please try again: "; getline(cin, role.role);
        cin.clear();
    }
    
    if(role.role == "Scrum Master")
    {
        id = 1;
    }

    myFile << username.name << "," << username.surname << "," << password.password << ","  << classname.classname << "," << email.email << "," << role.role << "," << id << "," << endl;
    myFile.close();
}