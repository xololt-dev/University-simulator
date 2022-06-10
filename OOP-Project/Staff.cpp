#include "Staff.h"

void Lecture::setLParameters(short day_, char occurence_, short knowledgeToGain_, short currLesson_, bool examCheck_)
{
	day = day_;
	occurence = occurence_;
	knowledgeToGain = knowledgeToGain_;
	currLesson = currLesson_;
	examCheck = examCheck_;
}

bool Lecture::showLExamCheck()
{
	return examCheck;
}

void Exercise::setEParameters(short day_, char occurence_, short knowledgeToGain_, short currLesson_, short testAmount_)
{
	day = day_;
	occurence = occurence_;
	knowledgeToGain = knowledgeToGain_;
	currLesson = currLesson_;
	testAmount = testAmount_;
}

short Exercise::showETestAmount()
{
	return testAmount;
}
/*
int Staff::showId()
{
	return id;
}

std::string Staff::showFirstName()
{
	return firstName;
}

std::string Staff::showLastName()
{
	return lastName;
}*/

Professor::Professor(int id_, std::string firstName_, std::string lastName_, short courseDifficulty_)
{
	id = id_;
	firstName = firstName_;
	lastName = lastName_;
	courseDifficulty = courseDifficulty_;
}

void Professor::setPParameters(int id_, std::string firstName_, std::string lastName_, short courseDifficulty_)
{
	id = id_;
	firstName = firstName_;
	lastName = lastName_;
	courseDifficulty = courseDifficulty_;
}

short Professor::showPCourseDifficulty()
{
	return courseDifficulty;
}
/*
void Professor::Lesson::setLParameters(short day_, char occurence_, short knowledgeToGain_, short currLesson_)
{
	day = day_;
	occurence = occurence_;
	knowledgeToGain = knowledgeToGain_;
	currLesson = currLesson_;
}

short Professor::Lesson::showDay()
{
	return day;
}

char Professor::Lesson::showOccurence()
{
	return occurence;
}

short Professor::Lesson::showKnowledgeToGain()
{
	return knowledgeToGain;
}

short Professor::Lesson::showCurrLesson()
{
	return currLesson;
}*/

Academic::Academic(int id_, std::string firstName_, std::string lastName_, short courseDifficulty_)
{
	id = id_;
	firstName = firstName_;
	lastName = lastName_;
	courseDifficulty = courseDifficulty_;
}

void Academic::setAParameters(int id_, std::string firstName_, std::string lastName_, short courseDifficulty_)
{
	id = id_;
	firstName = firstName_;
	lastName = lastName_;
	courseDifficulty = courseDifficulty_;
}

short Academic::showACourseDifficulty()
{
	return courseDifficulty;
}