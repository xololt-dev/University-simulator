/*
semester - does week contain only working days?
professors - in table/vector
professors - max cap or not?
mod 7 = day				+			mod 2 = even/odd
*/

#include <iostream>
#include "Student.h"
#include "Professor.h"

int main()
{
	Student one;
	Professor two;

	one.setSParameters(1,10,0,1,1);
	two.setPParameters(2, "Janusz", "Brodacz", 10, 2);

	std::cout << one.showSKnowledge() <<"\t"<< two.showPLastName();			//short test

	return 0;
}