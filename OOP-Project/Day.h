#ifndef DAY_H
#define DAY_H

#include "Professor.h"
#include "Student.h"
#include <iostream>
#include <vector>

bool isOdd(short dayNumber_);

void updateStatus(std::vector<Professor>& professors_, std::vector<Academic>& academics_, std::vector<Student>& classroom_);

void getLectures(std::vector<Professor>& professors_, std::vector<Student>& students_, short dayNumber_, bool isOdd_);
void getExercises(std::vector<Academic>& academics_, short dayNumber_, bool isOdd_);

#endif
