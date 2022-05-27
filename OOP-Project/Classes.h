#ifndef EXERCISE_H
#define EXERCISE_H

#include "Professor.h"

class Classes
{
    short day;
    char occurrence;
    
public:
    void readProfessor(); //receving vector of Proffesors
    
};
class Exercise:public Classes
{
public:
    void exc(short knowledge, short Knowledgetogain);
    void test(int id, bool *index, short knowledge, short knowledgeSkillCheck);
};
class Lecture:public Classes
{
public:
    void lec(short knowledge, short Knowledgetogain);
    void exam(int id, bool *index, short knowledge, short knowledgeSkillCheck);
};
#endif