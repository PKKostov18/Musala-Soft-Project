#include <iostream>
#include <string>
using namespace std;

#pragma once

struct STUDENT
{
	string name = "";
	string surname = "";
	string password = "";
	string classname = "";
	string role = "";
	string email = "";
	string id = "";
};

struct TEAM
{
	string name = "";
	string description = "";
	string date = "";
	string teacher = "";
	string teammatesBackend = "";
	string teammatesFrontend = "";
	string teammatesQA = "";
	string status = "";
};

struct TEACHER
{
	string name = "";
	string surname = "";
	string email = "";	
	string id = "";
};

struct SCHOOL
{
	string name = "";
	string town = "";
	string address = "";
};