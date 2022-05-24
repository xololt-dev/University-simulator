/*
semester - does week contain only working days?
professors - in table/vector
professors - max cap or not?
mod 7 = day				+			mod 2 = even/odd

many objects with vectors
https://stackoverflow.com/questions/13091302/stdvector-for-parent-and-child-class
*/

#include <iostream>
#include <vector>
#include "Student.h"
#include "Professor.h"

std::vector<Professor> staff;										//vectors to contain Professors and Students
std::vector<Student> classroom;
std::vector<Strict> staffel;

int main(int argc, char* argv[])
{
	Student one;
	Professor two;
	Strict three;


	three.setPParameters(3, "Januszos", "Brodaczos", 11, 3);
	staff.push_back(three);
	
	staffel.emplace_back();

	one.setSParameters(1,10,0,1,1);
	two.setPParameters(2, "Janusz", "Brodacz", 10, 2);
	

	std::cout << one.showSKnowledge() << "\t" << two.showPLastName();			//short test
	std::cout <<"\t" << staff[0].showPCourseDifficulty()<< "\t" << staffel[0].showPCourseDifficulty();

	return 0;
}