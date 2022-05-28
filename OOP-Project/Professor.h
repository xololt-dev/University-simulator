#ifndef PROFESSOR_H
#define PROFESSOR_H

#include <string>
/*
maybe main class Staff (id, fname, lname)
and then Professor & Academics take after Staff?
*/
class Professor
{
	int id;
	std::string firstName;
	std::string lastName;
	short courseDifficulty;
	bool examCheck;									//Exam	

	class Lecture
	{
	private:
		short day;
		char occurence;								//O(dd) or E(ven) or B(oth)
		int knowledgeToGain;
		short currLesson;							//to track current lesson numeber(every lesson going up by one) to know when to do exam
		bool Exam(short knowledge_, short courseDifficulty_)
		{
			if (knowledge_ >= courseDifficulty_)
				return true;
			else
				return false;
		}
		short GainKnowledge(/*int id_, */ short& fatigue_, short& knowledge_, int knowledgeToGain)
		{
			//add attendence conditon if not done outside
			knowledge_ += knowledgeToGain;
			fatigue_--;
		}

	public:
		void setLParameters(short day_, char occurence_, int knowledgeToGain_, short currLesson_);
		short showLDay();
		char showLOccurence();
		int showLKnowledgeToGain();
		short showLCurrLesson();
	};
public:
	Lecture lecture;

	Professor(int id_, std::string firstName_, std::string lastName_, short courseDifficulty_, bool examCheck_);
	void setPParameters(int id_, std::string firstName_, std::string lastName_, short courseDifficulty_, bool examCheck_);
	
	int showPId();
	std::string showPFirstName();
	std::string showPLastName();
	short showPCourseDifficulty();
	bool showPExamCheck();
};
																//professors and exercise ppl
class Academic
{
	int id;
	std::string firstName;
	std::string lastName;
	short courseDifficulty;
public:
	Academic(int id_, std::string firstName_, std::string lastName_, short courseDifficulty_);
	int showAId();
	std::string showAFirstName();
	std::string showALastName();
	short showACourseDifficulty();
};
#endif