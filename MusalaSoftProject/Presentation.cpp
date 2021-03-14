#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#include "Data.h"
#include "teacherPresentation.h"
#include "adminData.h"
#include "studentData.h"
#include "teacherData.h"
#include "Presentation.h"

using namespace std;

void mainMenu() //a menu function for the main menu
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

    cout << "\n                                   Enter your selection: "; 
    while (!(cin >> choice)) //check if the value is integer
    {
        cout << "\n                       Not an integer, try again: "; cin >> choice;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    
    while (choice != 1 && choice != 2 && choice != 9) //check if the input is in range
    {
        cout << "                       Invalid input, try again:"; 
        while (!(cin >> choice)) //check if the value is integer
        { 
            cout << "\n                          Not an integer, try again: "; cin >> choice;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
	
    switch (choice) //switch case for the choice 
    {
       case 1: loginMenu();
            break;

       case 2: registerMenu();
            break;

       case 9:
            break; 
    }
}

void loginMenu() //a menu function for the login
{
    ofstream myfile;
    myfile.open("currentAcc.txt", ios::out);
    STUDENT username, password, id;
    string result = "invalidAccount", result1 = "invalidAccount";
    char choice;
    int choose;

    system("cls");

    cout << "\n                                      Do you have an account?" << endl;
	cout << "                                                 Y/N: "; cin >> choice;

    while (choice != 'Y' && choice != 'N') //check if the answer is in range (Y or N)
    {
        cout << "                                Invalid input, try again: "; cin >> choice;
    }

    if (choice == 'Y') //if the user have an account displays a menu for the user to log in
    {
        system("cls");

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
        
        myfile << username.name;
        myfile.close();

        while (checkAccStudentsId(username, password) == false && checkAccTeachersId(username, password) == false && checkAccAdminId(username, password) == false) //check if the account data is not valid
        {
            cout << "\n                       Invalid account, please try to login again!\n" << endl;

            cout << "                                     Enter your name: ";
            cin >> username.name;
            cout << endl;
            cout << "                                     Enter your password: ";
            cin >> password.password;
            cout << endl;
        } 
        
    }
    else //if the user do not have an account
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

		while (choose != 1) //check if the value is in range (1)
		{
			cout << "\n                             Invalid input, try again: "; 
			while (!(cin >> choose)) //check if the value is integer
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

void registerMenu() //a menu function for the registration
{
    STUDENT username, password, surname, classname, email, role, id, status;
    string c_password;
    ofstream myFile;
    int choice, choose;
    myFile.open("students.txt", ios::app);

    system("cls");

    cout << "\n                                Like what you want to register? " << endl;
    cout << "\n                                         1. Student " << endl;
    cout << "                                         2. Teacher " << endl;
    cout << "\n                                           Choose: "; 

    while (!(cin >> choice)) //check if the value is integer
    {
        cout << "\n                       Not an integer, try again: "; cin >> choice;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    while (choice != 1 && choice != 2) //check if the value is in range (1 or 2)
    {
        cout << "                          Invalid input, try again:";
        while (!(cin >> choice)) //check if the value is integer
        {
            cout << "\n                            Not an integer, try again: "; cin >> choice;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    if (choice == 1) //if you choose to be a student register menu for students opens
    {
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

        cout << "                                   Enter your name: "; //registering your name
        cin >> username.name;

        cout << "                                   Enter your surname: "; //registering your surname
        cin >> username.surname;

        cout << "\n                      !!!Your password MUST be between 5 and 10 symbols!!!" << endl;
        cout << "                                   Enter your password: "; //registering your password
        cin >> password.password;

        while (password.password.length() > 10 || password.password.length() < 5) //check if the password is between 5 and 10 symbols
        {
            cout << "\n                           Invalid input, please try again: "; cin >> password.password;
        }
        cout << endl;

        cout << "                                   Enter your class" << endl; //registering your class
        cout << "                                   Example - 10A: ";
        cin >> classname.classname;

        isClassnameValid(classname.classname);

        cout << "                                   Enter your email: "; //registering your email
        cin >> email.email;

        while (!isEmailValid(email.email.c_str())) //check if the email is valid
        {
            cout << "\n                           Invalid email, try again: "; cin >> email.email;
        }
        cout << endl;

        cout << "                                Choose your role between:           " << endl << endl; //choosing your role
        cout << "                                     1. Back-end                        " << endl;
        cout << "                                     2. Front-end                       " << endl;
        cout << "                                     3. Scrum Master                    " << endl;
        cout << "                                     4. QA engineer                     " << endl;
        cout << "                                   Type your choice: ";
        getline(cin, role.role);
        cout << endl;

        while (role.role != "Back-end" && role.role != "Front-end" && role.role != "Scrum Master" && role.role != "QA engineer") //check if the role is correct
        {
            cout << "                         Invalid input, please try again: "; getline(cin, role.role);
            cin.clear();
        }

        if (role.role == "Scrum Master") //if your role is scrum master your id changes to 0
        {
            id.id = "0";
        }
        else if (role.role == "Front-end") //if your role is Front-end your id changes to 1
        {
            id.id = "1";
        }
        else if (role.role == "Back-end") //if your role is Back-end your id changes to 2
        {
            id.id = "2";
        }
        else if (role.role == "QA engineer") //if your role is QA engineer your id changes to 3
        {
            id.id = "3";
        }

        status.status = "notuse";
        myFile << username.name << "," << username.surname << "," << password.password << "," << classname.classname << "," << email.email << "," << role.role << "," << id.id << "," << status.status << "," << endl;
        myFile.close();
    }
    else if (choice == 2)
    {
        teacherRegisterMenu();
    }
}