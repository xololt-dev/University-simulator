#include "Professor.h"

void Professor::setPParameters(int id_, std::string firstName_, std::string lastName_, short courseDifficulty_, short testAmount_)
{
	id = id_;
	firstName = firstName_;
	lastName = lastName_;
	courseDifficulty = courseDifficulty_;
	testAmount = testAmount_;
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
	return std::string(lastName);
}

short Professor::showPCourseDifficulty()
{
	return courseDifficulty;
}

short Professor::showPTestAmount()
{
	return testAmount;
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
