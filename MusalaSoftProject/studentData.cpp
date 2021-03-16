#include <iostream>
#include <string>
#include <fstream>
#include "Data.h"
#include "Presentation.h"
#include "studentPresentation.h"
#include "adminPresentation.h"
#include "teacherData.h"
#include "Struct.h"

using namespace std;

bool checkAccStudentsId(STUDENT& name, STUDENT& surname, STUDENT& password)
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

				if (name.name == tokens[0])
				{
					if (surname.surname == tokens[1])
					{
						if (password.password == tokens[2])
						{
							if (tokens[0] == name.name)
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

			if (help != "") 
			{
				if (help[0] == '\n')
				{
					help.erase(0, 1);
				}

				cout << "  Account:    " << tokens[0] << "   " << tokens[1] << "   " << tokens[2] << "   " << tokens[3] << "   " << tokens[4] << "   " << tokens[5] << endl << endl;
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
	case 1:
		system("cls");
		viewMenu();
		break;
	}
}

bool checkAccExist(string name)
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

			if (help != "") 
			{
				if (help[0] == '\n')
				{
					help.erase(0, 1);
				}

				if (tokens[0] == name)
				{
					return true;
				}
			}
		}
	}
	myFile.close();
	return false;
}

void displayParticularStudentsBackend()
{
	ifstream myFile("students.txt");
	string line, tokens[10], help;

	cout << "\n                          _________________________________________________________________";
	cout << "\n                                                  Names:     " << endl << endl;

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
						cout << "                                Account:     " << tokens[0] << endl << endl;
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
	cout << "\n                                                    Names: " << endl << endl;

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
						cout << "                                   Account:    " << tokens[0]  << endl << endl;
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
	cout << "\n                                                   Names:" << endl << endl;

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
						cout << "                                   Account:    " << tokens[0] << endl << endl;
					}
				}
			}
		}
	}
	cout << "                          _________________________________________________________________" << endl;
	myFile.close();
}

void displayParticularStudentsScrumMaster()
{
	ifstream myFile("students.txt");
	string line, tokens[10], help;

	cout << "\n                          _________________________________________________________________";
	cout << "\n                                                    Names:   " << endl << endl;

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

				if (tokens[5] == "Scrum Master")
				{
					if (tokens[7] == "notuse")
					{
						cout << "                                  Account:    " << tokens[0] << endl << endl;
					}
				}
			}
		}
	}
	cout << "                          _________________________________________________________________" << endl;
	myFile.close();
}

