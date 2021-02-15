#include <iostream>
#include <string>
#include <regex>
#include <fstream>
#include "Data.h"
#include "Presentation.h"
#include "Struct.h"

using namespace std;

string checkAcc(STUDENT& username, STUDENT& password) 
{
	ifstream myFile("students.txt");
	string line[100];

	if (myFile.is_open())
	{
		while (myFile.good())
		{
			getline(myFile, line[0], ',');
			if (line[0] == username.name)
			{
				getline(myFile, line[1], ',');
				if (line[1] == password.password)
				{
					getline(myFile, line[2], ',');

					return line[2];
				}
				else
				{
					cout << "\n                   Invalid password or username!" << endl;
				}
			}
			else
			{
				getline(myFile, line[3]);
			}
		}
		myFile.close();
	}
	cout << "\n                   Please try to login again!\n" << endl;
	return "invalidAccount";
}

string checkAccId(STUDENT id, STUDENT& username)
{
	ifstream myFile("students.txt");
	string line[100];

	if (myFile.is_open())
	{
		while (myFile.good())
		{
			getline(myFile, line[0], ',');

			if (line[0] == username.name)
			{
				getline(myFile, line[1], ',');

				if (id.id == "0")
				{
					scrumMasterMenu();
				}
				else if (id.id == "1")
				{
					frontEndMenu();
				}
				else if (id.id == "2")
				{
					backEndMenu();
				}
				else if (id.id == "3")
				{
					QAEngineerMenu();
				}
				else if (id.id == "4")
				{
					teacherMenu();
				}
				else if (id.id == "5")
				{
					adminMenu();
				}
			}
			else
			{
				getline(myFile, line[3]);
			}
		}
		myFile.close();
	}	
	return "InvalidId";
}

bool isCharacter(const char character)
{
	return ((Character >= 'a' && Character <= 'z') || (Character >= 'A' && Character <= 'Z'));
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
}
