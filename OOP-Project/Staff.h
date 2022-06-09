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
	virtual short showDay() = 0;
	virtual char showOccurence() = 0;
	virtual short showKnowledgeToGain() = 0;
	virtual short showCurrLesson() = 0;
};

class Exercise : public Lesson											//newly added
{
	short testAmount;

public:
	void setEParameters(short day_, char occurence_, short knowledgeToGain_, short currLesson_, short testAmount_);
	
	short showETestAmount();

	short showDay()
	{
		return day;
	}
	char showOccurence()
	{
		return occurence;
	}
	virtual short showKnowledgeToGain()
	{
		return knowledgeToGain;
	}
	virtual short showCurrLesson()
	{
		return currLesson;
	}
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
	
	short showDay()
	{
		return day;
	}
	char showOccurence()
	{
		return occurence;
	}
	virtual short showKnowledgeToGain()
	{
		return knowledgeToGain;
	}
	virtual short showCurrLesson()
	{
		return currLesson;
	}
};

class Staff																//super class to Professor and Academic
{
protected:
	int id;
	std::string firstName;
	std::string lastName;
public:
	virtual int showId() = 0;
	virtual std::string showFirstName() = 0;
	virtual std::string showLastName() = 0;
};

class Professor : public Staff
{
	short courseDifficulty;

public:
	Lecture lecture;

	Professor(int id_, std::string firstName_, std::string lastName_, short courseDifficulty_);						//constructor Professor
	void setPParameters(int id_, std::string firstName_, std::string lastName_, short courseDifficulty_);

	short showPCourseDifficulty();

	int showId()
	{
		return id;
	}
	std::string showFirstName()
	{
		return firstName;
	}
	std::string showLastName()
	{
		return lastName;
	}
};
																
class Academic : public Staff
{
	short courseDifficulty;
	
public:
	Exercise exercise;

	Academic(int id_, std::string firstName_, std::string lastName_, short courseDifficulty_);				//constructor Academic
	void setAParameters(int id_, std::string firstName_, std::string lastName_, short courseDifficulty_);

	short showACourseDifficulty();

	int showId()
	{
		return id;
	}
	std::string showFirstName()
	{
		return firstName;
	}
	std::string showLastName()
	{
		return lastName;
	}
};
#endif