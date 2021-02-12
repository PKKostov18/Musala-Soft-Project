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

bool isCharacter(const char Character)
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