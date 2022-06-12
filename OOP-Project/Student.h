#ifndef STUDENT_H
#define STUDENT_H

class Student
{
	int id;
	short knowledge;
	short fatigue;
	short semester;
	bool studying;
	bool working;
	
public:
	Student(int id_, short knowledge_, short fatigue_, short semester_, bool studying_);					//constructor Student
	void setSParameters(int id_, short knowledge_, short fatigue_, short semester_, bool studying_);		//function to set parameters after construction
	void updateKnowledge(short knowledge_);
	void updateFatigue(short fatigue_);
	void updateSemester(short semester_);

	int showSId();
	short showSKnowledge();
	short showSFatigue();
	short showSSemester();
	bool showSStudying();
	bool showWorking();
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