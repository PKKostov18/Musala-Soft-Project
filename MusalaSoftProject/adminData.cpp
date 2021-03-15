#include <iostream>
#include <string>
#include <fstream>
#include "Data.h"
#include "adminData.h"
#include "adminPresentation.h"
#include "studentPresentation.h"
#include "Struct.h"

using namespace std;

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

void deleteAccount()
{
	ifstream myfile("students.txt");
	ifstream myFile("team.txt");
	ofstream tmpFile2("teamTmp.txt");
	ofstream tmpFile("studentsTmp.txt");
	ifstream myfile1("teachers.txt");
	ofstream tmpFile1("teachersTmp.txt");
	string tokens[10], help;
	int counter = 0, choice, choose;
	string line;
	bool userExist = false;

	cout << "\n                        Choose which account you want to delete! " << endl;
	cout << "\n                                      1. Student";
	cout << "\n                                      2. Teacher" << endl;
	cout << "\n                                   Choose an option: "; cin >> choose;

	if (choose == 1)
	{
		system("cls");

		cout << "                 +---------------------------------------------------+" << endl;
		cout << "\n                                 Name of the user: ";
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

		if (myFile.is_open())
		{
			string line;

			while (!myFile.eof())
			{
				getline(myFile, line);

				if (line != "")
				{
					tokenize(line, tokens, ',');

					if (help == tokens[3])
					{
						tmpFile2 << tokens[0] << "," << tokens[1] << "," << tokens[2] << "," << "missing" << "," << tokens[4] << "," << tokens[5] << "," << tokens[6] << "," << tokens[7] << "," << tokens[8] << "," << endl;
						userExist = true;
					}
					else if (help == tokens[4])
					{
						tmpFile2 << tokens[0] << "," << tokens[1] << "," << tokens[2] << "," << tokens[3] << "," << "missing" << "," << tokens[5] << "," << tokens[6] << "," << tokens[7] << "," << tokens[8] << "," << endl;
						userExist = true;
					}
					else if (help == tokens[5])
					{
						tmpFile2 << tokens[0] << "," << tokens[1] << "," << tokens[2] << "," << tokens[3] << "," << tokens[4] << "," << "missing" << "," << tokens[6] << "," << tokens[7] << "," << tokens[8] << "," << endl;
						userExist = true;
					}
					else if (help == tokens[7])
					{
						tmpFile2 << tokens[0] << "," << tokens[1] << "," << tokens[2] << "," << tokens[3] << "," << tokens[4] << "," << tokens[4] << "," << tokens[6] << "," << "missing" << "," << tokens[8] << "," << endl;
						userExist = true;
					}
				}
			}

			if (!userExist)
			{
				cout << "                     This user doesn't exist, nothing happened" << endl;
				myFile.close();
				remove("team.txt");
				tmpFile2.close();
				rename("teamTmp.txt", "team.txt");
			}
			else
			{
				myFile.close();

				if (remove("team.txt") != 0)
				{
					cerr << "\n                     Error! ";
				}

				tmpFile2.close();

				if (rename("teamTmp.txt", "team.txt") != 0)
				{
					cerr << "\n                     Error! ";
				}
			}
		}

		if (choice == 1)
		{
			system("cls");
			manageAccountsMenu();
		}
	}
	else
	{
		system("cls");

		cout << "                 +---------------------------------------------------+" << endl;
		cout << "\n                                 Name of the teacher: ";
		cin >> help;

		if (myfile1.is_open())
		{
			string line;

			while (!myfile1.eof())
			{
				getline(myfile1, line);

				if (line != "")
				{
					tokenize(line, tokens, ',');

					if (help != tokens[0])
					{
						if (tmpFile1.is_open())
						{
							counter = 4;
							tmpFile1 << tokens[counter] << "," << tokens[counter--] << "," << tokens[counter--] << "," << tokens[counter--] << "," << tokens[counter--] << "," << endl;
						}
					}
					else
					{
						userExist = true;
					}
				}
			}
			tmpFile1.close();
			myfile1.close();

			char buff[256];

			strerror_s(buff, 25);

			if (remove("teachers.txt") != 0)
			{
				strerror_s(buff, 25);
				cerr << "                  Error! " << buff << endl;
			}

			if (rename("teachersTmp.txt", "teachers.txt") != 0)
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

		if (myFile.is_open())
		{
			string line;

			while (!myFile.eof())
			{
				getline(myFile, line);

				if (line != "")
				{
					tokenize(line, tokens, ',');

					if (help == tokens[6])
					{
						tmpFile2 << tokens[0] << "," << tokens[1] << "," << tokens[2] << "," << tokens[3] << "," << tokens[4] << "," << tokens[5] << "," << "missing" << "," << tokens[7] << "," << tokens[8] << "," << endl;
						userExist = true;
					}
				}
			}

			if (!userExist)
			{
				cout << "                     This user doesn't exist, nothing happened" << endl;
				myFile.close();
				remove("team.txt");
				tmpFile2.close();
				rename("teamTmp.txt", "team.txt");
			}
			else
			{
				myFile.close();

				if (remove("team.txt") != 0)
				{
					cerr << "\n                     Error! ";
				}

				tmpFile2.close();

				if (rename("teamTmp.txt", "team.txt") != 0)
				{
					cerr << "\n                     Error! ";
				}
			}
		}

		if (choice == 1)
		{
			system("cls");
			manageAccountsMenu();
		}
	}


}

void deleteTeams()
{
	fstream myfile("team.txt");
	ofstream tmpFile("teamTmp.txt");
	string tokens[10], help;
	int counter = 0, choice;
	string line;
	bool teamExist = false;

	cout << "                 +---------------------------------------------------+" << endl;
	cout << "\n                                 Name of the team: ";
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
					teamExist = true;
				}
			}
		}
		tmpFile.close();
		myfile.close();

		char buff[256];

		strerror_s(buff, 25);

		if (remove("team.txt") != 0)
		{
			strerror_s(buff, 25);
			cerr << "                  Error! " << buff << endl;
		}

		if (rename("teamTmp.txt", "team.txt") != 0)
		{
			strerror_s(buff, 25);
			cerr << "                  Error! " << buff << endl;
		}
		else
		{
			cout << "\n                  Deleting team done!" << endl;
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
		manageTeamsMenu();
	}
}

