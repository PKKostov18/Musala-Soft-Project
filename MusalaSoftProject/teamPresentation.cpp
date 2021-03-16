#include <iostream>
#include <fstream>
#include <string>
#include "Data.h"
#include "studentData.h"
#include "studentPresentation.h"
#include "teacherData.h"

using namespace std;

void teamRegisterMenu()
{
    TEAM name, description, date, teacher, studentBackend, studentFrontend, studentQA, studentScrum, status;
    string nothing, line, tokens[10], help, name1;
    ofstream myFile;
    ifstream myfile, myfile1("team.txt");
    myFile.open("team.txt", ios::app);
    myfile.open("currentAcc.txt", ios::in);
    int choice;

    system("cls");

    if (myfile.is_open())
    {
        while (getline(myfile, line))
        {
            studentScrum.scrumMaster = line;
        }
        myfile.close();
    }

    if (myfile1.is_open())
    {
        while (myfile1.good())
        {
            getline(myfile1, tokens[0]);

            tokenize(tokens[0], tokens, ',');

            help = tokens[0];

            if (help != "")
            {
                if (help[0] == '\n')
                {
                    help.erase(0, 1);
                }

                if (tokens[7] == studentScrum.scrumMaster)
                {
                    if (tokens[8] == "inuse")
                    {
                        cout << "\n                              You already have a team!" << endl;
                        cout << "\n             Send a message to the admin to edit the team status to not active!" << endl;
                        cout << "\n                                  Type 1 to back: ";

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
                    else
                    {
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

                        cout << "\n                                       Enter the name: ";
                        cin >> studentBackend.teammatesBackend;

                        cout << endl;

                        cout << "                                      2. Front-end students" << endl;
                        displayParticularStudentsFrontend();

                        cout << "\n                                       Enter the name: ";
                        cin >> studentFrontend.teammatesFrontend;

                        cout << endl;

                        cout << "                                      3. QA engineer students" << endl;

                        displayParticularStudentsQA();

                        cout << "\n                                       Enter the name: ";
                        cin >> studentQA.teammatesQA;

                        cout << endl;

                        displayTeachersForTeams();
                        cout << "\n                                   Add a teacher to your team! " << endl;
                        cout << "                                   Enter the name and the surname: ";

                        getline(cin, teacher.teacher);
                        getline(cin, teacher.teacher);

                        if (myfile.is_open())
                        {
                            while (getline(myfile, line))
                            {
                                studentScrum.scrumMaster = line;
                            }
                            myfile.close();
                        }

                        status.status = "inuse";

                        myFile << name.name << "," << description.description << "," << date.date << "," << studentBackend.teammatesBackend << "," << studentFrontend.teammatesFrontend << "," << studentQA.teammatesQA << "," << teacher.teacher << "," << studentScrum.scrumMaster << status.status << "," << endl;
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

                        changeStudentsStatus(studentBackend.teammatesBackend);
                        changeStudentsStatus(studentFrontend.teammatesFrontend);
                        changeStudentsStatus(studentQA.teammatesQA);
                    }
                }
                else
                {
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

                    cout << "\n                                       Enter the name: ";
                    cin >> studentBackend.teammatesBackend;

                    cout << endl;

                    cout << "                                      2. Front-end students" << endl;
                    displayParticularStudentsFrontend();

                    cout << "\n                                       Enter the name: ";
                    cin >> studentFrontend.teammatesFrontend;

                    cout << endl;

                    cout << "                                      3. QA engineer students" << endl;

                    displayParticularStudentsQA();

                    cout << "\n                                       Enter the name: ";
                    cin >> studentQA.teammatesQA;

                    cout << endl;

                    displayTeachersForTeams();
                    cout << "\n                                   Add a teacher to your team! " << endl;
                    cout << "                                   Enter the name and the surname: ";

                    getline(cin, teacher.teacher);
                    getline(cin, teacher.teacher);

                    if (myfile.is_open())
                    {
                        while (getline(myfile, line))
                        {
                            studentScrum.scrumMaster = line;
                        }
                        myfile.close();
                    }

                    status.status = "inuse";

                    myFile << name.name << "," << description.description << "," << date.date << "," << studentBackend.teammatesBackend << "," << studentFrontend.teammatesFrontend << "," << studentQA.teammatesQA << "," << teacher.teacher << "," << studentScrum.scrumMaster << "," << status.status << "," << endl;
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

                    changeStudentsStatus(studentBackend.teammatesBackend);
                    changeStudentsStatus(studentFrontend.teammatesFrontend);
                    changeStudentsStatus(studentQA.teammatesQA);
                }
            }
        }
    }
    myfile1.close();
}