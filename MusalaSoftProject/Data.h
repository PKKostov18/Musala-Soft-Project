#include <iostream>
#include <vector>
#include "Struct.h"
using namespace std;

#pragma once

string checkAcc(STUDENT& username, STUDENT& password);
string checkAccStudentsId(STUDENT id, STUDENT& username);
string checkAccTeachersId(STUDENT id, STUDENT& username);
bool isCharacter(const char character);
bool isEmailValid(const char* email);
bool isClassnameValid(string& classname);
int tokenize(string line, string* results, char delimiter);
void displayStudents();
void displayTeachers();
vector<STUDENT> displayParticularStudents(string role);
