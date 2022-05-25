#include "Professor.h"

Professor::Professor(int id_, std::string firstName_, std::string lastName_, short courseDifficulty_)
{
	id = id_;
	firstName = firstName_;
	lastName = lastName_;
	courseDifficulty = courseDifficulty_;
}

void Professor::setPParameters(int id_, std::string firstName_, std::string lastName_, short courseDifficulty_, short testAmount_, bool examCheck_)
{
	id = id_;
	firstName = firstName_;
	lastName = lastName_;
	courseDifficulty = courseDifficulty_;
	testAmount = testAmount_;
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

short Professor::showPTestAmount()
{
	return testAmount;
}

bool Professor::showPExamCheck()
{
	return examCheck;
}

short Professor::showPDayLecture()
{
	return dayLecture;
}

char Professor::showPOccurenceLecture()
{
	return occurrenceLecture;
}

bool Professor::showPDayExercise(short day_)
{
	return dayExercise[day_];
}

char Professor::showPOccurrenceExercise(short day_)
{
	return occurrenceExercise[day_];
}

short Lenient::showPKnowledgeSkillCheck()
{
	return knowledgeSkillCheck;
}

short Lenient::showPKnowledgeToGain()
{
	return knowledgeToGain;
}

short Strict::showPKnowledgeSkillCheck()
{
	return knowledgeSkillCheck;
}

short Strict::showPKnowledgeToGain()
{
	return knowledgeToGain;
}
