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
    STUDENT username, password, id;
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

        //while (result == "invalidAccount")
        //{
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

           // result = checkAcc(username, password);
       // }
     
           // checkAccId(id, username);

       
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
    STUDENT username, password, surname, classname, email, role, id;
    string c_password;
    ofstream myFile;
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
        id.id = "0";
    }else if (role.role == "Front-end")
    {
        id.id = "1";
    }else if (role.role == "Back-end")
    {
        id.id = "2";
    }else if (role.role == "QA engineer")
    {
        id.id = "3";
    }

    myFile << username.name << "," << username.surname << "," << password.password << ","  << classname.classname << "," << email.email << "," << role.role << "," << id.id << "," << endl;
    myFile.close();
}

void scrumMasterMenu()
{
    int teamChoice;

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
    cout << "                    |                    2. Check your team                |" << endl;
    cout << "                    |                                                      |" << endl;
    cout << "                    |                    3. Email to the admin             |" << endl;
    cout << "                    |                                                      |" << endl;
    cout << "                    |                    4. Email your teammates           |" << endl;
    cout << "                    |                                                      |" << endl;
    cout << "                    |                    9. Back                           |" << endl;
    cout << "                    |                                                      |" << endl;
    cout << "                    +------------------------------------------------------+" << endl;

    cout << "                                   Enter your selection: "; 
    while (!(cin >> teamChoice))
    {
        cout << "\n                       Not an integer, try again: "; cin >> teamChoice;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    while (teamChoice != 1 && teamChoice != 2 && teamChoice != 3 && teamChoice != 9)
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
    case 1: ;
        break;

    case 2: ;
        break;

    case 3: ;
        break;

    case 4:;
        break;

    case 9:
        mainMenu();
        break;
    }
}

void frontEndMenu()
{
    int frontChoice;

    cout << "                    +------------------------------------------------------+" << endl;
    cout << "                    |                                                      |" << endl;
    cout << "                    |                       FRONT-END                      |" << endl;
    cout << "                    |                                                      |" << endl;
    cout << "                    +------------------------------------------------------+" << endl;
    cout << "                    |                                                      |" << endl;
    cout << "                    |     Please, select a option from the ones below:     |" << endl;
    cout << "                    |                                                      |" << endl;
    cout << "                    |                                                      |" << endl;
    cout << "                    |                                                      |" << endl;
    cout << "                    |                 1. Check your team                   |" << endl;
    cout << "                    |                                                      |" << endl;
    cout << "                    |                 2. Email to the Scrum Master         |" << endl;
    cout << "                    |                                                      |" << endl;
    cout << "                    |                 3. Check your inbox                  |" << endl;
    cout << "                    |                                                      |" << endl;
    cout << "                    |                 9. Back                              |" << endl;
    cout << "                    |                                                      |" << endl;
    cout << "                    +------------------------------------------------------+" << endl;

    cout << "                                   Enter your selection: "; 
    while (!(cin >> frontChoice))
    {
        cout << "\n                       Not an integer, try again: "; cin >> frontChoice;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    while (frontChoice != 1 && frontChoice != 2 && frontChoice != 3 && frontChoice != 9)
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
    case 1:;
        break;

    case 2:;
        break;

    case 3:;
        break;

    case 9:
        mainMenu();
        break;
    }
}

void backEndMenu()
{
    int backChoice;

    cout << "                    +------------------------------------------------------+" << endl;
    cout << "                    |                                                      |" << endl;
    cout << "                    |                       BACK-END                       |" << endl;
    cout << "                    |                                                      |" << endl;
    cout << "                    +------------------------------------------------------+" << endl;
    cout << "                    |                                                      |" << endl;
    cout << "                    |     Please, select a option from the ones below:     |" << endl;
    cout << "                    |                                                      |" << endl;
    cout << "                    |                                                      |" << endl;
    cout << "                    |                                                      |" << endl;
    cout << "                    |                 1. Check your team                   |" << endl;
    cout << "                    |                                                      |" << endl;
    cout << "                    |                 2. Email to the Scrum Master         |" << endl;
    cout << "                    |                                                      |" << endl;
    cout << "                    |                 3. Check your inbox                  |" << endl;
    cout << "                    |                                                      |" << endl;
    cout << "                    |                 9. Back                              |" << endl;
    cout << "                    |                                                      |" << endl;
    cout << "                    +------------------------------------------------------+" << endl;

    cout << "                                   Enter your selection: "; 
    while (!(cin >> backChoice))
    {
        cout << "\n                       Not an integer, try again: "; cin >> backChoice;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    while (backChoice != 1 && backChoice != 2 && backChoice != 3 && backChoice != 9)
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
    case 1:;
        break;

    case 2:;
        break;

    case 3:;
        break;

    case 9:
        mainMenu();
        break;
    }
}

