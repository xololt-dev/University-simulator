#include "Student.h"

void Student::setSParameters(int id_, short knowledge_, short fatigue_, short semester_, bool studying_)
{
	id = id_;
	knowledge = knowledge_;
	fatigue = fatigue_;
	semester = semester_;
	studying = studying_;
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
