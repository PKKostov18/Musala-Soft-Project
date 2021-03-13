#include <iostream>
#include <string>
#include <fstream>
#include "Data.h"

using namespace std;

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