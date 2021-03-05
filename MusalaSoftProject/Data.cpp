#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "Data.h"
#include "Presentation.h"
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

bool checkAccAdminId(STUDENT& username, STUDENT& password)
{
	ifstream myFile("admin.txt");
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
							if (tokens[4] == "5")
							{
								system("cls");
								adminMenu();
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
	int choose;
	string line, tokens[7], help;

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

void displayTeachers()
{
	ifstream myFile("teachers.txt");
	int choose;
	string line, tokens[7], help;

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

				cout << "   Team:    " << tokens[0] << "   " << tokens[1] << "   " << tokens[2] << "       " << tokens[3] << "       " << tokens[4] << "           " << tokens[5] << "        " << tokens[6] << "        " << tokens[7] << "       " << tokens[8] << endl << endl;
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

void changeStudentsStatus(string& student) 
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
				cerr << "                     Error! ";
			}
		}
	}
}

void deleteAccount() 
{
	fstream myfile("students.txt");
	ofstream tmpFile("studentsTmp.txt");
	string tokens[10], help;
	int counter = 0, choice;
	string line;
	bool userExist = false;

	cout << "                 +---------------------------------------------------+" << endl;
	cout << "\n                                Name of the user: ";
	cin >> help;

	if (myfile.is_open())
	{
		string line;
		while (!myfile.eof())
		{
			getline(myfile, line);

			if (line != "")
			{
				tokenize(line, tokens, ',');

				if (help != tokens[0]) 
				{
					if (tmpFile.is_open())
					{
						counter = 7;
						tmpFile << tokens[counter] << "," << tokens[counter--] << "," << tokens[counter--] << "," << tokens[counter--] << "," << tokens[counter--] << "," << tokens[counter--] << "," << tokens[counter--] << "," << tokens[counter--] << "," << endl;
					}
				}
				else
				{
					userExist = true;
				}
			}
		}
		tmpFile.close();
		myfile.close();

		char buff[256];

		strerror_s(buff, 25);

		if (remove("students.txt") != 0) 
		{
			strerror_s(buff, 25);
			cerr << "                  Error! " << buff << endl;
		}

		if (rename("studentsTmp.txt", "students.txt") != 0)
		{
			strerror_s(buff, 25);
			cerr << "                  Error! " << buff << endl;
		}
		else
		{
			cout << "\n                  Deleting account done!" << endl;
		}
	}

	cout << "\n                          Type 1 to back: ";  
	while (!(cin >> choice))
	{
		cout << "\n                       Not an integer, try again: "; cin >> choice;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}

	while (choice != 1)
	{
		cout << "                       Invalid input, try again:";
		while (!(cin >> choice))
		{
			cout << "\n                          Not an integer, try again: "; cin >> choice;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	}

	if (choice == 1)
	{
		system("cls");
		manageAccountsMenu();
	}
}

void editPassword() 
{
	ifstream myfile("students.txt");
	ofstream tmpFile("studentsTmp.txt");
	string tokens[10], help, newPassword;
	int counter = 0, choice;
	bool userExist = false;

	cout << "                 +---------------------------------------------------+" << endl;
	cout << "\n                                Name of the user: ";
	cin >> help;

	if (myfile.is_open())
	{
		string line;

		while (!myfile.eof())
		{
			getline(myfile, line);

			if (line != "") 
			{
				tokenize(line, tokens, ',');

				if (help != tokens[0])
				{
					if (tmpFile.is_open())
					{
						tmpFile << tokens[0] << "," << tokens[1] << "," << tokens[2] << "," << tokens[3] << " " << tokens[4] << "," << tokens[5] << "," << tokens[6] << "," << tokens[7] << "," << endl;
					}
				}
				else
				{
					cout << "New password: ";
					cin >> newPassword;
					tmpFile << tokens[0] << "," << tokens[1] << "," << newPassword << "," << tokens[3] << " " << tokens[4] << "," << tokens[5] << "," << tokens[6] << "," << tokens[7] << "," << endl;
					userExist = true;
				}
			}
		}

		if (!userExist)
		{
			cout << "                     This user doesn't exist, nothing happened" << endl;
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
				cerr << "\n                     Error! ";
			}

			tmpFile.close();

			if (rename("studentsTmp.txt", "students.txt") != 0)
			{
				cerr << "\n                     Error! ";
			}
			else
			{
				cout << "\n                     Editing password done!" << endl;
			}
		}
	}

	cout << "\n                          Type 1 to back: ";
	while (!(cin >> choice))
	{
		cout << "\n                       Not an integer, try again: "; cin >> choice;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}

	while (choice != 1)
	{
		cout << "\n                       Invalid input, try again:";
		while (!(cin >> choice))
		{
			cout << "\n                          Not an integer, try again: "; cin >> choice;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	}

	if (choice == 1)
	{
		system("cls");
		manageAccountsMenu();
	}
}