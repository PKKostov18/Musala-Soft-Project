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
    string result = "invalidAccount", result1 = "invalidAccount";
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

        while (checkAccStudentsId(username) == false && checkAccTeachersId(username) == false && checkAccAdminId(username) == false)
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
    else
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
    STUDENT username, password, surname, classname, email, role, id, status;
    string c_password;
    ofstream myFile;
    int choice;
    myFile.open("students.txt", ios::app);

    system("cls");

    cout << "\n                                Like what you want to register? " << endl;
    cout << "                                         1. Student " << endl;
    cout << "                                         2. Teacher " << endl;
    cout << "\n                                           Choose: "; 

    while (!(cin >> choice))
    {
        cout << "\n                       Not an integer, try again: "; cin >> choice;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    while (choice != 1 && choice != 2)
    {
        cout << "                          Invalid input, try again:";
        while (!(cin >> choice))
        {
            cout << "\n                            Not an integer, try again: "; cin >> choice;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    if (choice == 1)
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

        if (role.role == "Scrum Master")
        {
            id.id = "0";
        }
        else if (role.role == "Front-end")
        {
            id.id = "1";
        }
        else if (role.role == "Back-end")
        {
            id.id = "2";
        }
        else if (role.role == "QA engineer")
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
    case 1: 
        system("cls");
        teamRegisterMenu();
        break;

    case 2:
        system("cls");
        break;

    case 3:
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
    cout << "                    |                 9. Log out                           |" << endl;
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
    case 1:
        teamRegisterMenu();
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
    cout << "                    |                 9. Log out                           |" << endl;
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
    cout << "                    |                 2. Report bugs                       |" << endl;
    cout << "                    |                                                      |" << endl;
    cout << "                    |                 9. Log out                           |" << endl;
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
    cout << "                    |                4. See lists with particular creteria |" << endl;
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

    case 3:;
        break;

    case 4:
        break;

    case 9:
        mainMenu();
        break;
    }
}

void teamRegisterMenu()
{
    TEAM name, description, date, teacher, studentBackend, studentFrontend, studentQA, nameCheck;
    string nothing;
    ofstream myFile;
    int choice;
    myFile.open("team.txt", ios::app);

    system("cls");

    cout << "                    +------------------------------------------------------+" << endl;
    cout << "                    |                                                      |" << endl;
    cout << "                    |                     Create a team                    |" << endl;
    cout << "                    |                                                      |" << endl;
    cout << "                    +------------------------------------------------------+" << endl << endl; 

    getline(cin, nothing);
    cout << "                                   Enter your the team name: ";
    getline(cin, name.name);

    cout << "\n                                   Write a description of the team: ";
    getline(cin, description.description);

    cout << "\n                                   Enter the date of set up: " << endl;
    cout << "                                   Example - 05.03.2020 - dd.mm.yyyy: ";
    getline(cin, date.date);
    cout << endl;

    
    cout << "\n                           Choose to see who is free for your team: " << endl << endl;
    cout << "                                      1. Back-end students" << endl;

    displayParticularStudentsBackend();

    cout << "                                       Enter the name: ";
    cin >> studentBackend.teammatesBackend;
    changeStudentsStatus(studentBackend.teammatesBackend);
    cout << endl;

    cout << "                                      2. Front-end students" << endl;

    displayParticularStudentsFrontend();

    cout << "                                       Enter the name: ";
    cin >> studentFrontend.teammatesFrontend;
    changeStudentsStatus(studentFrontend.teammatesFrontend);
    cout << endl;

    cout << "                                      3. QA engineer students" << endl;

    displayParticularStudentsQA();

    cout << "                                       Enter the name: ";
    cin >> studentQA.teammatesQA;
    changeStudentsStatus(studentQA.teammatesQA);
    cout << endl;

    displayTeachersForTeams();
    cout << "                                   Add a teacher to your team: ";
    cin >> teacher.teacher;

    myFile << name.name << "," << description.description << "," << date.date << "," << studentBackend.teammatesBackend << "," << studentFrontend.teammatesFrontend << "," << studentQA.teammatesQA << "," << teacher.teacher << "," << endl;
    myFile.close();

    cout << "\n                                   Register successful!";
    cout << "\n\n                                   Type 1 to back: "; 

    while (!(cin >> choice))
    {
        cout << "\n                       Not an integer, try again: "; cin >> choice;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    while (choice != 1)
    {
        cout << "                          Invalid input, try again:";
        while (!(cin >> choice))
        {  
            cout << "\n                            Not an integer, try again: "; cin >> choice;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    if (choice == 1)
    {
        system("cls");
        scrumMasterMenu();
    }
} 

void teacherRegisterMenu()
{
    TEACHER name, surname, date, email, id, password;
    string choose;
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
}

void emailMenu()
{
    ofstream myfile("email.txt", ios::app);
    EMAIL name, description;
    string nothing;

    system("cls");

    cout << "                    +------------------------------------------------------+" << endl;
    cout << "                    |                                                      |" << endl;
    cout << "                    |                         Email                        |" << endl;
    cout << "                    |                                                      |" << endl;
    cout << "                    +------------------------------------------------------+" << endl;

    getline(cin, nothing);
    cout << "\n                                 Enter your name: "; getline(cin, name.name);

    cout << "\n                                 Enter a description: "; getline(cin, description.description);

    myfile << name.name << "," << description.description << "," << endl;
}

void viewEmails()
{
    ifstream myFile("email.txt");
    STUDENT students;
    int choose;
    string line, tokens[7], help;

    cout << "               From:         Descriptions:" << endl << endl;

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
                cout << "  Email:    " << tokens[0] << "   " << tokens[1] << endl << endl;
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
    case 1: adminMenu();
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
        editUsername();
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
    cout << "                    |                   1. Delete account                  |" << endl;
    cout << "                    |                                                      |" << endl;
    cout << "                    |                   2. Edit team name                  |" << endl;
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
        break;

    case 2:
        break;

    case 9: adminMenu();
        break;
    }
}