#include "Day.h"
#include <math.h>

short Day::checkActivities(short dayNumber_)
{
	return fmod(dayNumber_, 7);
}

void Day::getPLessons(std::vector<Professor> &professors_, short weekDay_)
{
	for (short i = 0; i < professors_.size(); i++)
	{
		if (professors_[i].showPDayLecture() == weekDay_)
		{
			//there is a lecture from professor i on this day (without odd/even)
		}
		if (professors_[i].showPDayExercise(weekDay_))
		{
			//there is a exercise (without odd/even)
		}
	}
}

void Day::getELessons(std::vector<Academic> &academics_, short weekDay_)
{
	for (short i = 0; i < academics_.size(); i++)
	{
		/*if (academics_[i].showPDayLecture() == weekDay_)
		{
			//there is a lecture from professor i on this day (without odd/even)
		}
		if (academics_[i].showPDayExercise(weekDay_))
		{
			//there is a exercise (without odd/even)
		}*/
	}
}
