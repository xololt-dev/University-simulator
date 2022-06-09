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
                goRelax();
            else if(random>=4 && random<8)
                goStudy();
            else if(random==8)
            {
                goParty(classroom_[i].fatigue, classroom_[i].knowledge);
                break;
            }
            getSleep(classroom_[i].fatigue);
        }
    }
}
short getSleep()
{
    //passive bonus that lowers fatigue
    return -3;
}
short goRelax()
{
    //opcianal fatiuge lowering
    return -1;
}
short goStudy()
{
    //opcional small knowledge gain
    return 1;
}
void goParty()
{
    //random event
    //this funcion cancels sleep bonus and lowers knowledge by a point (not done here)
    return -1, 3;
}