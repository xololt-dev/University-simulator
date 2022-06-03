#ifndef STAFF_H
#define STAFF_H

#include <string>

class Staff																//super class
{
protected:
	int id;
	std::string firstName;
	std::string lastName;
public:
	int showId();
	std::string showFirstName();
	std::string showLastName();
};

class Professor : public Staff
{
	short courseDifficulty;
	bool examCheck;				//Exam

	class Lecture
	{
		short day;
		char occurence;
		short knowledgeToGain;
		short currLesson;							//to track current lesson numeber(every lesson going up by one) to know when to do exam
		bool Exam(short knowledge_, short courseDifficulty_)
		{
			if (knowledge_ >= courseDifficulty_)
				return true;
			else
				return false;
		}
		short GainKnowledge(short& fatigue_, short& knowledge_, short knowledgeToGain)
		{
			//add attendence conditon if not done outside
			knowledge_ += knowledgeToGain;
			fatigue_--;
		}

	public:
		void setLParameters(short day_, char occurence_, short knowledgeToGain_, short currLesson_);
		short showLDay();
		char showLOccurence();
		short showLKnowledgeToGain();
		short showLCurrLesson();
	};
public:
	Lecture lecture;

	Professor(int id_, std::string firstName_, std::string lastName_, short courseDifficulty_, bool examCheck_);						//constructor Professor
	void setPParameters(int id_, std::string firstName_, std::string lastName_, short courseDifficulty_, bool examCheck_);

	short showPCourseDifficulty();
	bool showPExamCheck();
};
																//professors and exercise ppl
class Academic : public Staff
{
	short courseDifficulty;
	
	class Exercises				//newly added
	{
		short day;
		char occurence;
		short knowledgeToGain;
		short currLesson;
		short testAmount;
	
	public:
		void setEParameters(short day_, char occurence_, short knowledgeToGain_, short currLesson_);
		short showEDay();
		char showEOccurence();
		short showEKnowledgeToGain();
		short showECurrLesson();
		short showETestAmount();
	};
public:
	Exercises exercise;

	Academic(int id_, std::string firstName_, std::string lastName_, short courseDifficulty_);				//constructor Academic

	short showACourseDifficulty();
};
#endif