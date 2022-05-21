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

public:
	void setPParameters(int id_, std::string firstName_, std::string lastName_, short courseDifficulty_, short testAmount_);
	int showPId();
	std::string showPFirstName();
	std::string showPLastName();
	short showPCourseDifficulty();
	short showPTestAmount();
};

class Strict : public Professor
{
	short knowledgeSkillCheck;	//Exercises
	short knowledgeToGain;		//Lectures
	bool examCheck;				//Exam
public:
	short showPKnowledgeSkillCheck();
	short showPKnowledgeToGain();
};

class Lenient : public Professor
{
	short knowledgeSkillCheck;	//Exercises
	short knowledgeToGain;		//Lectures
	bool examCheck;				//Exam
public:
	short showPKnowledgeSkillCheck();
	short showPKnowledgeToGain();
};
#endif