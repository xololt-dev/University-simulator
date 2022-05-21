#include <iostream>
#include "Student.h"
#include "Professor.h"

int main()
{
	Student one;
	Professor two;

	one.setSParameters(1,10,0,1,1);
	two.setPParameters(2, "Janusz", "Brodacz", 10, 2);

	std::cout << one.showSKnowledge() <<"\t"<< two.showPLastName();

	return 0;
}