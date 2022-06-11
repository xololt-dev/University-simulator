#include "Student.h"

Student::Student(int id_, short knowledge_, short fatigue_, short semester_, bool studying_)
{
	id = id_;
	knowledge = knowledge_;
	fatigue = fatigue_;
	semester = semester_;
	studying = studying_;
}

void Student::setSParameters(int id_, short knowledge_, short fatigue_, short semester_, bool studying_)
{
	id = id_;
	knowledge = knowledge_;
	fatigue = fatigue_;
	semester = semester_;
	studying = studying_;
}

void Student::updateFatigue(short fatigue_)
{
	fatigue += fatigue_;
	if (Student::showSFatigue() < 0) fatigue = 0;
	if (Student::showSFatigue() > 100) fatigue = 100;
}

void Student::updateKnowledge(short knowledge_)
{
	knowledge += knowledge_;
	if (Student::showSKnowledge() < 0) knowledge = 0;
	if (Student::showSKnowledge() > 100) knowledge = 100;
}

int Student::showSId()
{
	return id;
}

short Student::showSKnowledge()
{
	return knowledge;
}

short Student::showSFatigue()
{
	return fatigue;
}

short Student::showSSemester()
{
	return semester;
}

bool Student::showSStudying()
{
	return studying;
}

short Student::showSAttendanceFrequency()
{
	return attendanceFrequency;
}