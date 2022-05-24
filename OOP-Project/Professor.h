#ifndef PROFESSOR_H
#define PROFESSOR_H

#include <string>

class Professor
{
	int id;
	std::string firstName;
	std::string lastName;
	short courseDifficulty;
	short testAmount;
	bool examCheck;				//Exam
	//short dayLecture;
	//char occurrenceLecture;					//O(dd) or E(ven) or B(oth)
	//short dayExercise[7];
	//char occurrenceExercise[7];
public:
	void setPParameters(int id_, std::string firstName_, std::string lastName_, short courseDifficulty_, short testAmount_, bool examCheck_);
	int showPId();
	std::string showPFirstName();
	std::string showPLastName();
	short showPCourseDifficulty();
	short showPTestAmount();
	bool showPExamCheck();
};

class Strict : public Professor
{
	short knowledgeSkillCheck;	//Exercises
	short knowledgeToGain;		//Lectures
public:
	short showPKnowledgeSkillCheck();
	short showPKnowledgeToGain();
};

class Lenient : public Professor
{
	short knowledgeSkillCheck;	//Exercises
	short knowledgeToGain;		//Lectures	
public:
	short showPKnowledgeSkillCheck();
	short showPKnowledgeToGain();
};
#endif