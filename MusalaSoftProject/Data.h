#include <iostream>
#include <vector>
#include "Struct.h"
using namespace std;

#pragma once

bool checkAccStudentsId(STUDENT& username, STUDENT& password);
bool checkAccTeachersId(STUDENT& username, STUDENT& password);
bool checkAccAdminId(STUDENT& username, STUDENT& password);
bool isCharacter(const char character);
bool isEmailValid(const char* email);
bool isClassnameValid(string& classname);
int tokenize(string line, string* results, char delimiter);
void displayStudents();
void displayTeachers();
void displayTeams();
void displayParticularStudentsBackend();
void displayParticularStudentsFrontend();
void displayParticularStudentsQA();
void displayTeachersForTeams();
void changeStudentsStatus(string& student);
void deleteAccount();
void editPassword();
