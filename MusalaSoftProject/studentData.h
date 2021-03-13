#pragma once

#include <iostream>
#include "Struct.h"
using namespace std;

bool checkAccStudentsId(STUDENT& username, STUDENT& password);
void displayStudents();
void displayParticularStudentsBackend();
void displayParticularStudentsFrontend();
void displayParticularStudentsQA();
void changeStudentsStatus(string student);