void editPassword()
{
	ifstream myfile("students.txt");
	ofstream tmpFile("studentsTmp.txt");
	string tokens[10], help, newPassword;
	int choice;
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
					cout << "                         New password: ";
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

void editTeamName()
{
	ifstream myfile("team.txt");
	ofstream tmpFile("teamTmp.txt");
	string tokens[10], help, newName;
	int counter = 0, choice;
	bool teamExist = false;

	cout << "                 +---------------------------------------------------+" << endl;
	cout << "\n                                Name of the team: ";
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
						tmpFile << tokens[0] << "," << tokens[1] << "," << tokens[2] << "," << tokens[3] << " " << tokens[4] << "," << tokens[5] << "," << tokens[6] << "," << tokens[7] << "," << tokens[8] << "," << endl;
					}
				}
				else
				{
					cout << "\n                                New team name: ";
					cin >> newName;
					tmpFile << newName << "," << tokens[1] << "," << tokens[2] << "," << tokens[3] << " " << tokens[4] << "," << tokens[5] << "," << tokens[6] << "," << tokens[7] << "," << tokens[8] << "," << endl;
					teamExist = true;
				}
			}
		}

		if (!teamExist)
		{
			cout << "                     This team doesn't exist!" << endl;
			myfile.close();
			remove("team.txt");
			tmpFile.close();
			rename("teamTmp.txt", "team.txt");
		}
		else
		{
			myfile.close();

			if (remove("team.txt") != 0)
			{
				cerr << "\n                     Error! ";
			}

			tmpFile.close();

			if (rename("teamTmp.txt", "team.txt") != 0)
			{
				cerr << "\n                     Error! ";
			}
			else
			{
				cout << "\n                     Editing team name done!" << endl;
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
		manageTeamsMenu();
	}
}

void editTeamStatus()
{
	ifstream myfile("team.txt");
	ofstream tmpFile("teamTmp.txt");
	string tokens[10], help, status = "notactive";
	int choice, choose;
	bool teamExist = false;

	cout << "                 +---------------------------------------------------+" << endl;
	cout << "\n                                Name of the team: ";
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
						tmpFile << tokens[0] << "," << tokens[1] << "," << tokens[2] << "," << tokens[3] << "," << tokens[4] << "," << tokens[5] << "," << tokens[6] << "," << tokens[7] << "," << tokens[8] << "," << endl;
					}
				}
				else
				{
					cout << "\n                                Team status! " << endl;
					cout << "\n                         Type 1 to set to notactive: "; cin >> choose;

					if (choose == 1)
					{
						tmpFile << tokens[0] << "," << tokens[1] << "," << tokens[2] << "," << tokens[3] << "," << tokens[4] << "," << tokens[5] << "," << tokens[6] << "," << tokens[7] << "," << status << "," << endl;
						teamExist = true;
					}
					else
					{
						cout << "                   Invalid input, try again: ";  cin >> choose;

						tmpFile << tokens[0] << "," << tokens[1] << "," << tokens[2] << "," << tokens[3] << "," << tokens[4] << "," << tokens[5] << "," << tokens[6] << "," << tokens[7] << "," << status << "," << endl;
						teamExist = true;
					}
				}
			}
		}

		if (!teamExist)
		{
			cout << "                     This team doesn't exist!" << endl;
			myfile.close();
			remove("team.txt");
			tmpFile.close();
			rename("teamTmp.txt", "team.txt");
		}
		else
		{
			myfile.close();

			if (remove("team.txt") != 0)
			{
				cerr << "\n                     Error! ";
			}

			tmpFile.close();

			if (rename("teamTmp.txt", "team.txt") != 0)
			{
				cerr << "\n                     Error! ";
			}
			else
			{
				cout << "\n                     Editing team name done!" << endl;
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
		manageTeamsMenu();
	}
}

