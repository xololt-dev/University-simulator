#ifndef AFTERHOURS_H
#define AFTERHOURS_H

#include "Student.h"
#include <iostream>
#include <vector>

bool isWeekend(short dayNumber_);
void Afterhours(std::vector<Student>& classroom_, bool isWeekend_ );

void getSleep(int i_, std::vector<Student>& classroom_);

void goRelax(int i_, std::vector<Student>& classroom_);
void goStudy(int i_, std::vector<Student>& classroom_);

void goParty(int i_, std::vector<Student>& classroom_);

#endif
