#include "Afterhours.h"
#include "Student.h"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

bool isWeekend(short dayNumber_) 
{ 
	//if it is weekend do afterhours activities funcion 3 times
	short weekDay_ = fmod(dayNumber_, 7);
	if(weekDay_ == 5 || weekDay_ == 6)
		return true;
	else
		return false;
}

void Afterhours(std::vector<Student>& classroom_, bool isWeekend_)
{
	bool sleep;
	srand(time(NULL));
	int random = std::rand() % 9;
	int w;
	switch (isWeekend_)	//student does one activity during 	the weekday and up to 3 during the weekend
	{
	case true:
		w = 3;
		break;
	case false:
		w = 1;
		break;
	}
	for (int j = 0; j < classroom_.size(); j++)	//going through all students
	{
		sleep = true;									//everyone gets chance to get sleep
		if (classroom_[j].showWorking() == true && isWeekend_ == false)  // lets assume that student works only during the week and not on weekends
		{															//if student works he has no time for anything else during the day
			goWork(classroom_[j]);
		}
		else										//all other students get to do freetime activities
		{
			for (int i = 0; i < w; i++)				//goes ones or thrice depending on weekday
			{
				if (random >= 0 && random < 4)		//activities with random chances of occuring 
					goRelax(classroom_[j]);
				else if (random >= 4 && random < 8)
					goStudy(classroom_[j]);
				else if (random == 8)			//smaller chance to go to the party then to do something else
				{
					goParty(classroom_[j]);
					sleep = false;				//student does not get sleep after a party
					break; //if students decides to party he will not be able to do anything after but it is possible for him to do something before
				}
			}
		}
		if (sleep == true)			//everyone except party goers gets to sleep
			getSleep(classroom_[j]);
	}
}
void getSleep(Student classroom_)
{
	//passive bonus that lowers fatigue
	classroom_.updateFatigue(-6);
}
void goRelax(Student classroom_)
{
	//opcianal fatiuge lowering
	classroom_.updateFatigue(-2);
}
void goStudy(Student classroom_)
{
	//opcional small knowledge gain
	classroom_.updateKnowledge(1);
}
void goParty(Student classroom_)
{
	//random event
	//this funcion cancels sleep bonus and lowers knowledge by a point (done up there in aftehours())
	classroom_.updateFatigue(4);
	classroom_.updateKnowledge(-1);
}
void goWork(Student classroom_)
{
	//if student is going to work he's going to be tired and have no time to do anything else during the weekday(done up there in aftehours())
	classroom_.updateFatigue(4);
}
//possible other random events
//just add funcion here and increase random module and else if case*/