void displayStudentsInParticularTeam()
{
	ifstream myFile("team.txt");
	string line, tokens[10], help, name;
	int choose;

	cout << "\n                   _________________________________________________________________" << endl;
	cout << "\n                                         Name of the team: ";
	cin >> name;

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

				if (tokens[0] == name)
				{
					cout << "\n                    +------------------------------------------------------+" << endl;
					cout << "                    |                                                      |" << endl;
					cout << "                    |                 Students in this team                |" << endl;
					cout << "                    |                                                      |" << endl;
					cout << "                    +------------------------------------------------------+" << endl << endl;

					cout << "\n         Back-end            Front-end            QA engineer           Scrum Master" << endl;
					cout << "\n         " << tokens[3] << "                   " << tokens[4] << "                " << tokens[5] << "                  " << tokens[7] << endl;
				}
				else
				{
					cout << "\n                            This team doesn't exist!" << endl;
				}
			}
		}
	}

	cout << "                                   Type 1 to back: ";
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
		system("cls");
		reports();
		break;
	}
	myFile.close();
}

void displayTeachersWithNoTeam()
{
	ifstream myFile("team.txt");
	ifstream myFile1("teachers.txt");
	string line, tokens[10], tokens1[10], help, help1;
	int choose;

	cout << "\n                    +------------------------------------------------------+" << endl;
	cout << "                    |                                                      |" << endl;
	cout << "                    |               Teachers who dosent't have             |" << endl;
	cout << "                    |                    allocated team                    |" << endl;
	cout << "                    |                                                      |" << endl;
	cout << "                    +------------------------------------------------------+" << endl << endl;

	cout << "\n                                 Name:            Surname:    " << endl;

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

				if (myFile1.is_open())
				{
					while (myFile1.good())
					{
						getline(myFile1, tokens1[0]);

						tokenize(tokens1[0], tokens1, ',');

						help1 = tokens1[0];

						if (help1 != "")
						{
							if (help1[0] == '\n')
							{
								help1.erase(0, 1);
							}

							if (tokens1[0] != tokens[6])
							{
								cout << "\n                    Teacher:  " << tokens1[0] << "      " << tokens1[1] << endl;
							}
							else
							{
								cout << "                     There isn't teachers which don't participate in a team!" << endl;
							}
						}
					}
				}
			}
		}
	}

	cout << "\n                                       Type 1 to back: ";
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
		system("cls");
		reports();
		break;
	}
	myFile.close();
}

void displayTeamsWithNotFullMembers()
{
	ifstream myFile("team.txt");
	string line, tokens[10], help, name;
	int choose;

	cout << "\n                           +------------------------------------------------------+" << endl;
	cout << "                           |                                                      |" << endl;
	cout << "                           |                    Not full teams                    |" << endl;
	cout << "                           |                                                      |" << endl;
	cout << "                           +------------------------------------------------------+" << endl << endl;

	cout << "                 Names:         Backend:    Frontend:    QA engineer:   Teacher:   Scrum Master:  " << endl << endl;

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

				if (tokens[3] == "missing")
				{
					cout << "      Team:    " << tokens[0] << "      " << tokens[3] << "      " << tokens[4] << "           " << tokens[5] << "        " << tokens[6] << "        " << tokens[7] << endl << endl;
				}
				else if (tokens[4] == "missing")
				{
					cout << "      Team:    " << tokens[0] << "      " << tokens[3] << "      " << tokens[4] << "           " << tokens[5] << "        " << tokens[6] << "        " << tokens[7] << endl << endl;
				}
				else if (tokens[5] == "missing")
				{
					cout << "      Team:    " << tokens[0] << "      " << tokens[3] << "      " << tokens[4] << "           " << tokens[5] << "        " << tokens[6] << "        " << tokens[7] << endl << endl;
				}
				else if (tokens[7] == "missing")
				{
					cout << "      Team:    " << tokens[0] << "      " << tokens[3] << "      " << tokens[4] << "           " << tokens[5] << "        " << tokens[6] << "        " << tokens[7] << endl << endl;
				}
			}
		}
	}
	myFile.close();

	cout << "\n                                           Type 1 to back: ";
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
		system("cls");
		reports();
		break;
	}
}

void viewSchoolInformation()
{
	ifstream myFile("school.txt", ios::in);
	string line, tokens[10], help;
	int choose;

	cout << "\n                           +------------------------------------------------------+" << endl;
	cout << "                           |                                                      |" << endl;
	cout << "                           |                    School information                |" << endl;
	cout << "                           |                                                      |" << endl;
	cout << "                           +------------------------------------------------------+" << endl << endl;

	cout << "                                   Name:         Town:       Address:  " << endl << endl;

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

				cout << "                     School:    " << tokens[0] << "      " << tokens[1] << "      " << tokens[2] << endl << endl;

			}
		}
	}
	myFile.close();

	cout << "\n                                           Type 1 to back: ";
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
		system("cls");
		schoolInformationMenu();
		break;
	}
}