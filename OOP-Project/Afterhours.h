#ifndef AFTERHOURS_H
#define AFTERHOURS_H

#include "Student.h"
#include <iostream>
#include <vector>

bool isWeekend(short dayNumber_);
void Afterhours(std::vector<Student>& classroom_, bool isWeekend_ );
//void getSleep(short fatigue_);			//how about we just pass the object. do for all
void getSleep(Student& student_);
void goRelax(short &fatigue_);
void goStudy(short &knowldege_);

void goParty(short &fatigue_, short &knowldege_);

#endif