void checkForMissingMember(string name)
{
	int choice;
	ifstream myfile("team.txt");
	ifstream myfile1("students.txt");
	ifstream myfile2("currentAcc.txt", ios::in);
	ofstream tmpFile("teamTmp.txt");
	string line, tokens[10], help, currentUser;
	bool userExist = false;

	cout << "\n                            +------------------------------------------------------+" << endl;
	cout << "                            |                                                      |" << endl;
	cout << "                            |                       Your team                      |" << endl;
	cout << "                            |                                                      |" << endl;
	cout << "                            +------------------------------------------------------+" << endl << endl;

	cout << "\n        Name:          Description:        Backend:     Frontend:     QA engineer:     Teacher:     Scrum Master:" << endl << endl;

	if (myfile2.is_open())
	{
		while (getline(myfile2, line))
		{
			currentUser = line;
		}
		myfile2.close();
	}

	if (myfile.is_open())
	{
		while (myfile.good())
		{
			getline(myfile, tokens[0]);

			tokenize(tokens[0], tokens, ',');

			help = tokens[0];

			if (help != "")
			{
				if (currentUser == tokens[7])
				{
					if (tokens[8] == "inuse")
					{
						cout << "  Team: " << tokens[0] << "       " << tokens[1] << "      " << tokens[3] << "         " << tokens[4] << "         " << tokens[5] << "          " << tokens[6] << "          " << tokens[7] << endl << endl;

						if (tokens[3] == "missing")
						{
							displayParticularStudentsBackend();
							cout << "\n\n                                  Add new Back-end student to your team: "; cin >> help;

							if (myfile.is_open())
							{
								string line;

								while (!myfile.eof())
								{
									getline(myfile, line);

									if (line != "")
									{
										tokenize(line, tokens, ',');

										if (!checkAccExist(help))
										{
											if (tmpFile.is_open())
											{
												tmpFile << tokens[0] << "," << tokens[1] << "," << tokens[2] << "," << tokens[3] << "," << tokens[4] << "," << tokens[5] << "," << tokens[6] << "," << tokens[7] << "," << tokens[8] << "," << endl;
											}
										}
										else
										{
											tmpFile << tokens[0] << "," << tokens[1] << "," << tokens[2] << "," << help << "," << tokens[4] << "," << tokens[5] << "," << tokens[6] << "," << tokens[7] << "," << tokens[8] << "," << endl;
											userExist = true;
										}
									}
								}

								if (!userExist)
								{
									cout << "                     This user doesn't exist, nothing happened" << endl;
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
								}
							}
						}
						else if (tokens[4] == "missing")
						{
							displayParticularStudentsFrontend();
							cout << "\n\n                                          Add new Front-end student to your team: "; cin >> help;

							if (myfile.is_open())
							{
								string line;

								while (!myfile.eof())
								{
									getline(myfile, line);

									if (line != "")
									{
										tokenize(line, tokens, ',');

										if (!checkAccExist(help))
										{
											if (tmpFile.is_open())
											{
												tmpFile << tokens[0] << "," << tokens[1] << "," << tokens[2] << "," << tokens[3] << " " << tokens[4] << "," << tokens[5] << "," << tokens[6] << "," << tokens[7] << "," << tokens[8] << "," << endl;
											}
										}
										else
										{
											tmpFile << tokens[0] << "," << tokens[1] << "," << tokens[2] << "," << tokens[3] << " " << help << "," << tokens[5] << "," << tokens[6] << "," << tokens[7] << "," << tokens[8] << "," << endl;
											userExist = true;
										}
									}
								}

								if (!userExist)
								{
									cout << "                     This user doesn't exist, nothing happened" << endl;
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
								}
							}
						}
						else if (tokens[5] == "missing")
						{
							displayParticularStudentsQA();
							cout << "\n\n                                     Add new QA engineer student to your team: "; cin >> help;

							if (myfile.is_open())
							{
								string line;

								while (!myfile.eof())
								{
									getline(myfile, line);

									if (line != "")
									{
										tokenize(line, tokens, ',');

										if (!checkAccExist(help))
										{
											if (tmpFile.is_open())
											{
												tmpFile << tokens[0] << "," << tokens[1] << "," << tokens[2] << "," << tokens[3] << " " << tokens[4] << "," << tokens[5] << "," << tokens[6] << "," << tokens[7] << "," << tokens[8] << "," << endl;
											}
										}
										else
										{
											tmpFile << tokens[0] << "," << tokens[1] << "," << tokens[2] << "," << tokens[3] << " " << tokens[4] << "," << help << "," << tokens[6] << "," << tokens[7] << "," << tokens[8] << "," << endl;
											userExist = true;
										}
									}
								}

								if (!userExist)
								{
									cout << "                     This user doesn't exist, nothing happened" << endl;
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
								}
							}
						}
						else if (tokens[7] == "missing")
						{
							displayParticularStudentsScrumMaster();
							cout << "\n\n                                       Add new Scrum Master student to your team: "; cin >> help;

							if (myfile.is_open())
							{
								string line;

								while (!myfile.eof())
								{
									getline(myfile, line);

									if (line != "")
									{
										tokenize(line, tokens, ',');

										if (!checkAccExist(help))
										{
											if (tmpFile.is_open())
											{
												tmpFile << tokens[0] << "," << tokens[1] << "," << tokens[2] << "," << tokens[3] << " " << tokens[4] << "," << tokens[5] << "," << tokens[6] << "," << tokens[7] << "," << tokens[8] << "," << endl;
											}
										}
										else
										{
											tmpFile << tokens[0] << "," << tokens[1] << "," << tokens[2] << "," << tokens[3] << " " << tokens[4] << "," << tokens[5] << "," << tokens[6] << "," << help << "," << tokens[8] << "," << endl;
											userExist = true;
										}
									}
								}

								if (!userExist)
								{
									cout << "                     This user doesn't exist, nothing happened" << endl;
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
								}
							}
						}
						else if (tokens[6] == "missing")
						{
							displayTeachersForTeams();
							cout << "\n\n                                          Add new teacher to your team: "; cin >> help;

							if (myfile.is_open())
							{
								string line;

								while (!myfile.eof())
								{
									getline(myfile, line);

									if (line != "")
									{
										tokenize(line, tokens, ',');

										if (!checkAccExist(help))
										{
											if (tmpFile.is_open())
											{
												tmpFile << tokens[0] << "," << tokens[1] << "," << tokens[2] << "," << tokens[3] << " " << tokens[4] << "," << tokens[5] << "," << tokens[6] << "," << tokens[7] << "," << tokens[8] << "," << endl;
											}
										}
										else
										{
											tmpFile << tokens[0] << "," << tokens[1] << "," << tokens[2] << "," << tokens[3] << " " << tokens[4] << "," << tokens[5] << "," << help << "," << tokens[7] << "," << tokens[8] << "," << endl;
											userExist = true;
										}
									}
								}

								if (!userExist)
								{
									cout << "                     This user doesn't exist, nothing happened" << endl;
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
								}
							}
						}
						else
						{
							cout << "\n                                                     Your team is fine!" << endl;
							cout << "                                             You don't miss member of your team!" << endl;
						}
					}
				}
			}
		}
	}
	myfile.close();

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

	if (myfile1.is_open())
	{
		while (myfile1.good())
		{
			getline(myfile1, tokens[0]);

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
	myfile1.close();
}

void changeStudentsStatus(string student)
{
	ifstream myfile("students.txt");
	ofstream tmpFile("studentsTmp.txt");
	string tokens[10];
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
					tmpFile << tokens[0] << "," << tokens[1] << "," << tokens[2] << "," << tokens[3] << " " << tokens[4] << "," << tokens[5] << "," << tokens[6] << "," << "use" << "," << endl;
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