#pragma once

#include <iostream>
#include "Struct.h"

using namespace std;

bool checkAccAdminId(STUDENT& name, STUDENT& surname, STUDENT& password);
void deleteAccount();
void deleteTeams();
void editPassword();
void editTeamName();
void editTeamStatus();
void displayStudentsInParticularTeam();
void displayTeachersWithNoTeam();
void displayTeamsWithNotFullMembers();
void viewSchoolInformation();