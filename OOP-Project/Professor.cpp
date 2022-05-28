#include "Professor.h"

Professor::Professor(int id_, std::string firstName_, std::string lastName_, short courseDifficulty_, bool examCheck_)
{
	id = id_;
	firstName = firstName_;
	lastName = lastName_;
	courseDifficulty = courseDifficulty_;
	examCheck = examCheck_;
}

void Professor::setPParameters(int id_, std::string firstName_, std::string lastName_, short courseDifficulty_, bool examCheck_)
{
	id = id_;
	firstName = firstName_;
	lastName = lastName_;
	courseDifficulty = courseDifficulty_;
	examCheck = examCheck_;
}

int Professor::showPId()
{
	return id;
}

std::string Professor::showPFirstName()
{
	return firstName;
}

std::string Professor::showPLastName()
{
	return lastName;
}

short Professor::showPCourseDifficulty()
{
	return courseDifficulty;
}

bool Professor::showPExamCheck()
{
	return examCheck;
}

void Professor::Lecture::setLParameters(short day_, char occurence_, int knowledgeToGain_, short currLesson_)
{
	day = day_;
	occurence = occurence_;
	knowledgeToGain = knowledgeToGain_;
	currLesson = currLesson_;
}

short Professor::Lecture::showLDay()
{
	return day;
}

char Professor::Lecture::showLOccurence()
{
	return occurence;
}

int Professor::Lecture::showLKnowledgeToGain()
{
	return knowledgeToGain;
}

short Professor::Lecture::showLCurrLesson()
{
	return currLesson;
}

Academic::Academic(int id_, std::string firstName_, std::string lastName_, short courseDifficulty_)
{
	id = id_;
	firstName = firstName_;
	lastName = lastName_;
	courseDifficulty = courseDifficulty_;
}

int Academic::showAId()
{
	return id;
}

std::string Academic::showAFirstName()
{
	return firstName;
}

std::string Academic::showALastName()
{
	return lastName;
}

short Academic::showACourseDifficulty()
{
	return courseDifficulty;
}
