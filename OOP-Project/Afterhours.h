#ifndef AFTERHOURS_H
#define AFTERHOURS_H

#include "Student.h"
#include <iostream>
#include <vector>

bool isWeekend(short dayNumber_);

void getSleep(Student classroom_, short fatigue_);
void goWork(Student classroom_, short fatigue_);

void goRelax(Student classroom_, short fatigue_);
void goStudy(Student classroom_, short knowledge_);

void goParty(Student classroom_, short fatigue_, short knowledge_);

void Afterhours(std::vector<Student>& classroom_, bool isWeekend_, std::vector<short>& simulationParameters_);

#endif
