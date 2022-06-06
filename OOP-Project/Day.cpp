#include "Day.h"
#include "Staff.h"
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

void updateStatus(std::vector<Professor>& professors_, std::vector<Academic>& academics_, std::vector<Student>& classroom_)		//displays full information about the simulation during the current day
{
	std::cout << "Professors: \n";
	for (int i = 0; i < professors_.size(); i++)
	{
		std::cout << professors_[i].Staff::showId() << "\t" << professors_[i].Staff::showFirstName() << "\t" << professors_[i].Staff::showLastName() << "\t" << professors_[i].showPCourseDifficulty();
		std::cout << "\t" << professors_[i].lecture.showDay() << "\t" << professors_[i].lecture.showOccurence() << "\t" << professors_[i].lecture.showKnowledgeToGain() << "\t" << professors_[i].lecture.showLExamCheck() << "\n";
	}
	std::cout << "Academics: \n";
	for (int i = 0; i < academics_.size(); i++)
	{
		std::cout << academics_[i].Staff::showId() << "\t" << academics_[i].Staff::showFirstName() << "\t" << academics_[i].Staff::showLastName() << "\t" << academics_[i].showACourseDifficulty();
		std::cout << "\t" << academics_[i].exercise.showDay() << "\t" << academics_[i].exercise.showOccurence() << "\t" << academics_[i].exercise.showKnowledgeToGain() << "\t" << academics_[i].exercise.showETestAmount() << "\n";
	}
	std::cout << "Classroom: \n";
	for (int i = 0; i < classroom_.size(); i++)
	{
		std::cout << classroom_[i].showSId() << "\t" << classroom_[i].showSKnowledge() << "\t" << classroom_[i].showSFatigue() << "\t" << classroom_[i].showSSemester() << "\t" << classroom_[i].showSStudying() << "\n";
	}
}

void getLectures(std::vector<Professor>& professors_, std::vector<Student>& students_, short dayNumber_, bool isOdd_, short semesterNumber_)			//searches thru professors to figure out which Lectures happen on that day
{
	short weekDay_ = fmod(dayNumber_, 7);
	short knowledgeAfter = 0;
	short fatigueAfter = 0;

	if(dayNumber_ < 106)
	{
		for (short i = 0; i < professors_.size(); i++)
		{
			if (professors_[i].lecture.showDay() == weekDay_)
			{
				//there is a lecture from professor i on this day (without odd/even)
				if (!((professors_[i].lecture.showOccurence() == '0' && !isOdd_) || (professors_[i].lecture.showOccurence() == 'E' && isOdd_)))				//checking the situations when we don't have a lecture (6 combinations, 2 times where we don't)
				{
					/*
					there is a lecture from professor i on this day (WITH odd/even)
					give student exp if attending the lecture
					*/
					for (short j = 0; j < students_.size(); j++)
					{
						if (students_[j].showSStudying())			//checking if student is still studying 
						{
							if (students_[j].showSFatigue() < 89)
							{
								knowledgeAfter = students_[j].showSKnowledge() + professors_[i].lecture.showKnowledgeToGain();
								fatigueAfter = students_[j].showSFatigue() + 10;
								students_[j].setSParameters(students_[j].showSId(), knowledgeAfter, fatigueAfter, students_[j].showSSemester(), students_[j].showSStudying());			//probably need 2 separate functions for this aka WIP
							}
							else
							{
								knowledgeAfter = students_[j].showSKnowledge() - professors_[i].lecture.showKnowledgeToGain();
								fatigueAfter = students_[j].showSFatigue() - 10;
								students_[j].setSParameters(students_[j].showSId(), knowledgeAfter, fatigueAfter, students_[j].showSSemester(), students_[j].showSStudying());
							}
						}						
					}
				}
			}
		}
	}
	else if (dayNumber_ == 106)									//if day 106, go thru exams,	seems to be working fine
	{
		double examVariable = (14 + 8 * semesterNumber_ - pow(static_cast<double>(semesterNumber_), 2))/(7 * static_cast<double>(semesterNumber_));			//for exam function (difficulty with semsters)
		double examVariablePow = 0;																															//for pow funct. later

		for (short i = 0; i < professors_.size(); i++)
		{
			if (professors_[i].lecture.showLExamCheck())		//does the professor have an exam
			{
				if (examVariable > 1)	examVariablePow = 1 - (static_cast<double>(professors_[i].showPCourseDifficulty()) / static_cast<double>(100));			//making sure formula works (at 0.5 point it misbehaves without change)
				else	examVariablePow = static_cast<double>(professors_[i].showPCourseDifficulty()) / static_cast<double>(100);

				for (short j = 0; j < students_.size(); j++)	//go thru exam for each student
				{
					if (students_[j].showSStudying())
					{
						double eqVar = examVariable * static_cast<double>(students_[j].showSKnowledge()) / 100 * 7 / static_cast<double>(semesterNumber_);			//if failed exam, end of simulation for that person

						if (!(eqVar > 1))				//if eqVar is above 1, the student has more knowledge than max required for this semester aka automatic pass
						{
							if ((1 / (1 + pow(((1 - (eqVar / examVariable)) / eqVar), examVariablePow))) < 0.5000)	students_[j].setSParameters(students_[j].showSId(), students_[j].showSKnowledge(), students_[j].showSFatigue(), students_[j].showSSemester(), 0);
						}
					}
				}
			}			
		}
	}
}

void getExercises(std::vector<Academic>& academics_, std::vector<Student>& students_, short dayNumber_, bool isOdd_)						//searches thru academics to figure out which exercises happen on that day
{
	short weekDay_ = fmod(dayNumber_, 7);
	short knowledgeAfter = 0;
	short fatigueAfter = 0;

	for (short i = 0; i < academics_.size(); i++)
	{
		if (academics_[i].exercise.showDay() == weekDay_)
		{
			//there is an exercise with the academic on this day (without odd/even)
			if (!((academics_[i].exercise.showOccurence() == '0' && !isOdd_) || (academics_[i].exercise.showOccurence() == 'E' && isOdd_)))
			{
				/*
				there is a lecture from professor i on this day (WITH odd/even)
				give student exp if attending the lecture
				*/
				for (short j = 0; j < students_.size(); j++)
				{
					if (students_[j].showSFatigue() < 89)
					{
						knowledgeAfter = students_[j].showSKnowledge() + academics_[i].exercise.showKnowledgeToGain();
						fatigueAfter = students_[j].showSFatigue() + 10;
						students_[j].setSParameters(students_[j].showSId(), knowledgeAfter, fatigueAfter, students_[j].showSSemester(), students_[j].showSStudying());			//probably need 2 separate functions for this aka WIP
					}
					else
					{
						knowledgeAfter = students_[j].showSKnowledge() - academics_[i].exercise.showKnowledgeToGain();
						fatigueAfter = students_[j].showSFatigue() - 10;
						students_[j].setSParameters(students_[j].showSId(), knowledgeAfter, fatigueAfter, students_[j].showSSemester(), students_[j].showSStudying());
					}
				}
			}
		}
		
		//needs to have a check for tests (2 tests equals test in the middle of semester and at the end, three = 1/3 of semester, 2/3 and end etc etc)

	}
}
