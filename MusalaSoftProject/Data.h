#include <iostream>
#include <vector>
#include "Struct.h"
using namespace std;

#pragma once

bool checkAccStudents(STUDENT& username, STUDENT& password);
bool checkAccTeachers(STUDENT& username, STUDENT& password);
bool checkAccAdmin(STUDENT& username, STUDENT& password);
void checkAccStudentsId(STUDENT& username);
void checkAccTeachersId(STUDENT& username);
void checkAccAdminId(STUDENT& username);
bool isCharacter(const char character);
bool isEmailValid(const char* email);
bool isClassnameValid(string& classname);
int tokenize(string line, string* results, char delimiter);
void displayStudents();
void displayTeachers();
void displayParticularStudentsBackend();
void displayParticularStudentsFrontend();
void displayParticularStudentsQA();
void displayTeachersForTeams();
void editUsername(string student);
void deleteAccount();
void editUsername();
