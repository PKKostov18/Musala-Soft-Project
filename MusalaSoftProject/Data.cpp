#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "Data.h"
#include "Presentation.h"
#include "Struct.h"

using namespace std;

bool checkAccStudents(STUDENT& username, STUDENT& password) 
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

			if (help == "") {}
			else
			{
				if (help[0] == '\n')
				{
					help.erase(0, 1);
				}

				if (tokens[0] == username.name)
				{
					if (tokens[2] == password.password)
					{
						return true;
					}
				}
			}
		}
	}
	myFile.close();
	return false;
}

bool checkAccTeachers(STUDENT& username, STUDENT& password)
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

				if (tokens[0] == username.name)
				{
					if (tokens[2] == password.password)
					{
						return true;
					}
				}
			}
		}
	}
	myFile.close();
	return false;
}

void checkAccStudentsId(STUDENT& username)
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

			if (help == "") {}
			else
			{
				if (help[0] == '\n')
				{
					help.erase(0, 1);
				}

				if (tokens[0] == username.name)
				{
					if (tokens[6] == "0")
					{
						scrumMasterMenu();
					}
					else if (tokens[6] == "1")
					{
						frontEndMenu();
					}
					else if (tokens[6] == "2")
					{
						backEndMenu();
					}
					else if (tokens[6] == "3")
					{
						QAEngineerMenu();
					}
					else
					{
						teacherMenu();
					}
				}
			}
		}
	}
	myFile.close();
}

void checkAccTeachersId(STUDENT& username)
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

				if (tokens[0] == username.name)
				{
					if (tokens[4] == "4")
					{
						teacherMenu();
					}
				}
			}
		}
	}
	myFile.close();
}

bool isCharacter(const char character)
{
	return ((character >= 'a' && character <= 'z') || (character >= 'A' && character <= 'Z'));
}

bool isEmailValid(const char* email)
{
	if (!email)
		return 0;
	if (!isCharacter(email[0]))
		return 0;

	int AtOffset = -1;
	int DotOffset = -1;
	unsigned int Length = strlen(email);

	for (unsigned int i = 0; i < Length; i++)
	{
		if (email[i] == '@')
			AtOffset = (int)i;
		else if (email[i] == '.')
			DotOffset = (int)i;
	}

	if (AtOffset == -1 || DotOffset == -1)
		return 0;
	if (AtOffset > DotOffset) 
		return 0;

	return !(DotOffset >= ((int)Length - 1)); 
}

bool isClassnameValid(string& classname)
{
	while (classname != "10B" && classname != "10A" && classname != "10V" && classname != "10G")
	{
		cout << "\n                       Invalid input, try again: "; cin >> classname;
		cout << endl;
	}
	return true;
}

int tokenize(string line, string* results, char delimiter) 
{
	string help;
	int counter = 0, count = 0;

	for (int i = 0; i < line.size(); i++)
	{
		if (line[i] == delimiter)
		{
			results[counter++] = help;
			help = "";
			i++;
		}
		help += line[i];
	}
	return counter;
}

void displayStudents()
{
	ifstream myFile("students.txt");
	STUDENT students;
	int choose;
	string line, tokens[7], help;

	cout << "              Names:    Surnames:   Passowrds:     Class:     Emails:     Role:" << endl << endl;

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
	case 1: viewMenu();
		break;
	}
}

void displayTeachers()
{
	ifstream myFile("teachers.txt");
	STUDENT students;
	int choose;
	string line, tokens[7], help;

	cout << "              Names:    Surnames:     Passwords:     Emails:" << endl << endl;

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
				cout << "  Account:    " << tokens[0] << "   " << tokens[1] << "   " << tokens[2] << "   " << tokens[3] << endl << endl;
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
	case 1: viewMenu();
		break;
	}
	myFile.close();
}

void displayParticularStudentsBackend()
{
	ifstream myFile("students.txt");
	string line, tokens[10], help;

	cout << "\n                          _________________________________________________________________";
	cout << "\n                                        Names:           Surnames:" << endl << endl;

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
							cout << "                           Account:    " << tokens[0] << "        " << tokens[1] << endl << endl;
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
	cout << "\n                                        Names:           Surnames:" << endl << endl;

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
						cout << "                           Account:    " << tokens[0] << "        " << tokens[1] << endl << endl;
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
	cout << "\n                                        Names:           Surnames:" << endl << endl;

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
						cout << "                           Account:    " << tokens[0] << "        " << tokens[1] << endl << endl;
					}
				}
			}
		}
	}
	cout << "                          _________________________________________________________________" << endl;
	myFile.close();
}

void displayTeachersForTeams()
{
	ifstream myFile("teachers.txt");
	string line, tokens[7], help;

	cout << "\n                          _________________________________________________________________" << endl;
	cout << "                                       Names:       Surnames:  " << endl << endl;

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
				cout << "                            Account:    " << tokens[0] << "   " << tokens[1] << endl << endl;
			}
		}
	}
	cout << "                          _________________________________________________________________" << endl;
	myFile.close();
}

void editUsername(string student) 
{
	fstream myfile("students.txt");
	string tokens[10], help, newUsername;

	if (myfile.is_open())
	{
		string line;

		while (!myfile.eof())
		{
			getline(myfile, line);

			if (line != "") {
				tokenize(line, tokens, ',');

				if (tokens[0] == student) 
				{
					tokens[7] = "use";
					myfile << tokens[0] << "," << tokens[1] << "," << tokens[2] << "," << tokens[3] << "," << tokens[4] << "," << tokens[5] << "," << tokens[6] << "," << tokens[7] << endl;
				}
			}
		}
	}
}