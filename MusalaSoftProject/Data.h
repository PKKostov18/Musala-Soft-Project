#include <iostream>
#include "Struct.h"
using namespace std;

#pragma once

string checkAcc(STUDENT& username, STUDENT& password);
bool isCharacter(const char Character);
bool isEmailValid(const char* email);
bool isClassnameValid(string& classname);