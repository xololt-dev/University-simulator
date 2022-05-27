#ifndef STUDENT_H
#define STUDENT_H

class Student
{
	int id;
	short knowledge;
	short fatigue;
	short semester;
	bool studying;
	short attendanceFrequency;
	bool index[];

public:
	void setSParameters(int id_, short knowledge_, short fatigue_, short semester_, bool studying_);
	int showSId();
	short showSKnowledge();
	short showSFatigue();
	short showSSemester();
	bool showSStudying();
	short showSAttendanceFrequency();
};

class Drinker : public Student
{
	short partyingFrequency;
	short studyingFrequency;
public:
	//must pass two times - function needed
};

class Crammer : public Student
{
	short partyingFrequency;
	short studyingFrequency;
public:
	//can fail first time - function needed
};

#endif