#include <iostream>
#include <string>
#include <fstream>
#include "Data.h"
#include "studentPresentation.h"
#include "adminPresentation.h"

using namespace std;

void displayTeams()
{
	ifstream myFile("team.txt");
	int choose;
	string line, tokens[9], help;

	cout << "\n                                                 +------------------------------------------------------+" << endl;
	cout << "                                                 |                                                      |" << endl;
	cout << "                                                 |                    List of the teams                 |" << endl;
	cout << "                                                 |                                                      |" << endl;
	cout << "                                                 +------------------------------------------------------+" << endl << endl;

	cout << "               Names:          Description:          Date:         Backend:    Frontend:    QA engineer:   Teacher:   Scrum Master:   Status: " << endl << endl;

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

				cout << "      Team:    " << tokens[0] << "   " << tokens[1] << "   " << tokens[2] << "       " << tokens[3] << "       " << tokens[4] << "           " << tokens[5] << "        " << tokens[6] << "        " << tokens[7] << "       " << tokens[8] << endl << endl;
			}
		}
	}

	cout << "\n\n                                                                  Type 1 to back: ";
	while (!(cin >> choose))
	{
		cout << "\n                                                      Not an integer, please try again: "; cin >> choose;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}

	while (choose != 1)
	{
		cout << "\n                                                         Invalid input, try again: ";
		while (!(cin >> choose))
		{
			cout << "\n                                                     Not an integer, please try again: "; cin >> choose;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	}

	switch (choose)
	{
	case 1: viewMenu();
		break;
	}
	myFile.close();
}

void displayYourTeam(string name)
{
	int choice;
	ifstream myFile("team.txt");
	ifstream myfile("students.txt");
	string line, tokens[10], help;

	cout << "\n                            +------------------------------------------------------+" << endl;
	cout << "                            |                                                      |" << endl;
	cout << "                            |                       Your team                      |" << endl;
	cout << "                            |                                                      |" << endl;
	cout << "                            +------------------------------------------------------+" << endl << endl;

	cout << "\n      Name:          Description:        Backend:     Frontend:     QA engineer:     Teacher:     Scrum Master:" << endl << endl;

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

				if (tokens[8] == "inuse")
				{
					if (tokens[3] == name)
					{
						cout << " Team: " << tokens[0] << "       " << tokens[1] << "      " << tokens[3] << "         " << tokens[4] << "         " << tokens[5] << "          " << tokens[6] << "          " << tokens[7] << endl << endl;
					}
					else if (tokens[4] == name)
					{
						cout << " Team: " << tokens[0] << "       " << tokens[1] << "      " << tokens[3] << "         " << tokens[4] << "         " << tokens[5] << "          " << tokens[6] << "          " << tokens[7] << endl << endl;
					}
					else if (tokens[5] == name)
					{
						cout << " Team: " << tokens[0] << "       " << tokens[1] << "      " << tokens[3] << "         " << tokens[4] << "         " << tokens[5] << "          " << tokens[6] << "          " << tokens[7] << endl << endl;
					}
					else if (tokens[7] == name)
					{
						cout << " Team: " << tokens[0] << "       " << tokens[1] << "      " << tokens[3] << "         " << tokens[4] << "         " << tokens[5] << "          " << tokens[6] << "          " << tokens[7] << endl << endl;
					}
				}
			}
		}
	}
	myFile.close();

	cout << "\n                                                      Type 1 to back: ";
	while (!(cin >> choice))
	{
		cout << "\n                                            Not an integer, try again: "; cin >> choice;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}

	while (choice != 1)
	{
		cout << "\n                                            Invalid input, try again:";
		while (!(cin >> choice))
		{
			cout << "\n                                      Not an integer, try again: "; cin >> choice;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	}

	if (myfile.is_open())
	{
		while (myfile.good())
		{
			getline(myfile, tokens[0]);

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

				if (tokens[0] == name)
				{
					if (choice == 1)
					{
						if (tokens[6] == "0")
						{
							system("cls");
							scrumMasterMenu();
						}
						else if (tokens[6] == "1")
						{
							system("cls");
							frontEndMenu();
						}
						else if (tokens[6] == "2")
						{
							system("cls");
							backEndMenu();
						}
						else if (tokens[6] == "3")
						{
							system("cls");
							QAEngineerMenu();
						}
					}
				}
			}
		}
	}
	myfile.close();
}