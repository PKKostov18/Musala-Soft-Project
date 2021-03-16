#pragma once

#include <iostream>
#include "Struct.h"
using namespace std;

bool checkAccStudentsId(STUDENT& name, STUDENT& surname, STUDENT& password);
void displayStudents();
bool checkAccExist(string name);
void displayParticularStudentsBackend();
void displayParticularStudentsFrontend();
void displayParticularStudentsQA();
void displayParticularStudentsScrumMaster();
void changeStudentsStatus(string student);
void checkForMissingMember(string name);