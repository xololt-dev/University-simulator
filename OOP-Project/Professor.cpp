#include "Professor.h"

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
