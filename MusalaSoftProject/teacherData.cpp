#include <iostream>
#include <string>
#include <fstream>
#include "Data.h"
#include "adminPresentation.h"
#include "teacherPresentation.h"
#include "Struct.h"

using namespace std;

bool checkAccTeachersId(STUDENT& username, STUDENT& password)
{
	ifstream myFile("teachers.txt");
	string line, tokens[10], help;

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

				if (username.name == tokens[0])
				{
					if (password.password == tokens[2])
					{
						if (tokens[0] == username.name)
						{
							if (tokens[4] == "4")
							{
								system("cls");
								teacherMenu();
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

void displayTeachers()
{
	ifstream myFile("teachers.txt");
	int choose;
	string line, tokens[4], help;

	cout << "\n                    +------------------------------------------------------+" << endl;
	cout << "                    |                                                      |" << endl;
	cout << "                    |                    List of teachers                  |" << endl;
	cout << "                    |                                                      |" << endl;
	cout << "                    +------------------------------------------------------+" << endl << endl;

	cout << "              Names:    Surnames:     Passwords:     Emails:" << endl << endl;

	if (myFile.is_open())
	{
		while (myFile.good())
		{
			getline(myFile, tokens[0]);

			tokenize(tokens[0], tokens, ',');

			help = tokens[0];

			if (help != "") 
			{
				if (help[0] == '\n')
				{
					help.erase(0, 1);
				}

				cout << "  Account:    " << tokens[0] << "   " << tokens[1] << "   " << tokens[2] << "   " << tokens[3] << endl << endl;
			}
		}
	}
	myFile.close();

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
	case 1: viewMenu();
		break;
	}
}

void displayTeachersForTeams()
{
	ifstream myFile("teachers.txt");
	string line, tokens[7], help;

	cout << "\n                          _________________________________________________________________" << endl;
	cout << "                                              Names:" << endl << endl;

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
				cout << "                                Account:    " << tokens[0] << endl << endl;
			}
		}
	}
	cout << "                          _________________________________________________________________" << endl;
	myFile.close();
}