#include <iostream>
#include <vector>
#include <conio.h>
#include <math.h>
#include "Student.h"
#include "Staff.h"
#include "Day.h"
#include "Save.h"
#include "Afterhours.h"

const short semesterLength = 112;
const short semesterAmount = 7;

std::vector<Professor> professors;										//vectors to contain Professors, Academics and Students
std::vector<Academic> academics;
std::vector<Student> classroom;

std::vector<Professor> professorsRef;
std::vector<Academic> academicsRef;
std::vector<Student> classroomRef;

short dayNumber = 0;												//tracking days passed
short semesterNumber = 1;
short simulationNumber = 1;

std::vector<short> simulationParameters;																		/*
																												short sleep;
																												short relax;
																												short study;
																												short partyFatigue;
																												short partyKnowledge;
																												short work;
																												short lectureFatigue;
																												short lectureFatigueRecovery;
																												short exerciseFatigue;
																												short exerciseFatigueRecovery;
																												short midSemesterRecovery;
																												short simulationsToDo;
																												*/

int main(int argc, char* argv[])
{
	unsigned char button;

	simulationParameters.resize(12);

	getSimulationInfo(argv[2], argv[3], simulationParameters);
	getObjectsInfo(argv[1], professors, academics, classroom);

	professorsRef.assign(professors.begin(), professors.end());
	academicsRef.assign(academics.begin(), academics.end());
	classroomRef.assign(classroom.begin(), classroom.end());

	saveToFile(argv[3], professors, academics, classroom, dayNumber, semesterNumber);
	
	do
	{																			//after each day
		button = _getch();
		if (static_cast <int>(button) == 13)									//if enter pressed, go to thru the day
		{
			while(simulationNumber <= simulationParameters[11])
			{
				Day(professors, academics, classroom, dayNumber, isEven(dayNumber), semesterNumber, simulationParameters);
				Afterhours(classroom, isWeekend(dayNumber), simulationParameters);

				saveToFile(argv[3], professors, academics, classroom, dayNumber, semesterNumber);
				dayNumber++;

				if (dayNumber > semesterLength)
				{
					dayNumber = 0;
					if (semesterNumber < semesterAmount) 		//going between semesters
					{
						semesterNumber++;
						for (short i = 0; i < classroom.size(); i++)
						{
							if (classroom[i].showStudying())
							{
								classroom[i].updateFatigue(simulationParameters[10]);
								classroom[i].updateSemester();
							}
						}
					}
					else if (semesterNumber == semesterAmount)			//if there are still simulations left
					{
						if (simulationNumber == simulationParameters[11]) goto end;
						button = _getch();
						if (static_cast <int>(button) == 27) break;

						simulationNumber++;
						semesterNumber = 1;

						professors.assign(professorsRef.begin(), professorsRef.end());
						academics.assign(academicsRef.begin(), academicsRef.end());
						classroom.assign(classroomRef.begin(), classroomRef.end());
					}
				}
			}
		}
	} while (static_cast <int>(button) != 27);									//ESC stops the simulation	
	
	end:
	return 0;
}