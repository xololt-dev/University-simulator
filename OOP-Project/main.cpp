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
#include "Save.h"

const short semesterLength = 105;
const short semesterAmount = 7;

std::vector<Professor> staff;										//vectors to contain Professors and Students
std::vector<Academic> academics;
std::vector<Student> classroom;
std::vector<int> weekEven;
std::vector<int> weekOdd;

short dayNumber = 1;												//tracking days passed
bool evenWeek = 1;

int main(int argc, char* argv[])
{
	Student one(1, 10, 0, 1, 1);
	Professor two(2, "Janusz", "Brodacz", 10);

	unsigned char button;

	//three.setPParameters(3, "Januszos", "Brodaczos", 11, 3, 0);
	//staff.push_back(three);

	one.setSParameters(1, 10, 0, 1, 1);
	two.setPParameters(2, "Janusz", "Brodacz", 10, 2, 0);

	getFromFile(argv[1], staff, academics, classroom);

	std::cout << one.showSKnowledge() << "\t" << two.showPLastName();			//short test
	std::cout << "\t" << staff.size() << "\n";
	for (int i = 0; i < staff.size(); i++)															//check if loading from file works
	{
		std::cout << staff[i].showPId() << "\t" << staff[i].showPFirstName() << "\t" << staff[i].showPLastName() << "\t" << staff[i].showPCourseDifficulty() << "\n";
	}
	for (int i = 0; i < academics.size(); i++)
	{
		std::cout << academics[i].showAId() << "\t" << academics[i].showAFirstName() << "\t" << academics[i].showALastName() << "\t" << academics[i].showACourseDifficulty() << "\n";
	}
	for (int i = 0; i < classroom.size(); i++)
	{
		std::cout << classroom[i].showSId() << "\t" << classroom[i].showSKnowledge() << "\t" << classroom[i].showSFatigue() << "\t" << classroom[i].showSSemester() << "\t" << classroom[i].showSStudying() << "\n";
	}
	
	do
	{																			//after each day
		button = _getch();
		if (static_cast <int>(button) == 13)
		{
			std::cout << "Day: " << dayNumber << "\n";
			dayNumber++;
		}
	} while (static_cast <int>(button) != 27);

	return 0;
}