void QAEngineerMenu()
{
    int QAChoice;

    cout << "                    +------------------------------------------------------+" << endl;
    cout << "                    |                                                      |" << endl;
    cout << "                    |                      QA ENGINEER                     |" << endl;
    cout << "                    |                                                      |" << endl;
    cout << "                    +------------------------------------------------------+" << endl;
    cout << "                    |                                                      |" << endl;
    cout << "                    |     Please, select a option from the ones below:     |" << endl;
    cout << "                    |                                                      |" << endl;
    cout << "                    |                                                      |" << endl;
    cout << "                    |                                                      |" << endl;
    cout << "                    |                 1. Check your team                   |" << endl;
    cout << "                    |                                                      |" << endl;
    cout << "                    |                 2. Email to the Scrum Master         |" << endl;
    cout << "                    |                                                      |" << endl;
    cout << "                    |                 3. Check your inbox                  |" << endl;
    cout << "                    |                                                      |" << endl;
    cout << "                    |                 9. Back                              |" << endl;
    cout << "                    |                                                      |" << endl;
    cout << "                    +------------------------------------------------------+" << endl;

    cout << "                                   Enter your selection: "; 
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
    case 1:;
        break;

    case 2:;
        break;

    case 3:;
        break;

    case 9:
        mainMenu();
        break;
    }
}

void emailMenu()
{
    int emailChoice;

    cout << "                    +------------------------------------------------------+" << endl;
    cout << "                    |                                                      |" << endl;
    cout << "                    |                         EMAIL                        |" << endl;
    cout << "                    |                                                      |" << endl;
    cout << "                    +------------------------------------------------------+" << endl;
    cout << "                    |                                                      |" << endl;
    cout << "                    |    Please, select which person you want to email:    |" << endl;
    cout << "                    |                                                      |" << endl;
    cout << "                    |                                                      |" << endl;
    cout << "                    |                                                      |" << endl;
    cout << "                    |                 1. Back-end developer                |" << endl;
    cout << "                    |                                                      |" << endl;
    cout << "                    |                 2. Front-end developer               |" << endl;
    cout << "                    |                                                      |" << endl;
    cout << "                    |                 3. QA engineer                       |" << endl;
    cout << "                    |                                                      |" << endl;
    cout << "                    |                 9. Back                              |" << endl;
    cout << "                    |                                                      |" << endl;
    cout << "                    +------------------------------------------------------+" << endl;

    cout << "                                   Enter your selection: ";
    while (!(cin >> emailChoice))
    {
        cout << "\n                       Not an integer, try again: "; cin >> emailChoice;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    while (emailChoice != 1 && emailChoice != 2 && emailChoice != 3 && emailChoice != 9)
    {
        cout << "                       Invalid input, try again:";
        while (!(cin >> emailChoice))
        {
            cout << "\n                          Not an integer, try again: "; cin >> emailChoice;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }


    switch (emailChoice)
    {
    case 1:;
        break;

    case 2:;
        break;

    case 3:;
        break;

    case 9:
        mainMenu();
        break;
    }
}

void teacherMenu()
{
    int teacherChoice;

    cout << "                    +------------------------------------------------------+" << endl;
    cout << "                    |                                                      |" << endl;
    cout << "                    |                        TEACHER                       |" << endl;
    cout << "                    |                                                      |" << endl;
    cout << "                    +------------------------------------------------------+" << endl;
    cout << "                    |                                                      |" << endl;
    cout << "                    |     Please, select a option from the ones below:     |" << endl;
    cout << "                    |                                                      |" << endl;
    cout << "                    |                                                      |" << endl;
    cout << "                    |                                                      |" << endl;
    cout << "                    |               1. Check the teams you are in          |" << endl;
    cout << "                    |                                                      |" << endl;
    cout << "                    |               9. Back                                |" << endl;
    cout << "                    |                                                      |" << endl;
    cout << "                    +------------------------------------------------------+" << endl;

    cout << "                                   Enter your selection: "; 
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
    case 1:;
        break;

    case 9:
        mainMenu();
        break;
    }
}

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
    cout << "                    |                                                      |" << endl;
    cout << "                    |                   1. Manage account                  |" << endl;
    cout << "                    |                                                      |" << endl;
    cout << "                    |                   2. View info                       |" << endl;
    cout << "                    |                                                      |" << endl;
    cout << "                    |                   3. Inbox                           |" << endl;
    cout << "                    |                                                      |" << endl;
    cout << "                    |                   9. Back                            |" << endl;
    cout << "                    |                                                      |" << endl;
    cout << "                    +------------------------------------------------------+" << endl;

    cout << "                                   Enter your selection: "; 
    while (!(cin >> adminChoice))
    {
        cout << "\n                       Not an integer, try again: "; cin >> adminChoice;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    while (adminChoice != 1 && adminChoice != 2 && adminChoice != 3 && adminChoice != 9)
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
    case 1:;
        break;

    case 2:;
        break;

    case 9:
        mainMenu();
        break;
    }
}