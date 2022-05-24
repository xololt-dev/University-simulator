/*
semester - full week
7 classes per day MAX	=>			2*5*7 = 70 professors max
mod 7 = day				+			mod 2 = even/odd

professors - in table/vector
professors - max cap or not?

many objects with vectors
https://stackoverflow.com/questions/13091302/stdvector-for-parent-and-child-class
*/

#include <iostream>
#include <vector>
#include <conio.h>
#include "Student.h"
#include "Professor.h"
#include "Day.h"

std::vector<Professor> staff;										//vectors to contain Professors and Students
std::vector<Student> classroom;
std::vector<Strict> staffel;
std::vector<int> weekEven;
std::vector<int> weekOdd;

void Day();

int main(int argc, char* argv[])
{
	Student one;
	Professor two;
	Strict three;

	unsigned char button;
	int countDay = 0;

	three.setPParameters(3, "Januszos", "Brodaczos", 11, 3, 0);
	staff.push_back(three);
	
	staffel.emplace_back();

	one.setSParameters(1,10,0,1,1);
	two.setPParameters(2, "Janusz", "Brodacz", 10, 2, 0);
	
	std::cout << one.showSKnowledge() << "\t" << two.showPLastName();			//short test
	std::cout <<"\t" << staff[0].showPCourseDifficulty()<< "\t" << staffel[0].showPCourseDifficulty();

	do
	{																			//after each day
		button = _getch();
		if (static_cast <int>(button) == 13)
		{
			std::cout << "Day: " << countDay << "\n";
			countDay++;
		}
	} while (static_cast <int>(button) != 27);

	return 0;
}

void Day()
{

}