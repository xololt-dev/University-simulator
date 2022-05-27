#include "Classes.h"

void Classes::readProfessor()
{
    
}
void Exercise::exc(short knowledge, short Knowledgetogain)
{
    knowledge+=Knowledgetogain;
}
void Exercise::test(int id, bool *index, short knowledge, short knowledgeSkillCheck)
{
    if(knowledge>=knowledgeSkillCheck)
        index[id]=true;
}
void Lecture::lec(short knowledge, short Knowledgetogain)
{
    knowledge+=Knowledgetogain;
}
void Lecture::exam(int id, bool *index, short knowledge, short knowledgeSkillCheck)
{
    if(knowledge>=knowledgeSkillCheck)
        index[id]=true;
}