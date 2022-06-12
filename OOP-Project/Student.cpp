#include "Student.h"

Student::Student(int id_, short knowledge_, short fatigue_, short semester_, bool studying_, bool working_)
{
	id = id_;
	knowledge = knowledge_;
	fatigue = fatigue_;
	semester = semester_;
	studying = studying_;
	working = working_;
}

void Student::setSParameters(int id_, short knowledge_, short fatigue_, short semester_, bool studying_, bool working_)
{
	id = id_;
	knowledge = knowledge_;
	fatigue = fatigue_;
	semester = semester_;
	studying = studying_;
	working = working_;
}

void Student::updateFatigue(short fatigue_)
{
	fatigue += fatigue_;
	if (Student::showFatigue() < 0) fatigue = 0;
	if (Student::showFatigue() > 100) fatigue = 100;
}

void Student::updateKnowledge(short knowledge_)
{
	knowledge += knowledge_;
	if (Student::showKnowledge() < 0) knowledge = 0;
	if (Student::showKnowledge() > 100) knowledge = 100;
}

void Student::updateSemester()
{
	semester++;
}

void Student::updateStudying()
{
	studying = 0;
}

int Student::showSId()
{
	return id;
}

short Student::showKnowledge()
{
	return knowledge;
}

short Student::showFatigue()
{
	return fatigue;
}

short Student::showSemester()
{
	return semester;
}

bool Student::showStudying()
{
	return studying;
}

bool Student::showWorking()
{
	return working;
}