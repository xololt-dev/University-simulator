#ifndef DAY_H
#define DAY_H

#include "Professor.h"
#include "Student.h"
#include <vector>

bool isOdd(short dayNumber_);
void getLectures(std::vector<Professor>& professors_, short dayNumber_, bool isOdd_);
void getExercises(std::vector<Academic>& academics_, short dayNumber_, bool isOdd_);

#endif
