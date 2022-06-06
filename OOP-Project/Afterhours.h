#ifndef AFTERHOURS_H
#define AFTERHOURS_H

#include "Student.h"
#include <iostream>
#include <vector>

bool isWeekend(short dayNumber_);

void getSleep(std::vector<Student>& classroom_);

void goRelax(std::vector<Student>& classroom_);
void goStudy(std::vector<Student>& classroom_);

void goParty(std::vector<Student>& classroom_);

#endif
