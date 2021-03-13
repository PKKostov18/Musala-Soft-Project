#pragma once

#include <iostream>
#include <vector>
#include "Struct.h"

using namespace std;

bool isCharacter(const char character);
bool isEmailValid(const char* email);
bool isClassnameValid(string& classname);
int tokenize(string line, string* results, char delimiter);