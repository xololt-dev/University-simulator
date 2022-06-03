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

public:
	Student(int id_, short knowledge_, short fatigue_, short semester_, bool studying_);					//constructor Student
	void setSParameters(int id_, short knowledge_, short fatigue_, short semester_, bool studying_);		//function to set parameters after construction
	int showSId();
	short showSKnowledge();
	short showSFatigue();
	short showSSemester();
	bool showSStudying();
	short showSAttendanceFrequency();
};
/*
* concept - not sure if gonna be implemented in final version
* 
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
};*/

#endif