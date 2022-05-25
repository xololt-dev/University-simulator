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
    void test();
};
class Lecture:public Classes
{
    void exam();
};
#endif