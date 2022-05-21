#ifndef STUDENT_H
#define STUDENT_H

class Student
{
	int id;
	short knowledge;
	short fatigue;
	short semester;
	bool studying;

public:
	void setSParameters(int id_, short knowledge_, short fatigue_, short semester_, bool studying_);
	int showSId();
	short showSKnowledge();
	short showSFatigue();
	short showSSemester();
	bool showSStudying();
	//float tendencyToParty;
};

class Drinker : public Student
{
public:
	//musi zdac dwa razy
};

#endif