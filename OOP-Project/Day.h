#ifndef DAY_H
#define DAY_H

#include "Professor.h"
#include "Student.h"
#include <vector>

class Day
{
	std::vector<int> weekEven;
	std::vector<int> weekOdd;
public:
	void checkActivities();
};
#endif
