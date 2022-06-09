#ifndef AFTERHOURS_H
#define AFTERHOURS_H

#include "Student.h"
#include <iostream>
#include <vector>

bool isWeekend(short dayNumber_);

short getSleep();

short goRelax();
short goStudy();

short goParty(std::vector<Student>& classroom_);

#endif
