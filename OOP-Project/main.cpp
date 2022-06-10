/*
semester - full week
7 classes per day MAX	=>			2*5*7 = 70 professors max
mod 7 = day				+			mod 2 = even/odd

professors - in table/vector
professors - max cap or not?
*/

#include <iostream>
#include <vector>
#include <conio.h>
#include <math.h>
#include "Student.h"
#include "Staff.h"
#include "Day.h"
#include "Save.h"
#include "Afterhours.h"

const short semesterLength = 105;
const short semesterAmount = 7;

std::vector<Professor> professors;										//vectors to contain Professors, Academics and Students
std::vector<Academic> academics;
std::vector<Student> classroom;

short dayNumber = 0;												//tracking days passed
bool evenWeek = 1;
short semesterNumber = 1;
short simulationNumber = 1;

int main(int argc, char* argv[])
{
	unsigned char button;
	
	getFromFile(argv[1], professors, academics, classroom);

	saveToFile(argv[2], professors, academics, classroom, dayNumber, semesterNumber);
	dayNumber++;

	do
	{																			//after each day
		button = _getch();
		if (static_cast <int>(button) == 13)									//if enter pressed, go to thru the day
		{
			getLectures(professors, classroom, dayNumber, isOdd(dayNumber), semesterNumber);
			getExercises(academics, classroom, dayNumber, isOdd(dayNumber));
			Afterhours(classroom, isWeekend(dayNumber));
			saveToFile(argv[2], professors, academics, classroom, dayNumber, semesterNumber);	
			dayNumber++;
		}
	} while (static_cast <int>(button) != 27);									//ESC stops the simulation

	return 0;
}
