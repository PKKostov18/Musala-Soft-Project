#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "Data.h"
#include "Presentation.h"
#include "studentPresentation.h"
#include "adminPresentation.h"
#include "Struct.h"

using namespace std;

bool checkAccStudentsId(STUDENT& username, STUDENT& password)
{
	ifstream myFile("students.txt");
	string line, tokens[10], help;

	if (myFile.is_open())
	{
		while (myFile.good())
		{
			getline(myFile, tokens[0]);

			tokenize(tokens[0], tokens, ',');

			help = tokens[0];

			if (help == "")
			{
			}
			else
			{
				if (help[0] == '\n')
				{
					help.erase(0, 1);
				}
				if (username.name == tokens[0])
				{
					if (password.password == tokens[2])
					{
						if (tokens[0] == username.name)
						{
							if (tokens[6] == "0")
							{
								system("cls");
								scrumMasterMenu();
								return true;
							}
							else if (tokens[6] == "1")
							{
								system("cls");
								frontEndMenu();
								return true;
							}
							else if (tokens[6] == "2")
							{
								system("cls");
								backEndMenu();
								return true;
							}
							else if (tokens[6] == "3")
							{
								system("cls");
								QAEngineerMenu();
								return true;
							}
						}
					}
				}
			}
		}
	}
	myFile.close();
	return false;
}

void displayStudents()
{
	ifstream myFile("students.txt");
	int choose;
	string line, tokens[6], help;

	cout << "\n                    +------------------------------------------------------+" << endl;
	cout << "                    |                                                      |" << endl;
	cout << "                    |                    List of students                  |" << endl;
	cout << "                    |                                                      |" << endl;
	cout << "                    +------------------------------------------------------+" << endl << endl;

	cout << "              Names:    Surnames:     Passwords:     Class:     Emails:     Roles:" << endl << endl;

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

				cout << "  Account:    " << tokens[0] << "   " << tokens[1] << "   " << tokens[2] << "   " << tokens[3] << "   " << tokens[4] << "   " << tokens[5] << endl << endl;
			}
		}
	}

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
		viewMenu();
		break;
	}
	myFile.close();
}

void displayParticularStudentsBackend()
{
	ifstream myFile("students.txt");
	string line, tokens[10], help;

	cout << "\n                          _________________________________________________________________";
	cout << "\n                                            Names:           " << endl << endl;

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

				if (tokens[5] == "Back-end")
				{
					if (tokens[7] == "notuse")
					{
						cout << "                             Account:    " << tokens[0] << endl << endl;
					}
				}
			}
		}
	}
	cout << "                          _________________________________________________________________" << endl;
	myFile.close();
}

void displayParticularStudentsFrontend()
{
	ifstream myFile("students.txt");
	string line, tokens[10], help;

	cout << "\n                          _________________________________________________________________";
	cout << "\n                                               Names:" << endl << endl;

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

				if (tokens[5] == "Front-end")
				{
					if (tokens[7] == "notuse")
					{
						cout << "                              Account:    " << tokens[0] << endl << endl;
					}
				}
			}
		}
	}
	cout << "                          _________________________________________________________________" << endl;
	myFile.close();
}

void displayParticularStudentsQA()
{
	ifstream myFile("students.txt");
	string line, tokens[10], help;

	cout << "\n                          _________________________________________________________________";
	cout << "\n                                            Names:" << endl << endl;

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

				if (tokens[5] == "QA engineer")
				{
					if (tokens[7] == "notuse")
					{
						cout << "                              Account:    " << tokens[0] << endl << endl;
					}
				}
			}
		}
	}
	cout << "                          _________________________________________________________________" << endl;
	myFile.close();
}

void changeStudentsStatus(string student)
{
	ifstream myfile("students.txt");
	ofstream tmpFile("studentsTmp.txt");
	string tokens[10], status = "use";
	bool userExist = false;

	if (myfile.is_open())
	{
		string line;

		while (!myfile.eof())
		{
			getline(myfile, line);

			if (line != "")
			{
				tokenize(line, tokens, ',');

				if (student != tokens[0])
				{
					if (tmpFile.is_open())
					{
						tmpFile << tokens[0] << "," << tokens[1] << "," << tokens[2] << "," << tokens[3] << " " << tokens[4] << "," << tokens[5] << "," << tokens[6] << "," << tokens[7] << "," << endl;
					}
				}
				else
				{
					tmpFile << tokens[0] << "," << tokens[1] << "," << tokens[2] << "," << tokens[3] << " " << tokens[4] << "," << tokens[5] << "," << tokens[6] << "," << status << "," << endl;
					userExist = true;
				}
			}
		}

		if (!userExist)
		{
			cout << "                     There is no user with this name!" << endl;
			myfile.close();
			remove("students.txt");
			tmpFile.close();
			rename("studentsTmp.txt", "students.txt");
		}
		else
		{
			myfile.close();

			if (remove("students.txt") != 0)
			{
				cerr << "                     Error! ";
			}

			tmpFile.close();

			if (rename("studentsTmp.txt", "students.txt") != 0)
			{
				cerr << "\n                     Error! ";
			}
		}
	}
}