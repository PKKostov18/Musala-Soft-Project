#include <iostream>
#include <string>
#include <fstream>
#include "Data.h"
#include "Presentation.h"
#include "Struct.h"

using namespace std;

string checkAcc(STUDENT username, STUDENT password) 
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