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
            if(random>=0 && random<4)
                goRelax(i, classroom_);
            else if(random>=4 && random<8)
                goStudy(i, classroom_);
            else if(random==8)
            {
                goParty(i, classroom_);
                break;
            }
            getSleep(i, classroom_);
        }
    }
}
void getSleep(int i_, std::vector<Student>& classroom_)
{
    //passive bonus that lowers fatigue
    classroom_[i_].updateFatigue(-3);
}
void goRelax(int i_, std::vector<Student>& classroom_)
{
    //opcianal fatiuge lowering
    classroom_[i_].updateFatigue(-1);
}
void goStudy(int i_, std::vector<Student>& classroom_)
{
    //opcional small knowledge gain
    classroom_[i_].updateKnowledge(1);
}
void goParty(int i_, std::vector<Student>& classroom_) 
{
    //random event
    //this funcion cancels sleep bonus and lowers knowledge by a point (done up there in aftehours())
    classroom_[i_].updateFatigue(3);
    classroom_[i_].updateKnowledge(-2);
}
//possible other random events
//just add funcion here and increase random module and else if case