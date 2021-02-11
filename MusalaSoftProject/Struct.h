#include <iostream>
#include <string>
using namespace std;

#pragma once

struct STUDENT
{
	string name;
	string surname;
	string password;
	string classname;
	string role;
	string email;
};

struct TEAM
{
	string name;
	string description;
	string email;
};

struct TEACHER
{
	string name;
	string surname;
	string email;
};

struct SCHOOL
{
	string name;
	string town;
	string address;
};