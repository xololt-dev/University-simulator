#include "Day.h"
#include "Professor.h"
#include "Student.h"
#include <iostream>
#include <vector>
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

void updateStatus(std::vector<Professor>& professors_, std::vector<Academic>& academics_, std::vector<Student>& classroom_)
{
	std::cout << "Professors: \n";
	for (int i = 0; i < professors_.size(); i++)															//check if loading from file works
	{
		std::cout << professors_[i].showPId() << "\t" << professors_[i].showPFirstName() << "\t" << professors_[i].showPLastName() << "\t" << professors_[i].showPCourseDifficulty() << "\t" << professors_[i].showPExamCheck();
		std::cout << "\t" << professors_[i].lecture.showLDay() << "\t" << professors_[i].lecture.showLOccurence() << "\t" << professors_[i].lecture.showLKnowledgeToGain() << "\n";
	}
	std::cout << "Academics: \n";
	for (int i = 0; i < academics_.size(); i++)
	{
		std::cout << academics_[i].showAId() << "\t" << academics_[i].showAFirstName() << "\t" << academics_[i].showALastName() << "\t" << academics_[i].showACourseDifficulty() << "\n";
	}
	std::cout << "Classroom: \n";
	for (int i = 0; i < classroom_.size(); i++)
	{
		std::cout << classroom_[i].showSId() << "\t" << classroom_[i].showSKnowledge() << "\t" << classroom_[i].showSFatigue() << "\t" << classroom_[i].showSSemester() << "\t" << classroom_[i].showSStudying() << "\n";
	}
}

void getLectures(std::vector<Professor>& professors_, std::vector<Student>& students_, short dayNumber_, bool isOdd_)			//mini test passed - but needs testing on full data set
{
	short weekDay_ = fmod(dayNumber_, 7);
	short knowledgeAfter = 0;
	short fatigueAfter = 0;

	for (short i = 0; i < professors_.size(); i++)
	{
		if (professors_[i].lecture.showLDay() == weekDay_)
		{
			//there is a lecture from professor i on this day (without odd/even)
			if (!((professors_[i].lecture.showLOccurence() == '0' && !isOdd_) || (professors_[i].lecture.showLOccurence() == 'E' && isOdd_)))				//checking the situations when we don't have a lecture (6 combinations, 2 times where we don't)
			{
				/*
				there is a lecture from professor i on this day (WITH odd/even)			
				give student exp if attending the lecture
				*/
				for (short j = 0; j < students_.size(); j++)
				{
					if (students_[j].showSFatigue() < 89)
					{
						knowledgeAfter = students_[j].showSKnowledge() + (professors_[i].showPCourseDifficulty())/5;
						fatigueAfter = students_[j].showSFatigue() + 10;
						students_[j].setSParameters(students_[j].showSId(), knowledgeAfter, fatigueAfter, students_[j].showSSemester(), students_[j].showSStudying());			//probably need 2 separate functions for this
					}
					else
					{
						knowledgeAfter = students_[j].showSKnowledge() - (professors_[i].showPCourseDifficulty()) / 5;
						fatigueAfter = students_[j].showSFatigue() - 10;
						students_[j].setSParameters(students_[j].showSId(), knowledgeAfter, fatigueAfter, students_[j].showSSemester(), students_[j].showSStudying());
					}
				}
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
