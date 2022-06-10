#include "Afterhours.h"
#include "Student.h"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

bool isWeekend(short dayNumber_) 
{ 
    //if it is weekend do afterhours activities funcion 3 times
    short weekDay_ = fmod(dayNumber_, 7);
    if(weekDay_==5 || weekDay_==6)
        return true;
    else
        return false;
}

void Afterhours(std::vector<Student>& classroom_, bool isWeekend_ )
{
    srand(time(NULL));
    int random=std::rand()%9;
    int w;
    switch(isWeekend_)
    {
        case true:
            w=3;
            break;
        case false:
            w=1;
            break;
    }
    for(int j=0;j<w;j++)
    {
        for(int i=0; i<classroom_.size();i++)
        {
           // if(random>=0 && random<4)
                //goRelax(classroom_[i].fatigue);
            //else if(random>=4 && random<8)
               // goStudy(classroom_[i].knowledge);
            if(random==8)
            {
               // goParty(classroom_[i].fatigue, classroom_[i].knowledge);
                break;
            }
            getSleep(classroom_[i]);
        }
    }
}/*
void getSleep(short fatigue_)
{
    //passive bonus that lowers fatigue
    fatigue_-=3;
}*/
void getSleep(Student& student_)
{
    student_.setSFatigue(student_.showSFatigue()-3);        //working
};/*
void goRelax(short fatigue_)
{
    //opcianal fatiuge lowering
    fatigue_--;
}
void goStudy(short knowledge_)
{
    //opcional small knowledge gain
    knowledge_++;
}
void goParty(short &fatigue_, short &knowledge_)
{
    //random event
    //this funcion cancels sleep bonus and lowers knowledge by a point (not done here)
    knowledge_--;
    fatigue_+=3;
}*/