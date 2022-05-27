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
	short testAmount;
	bool examCheck;				//Exam
	short dayLecture;
	char occurrenceLecture;					//O(dd) or E(ven) or B(oth)
	bool dayExercise[5];
	char occurrenceExercise[5];
	/*
	class Lecture
	{
		short day;
	}
	*/
public:
	//Professor();
	Professor(int id_, std::string firstName_, std::string lastName_, short courseDifficulty_);
	void setPParameters(int id_, std::string firstName_, std::string lastName_, short courseDifficulty_, short testAmount_, bool examCheck_);
	int showPId();
	std::string showPFirstName();
	std::string showPLastName();
	short showPCourseDifficulty();
	short showPTestAmount();
	bool showPExamCheck();
	short showPDayLecture();
	char showPOccurenceLecture();
	bool showPDayExercise(short day_);
	char showPOccurrenceExercise(short day_);
};
																//professors and exercise ppl

/*class Strict : public Professor
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
};*/

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