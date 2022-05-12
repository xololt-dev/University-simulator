#include <iostream>
#include "Student.h"

int main()
{
	S::Student one;
	one.tendencyToParty = 0.7;
	std::cout << one.tendencyToParty;
	return 0;
}