#ifndef STAFF_H
#define STAFF_H

#include <string>

class Lesson															//super class to Lecture and Exercise
{
protected:
	short day;
	char occurence;
	short knowledgeToGain;
	short currLesson;							//to track current lesson numeber(every lesson going up by one) to know when to do exam

public:
	short showDay();
	char showOccurence();
	short showKnowledgeToGain();
	short showCurrLesson();
};

class Exercise : public Lesson											//newly added
{
	short testAmount;

public:
	void setEParameters(short day_, char occurence_, short knowledgeToGain_, short currLesson_, short testAmount_);

	short showETestAmount();
};

class Lecture : public Lesson
{
	bool examCheck;				//Exam
	/*
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
	*/
public:
	void setLParameters(short day_, char occurence_, short knowledgeToGain_, short currLesson_, bool examCheck_);

	bool showLExamCheck();
};

class Staff																//super class to Professor and Academic
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

public:
	Lecture lecture;

	Professor(int id_, std::string firstName_, std::string lastName_, short courseDifficulty_);						//constructor Professor
	void setPParameters(int id_, std::string firstName_, std::string lastName_, short courseDifficulty_);

	short showPCourseDifficulty();	
};
																
class Academic : public Staff
{
	short courseDifficulty;
	
public:
	Exercise exercise;

	Academic(int id_, std::string firstName_, std::string lastName_, short courseDifficulty_);				//constructor Academic
	void setAParameters(int id_, std::string firstName_, std::string lastName_, short courseDifficulty_);

	short showACourseDifficulty();
};
#endif