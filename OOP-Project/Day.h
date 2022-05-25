#ifndef DAY_H
#define DAY_H

#include "Professor.h"
#include "Student.h"
#include <vector>

class Day
{
	std::vector<std::vector<int>> weekEven;				// {id(int), type(char)}
	std::vector<std::vector<int>> weekOdd;
public:
	short checkActivities(short dayNumber_);
	void getPLessons(std::vector<Professor> &professors_, short weekDay_);
	void getELessons(std::vector<Academic> &academics_, short weekDay_);
};

#endif
