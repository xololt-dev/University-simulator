#include "Day.h"
#include <math.h>

bool isOdd(short dayNumber_)
{
	return fmod(ceil(dayNumber_ / static_cast<double>(7)), 2);			//check if week is odd
}

/*
function here so that we can understand if the student is going to attend the school today
if yes, go thru todays activities (getLectures, getExercises)
otherwise, reduce fatigue
*/

void getLectures(std::vector<Professor>& professors_, short dayNumber_, bool isOdd_)
{
	short weekDay_ = fmod(dayNumber_, 7);

	for (short i = 0; i < professors_.size(); i++)
	{
		if (professors_[i].showPDayLecture() == weekDay_)
		{
			//there is a lecture from professor i on this day (without odd/even)
			if (!((professors_[i].showPOccurenceLecture() == '0' && !isOdd_) || (professors_[i].showPOccurenceLecture() == 'E' && isOdd_)))				//checking the situations when we don't have a lecture (6 combinations, 2 times where we don't)
			{
				/*
				there is a lecture from professor i on this day (WITH odd/even)			
				give student exp if attending the lecture
				*/
			}
		}
	}
}

void getExercises(std::vector<Academic>& academics_, short dayNumber_, bool isOdd_)
{
	short weekDay_ = fmod(dayNumber_, 7);

	for (short i = 0; i < academics_.size(); i++)
	{
		/*if (academics_[i].showPDayLecture() == weekDay_)
		{
			//there is a lecture from professor i on this day (without odd/even)
		}
		if (academics_[i].showPDayExercise(weekDay_))
		{
			//there is a exercise (without odd/even)
		}
		
		needs to have a check for tests (2 tests equals test in the middle of semester and at the end, three = 1/3 of semester, 2/3 and end etc etc)
		*/
	}
}
