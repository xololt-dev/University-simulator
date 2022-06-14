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

void Afterhours(std::vector<Student>& classroom_, bool isWeekend_, std::vector<short>& simulationParameters_)
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
			goWork(classroom_[j], simulationParameters_[5]);
		}
		else										//all other students get to do freetime activities
		{
			for (int i = 0; i < w; i++)				//goes ones or thrice depending on weekday
			{
				if (random >= 0 && random < 4)		//activities with random chances of occuring 
					goRelax(classroom_[j], simulationParameters_[1]);
				else if (random >= 4 && random < 8)
					goStudy(classroom_[j], simulationParameters_[2]);
				else if (random == 8)			//smaller chance to go to the party then to do something else
				{
					goParty(classroom_[j], simulationParameters_[3], simulationParameters_[4]);
					sleep = false;				//student does not get sleep after a party
					break; //if students decides to party he will not be able to do anything after but it is possible for him to do something before
				}
			}
		}
		if (sleep == true)			//everyone except party goers gets to sleep
			getSleep(classroom_[j], simulationParameters_[0]);
	}
}
void getSleep(Student classroom_, short fatigue_)
{
	//passive bonus that lowers fatigue
	classroom_.updateFatigue(fatigue_);
}
void goRelax(Student classroom_, short fatigue_)
{
	//opcianal fatiuge lowering
	classroom_.updateFatigue(fatigue_);
}
void goStudy(Student classroom_, short knowledge_)
{
	//opcional small knowledge gain
	classroom_.updateKnowledge(knowledge_);
}
void goParty(Student classroom_, short fatigue_, short knowledge_)
{
	//random event
	//this funcion cancels sleep bonus and lowers knowledge by a point (done up there in aftehours())
	classroom_.updateFatigue(fatigue_);
	classroom_.updateKnowledge(knowledge_);
}
void goWork(Student classroom_, short fatigue_)
{
	//if student is going to work he's going to be tired and have no time to do anything else during the weekday(done up there in aftehours())
	classroom_.updateFatigue(fatigue_);
}
//possible other random events
//just add funcion here and increase random module and else if case*/