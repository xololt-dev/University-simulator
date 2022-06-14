#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <conio.h>
#include <math.h>
#include "Student.h"
#include "Staff.h"
#include "Day.h"
#include "Save.h"
#include "Afterhours.h"
#include "Animation.h"

const short windowX = 1024;
const short windowY = 384;
const short semesterLength = 112;
const short semesterAmount = 7;

std::vector<Professor> professors;																				//vectors to contain Professors, Academics and Students
std::vector<Academic> academics;
std::vector<Student> classroom;
std::vector<Professor> professorsRef;																			//reference vectors
std::vector<Academic> academicsRef;
std::vector<Student> classroomRef;

std::vector<sf::CircleShape> professorsDisplay;																	//vectors to contain displayed objects
std::vector<sf::CircleShape> academicsDisplay;
std::vector<sf::CircleShape> classroomDisplay;
std::vector<sf::Text> professorsDisplayText;
std::vector<sf::Text> academicsDisplayText;
std::vector<sf::Text> classroomDisplayText;

short dayNumber = 0;																							//tracking days passed
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

	getObjectsInfo(argv[1], professors, academics, classroom);													//getting info from provided files
	getSimulationInfo(argv[2], argv[3], simulationParameters);

	professorsRef.assign(professors.begin(), professors.end());													//making sure we have references to run multiple simulations
	academicsRef.assign(academics.begin(), academics.end());
	classroomRef.assign(classroom.begin(), classroom.end());

	saveToFile(argv[3], professors, academics, classroom, dayNumber, semesterNumber);

	if (professors.size() < 11 && academics.size() < 11 && classroom.size() < 57)
	{
		sf::RenderWindow window(sf::VideoMode(windowX, windowY), "University simulation");

		sf::Font font;
		font.loadFromFile("LatoWeb-Bold.ttf");

		std::string dayString = "Day: " + std::to_string(dayNumber);											//creating simulation information text
		std::string semesterString = "Semester: " + std::to_string(simulationNumber);
		std::string simString = "Simulation: " + std::to_string(simulationNumber);
		sf::Text dayT(dayString, font);
		sf::Text semesterT(semesterString, font);
		sf::Text simT(simString, font);
		dayT.setFillColor(sf::Color::White);
		dayT.setPosition(170, 320);
		semesterT.setFillColor(sf::Color::White);
		semesterT.setPosition(432, 320);
		simT.setFillColor(sf::Color::White);
		simT.setPosition(672, 320);

		objectsStudents(classroom, classroomDisplay, classroomDisplayText, semesterNumber, font, windowX, 1);

		while (window.isOpen())
		{
			sf::Event event;
			while (window.pollEvent(event))
			{
				if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Enter))			//day passes with enter press
				{
					Day(professors, academics, classroom, dayNumber, isEven(dayNumber), semesterNumber, simulationParameters);
					Afterhours(classroom, isWeekend(dayNumber), simulationParameters);

					objectsStudents(classroom, classroomDisplay, classroomDisplayText, semesterNumber, font, windowX, 0);
					saveToFile(argv[3], professors, academics, classroom, dayNumber, semesterNumber);

					dayString = "Day: " + std::to_string(dayNumber);
					dayT.setString(dayString);
					dayNumber++;
				}

				if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape))	event.type = sf::Event::Closed;		//if esc pressed, quit the program

				if (event.type == sf::Event::Closed)
					window.close();
			}

			window.clear();
			
			if (dayNumber > semesterLength)
			{
				dayNumber = 0;
				if (semesterNumber < semesterAmount) 															//going between semesters
				{
					semesterNumber++;
					for (short i = 0; i < classroom.size(); i++)
					{
						if (classroom[i].showStudying())
						{
							classroom[i].updateFatigue(simulationParameters[10]);													//some recovery between semesters
							classroom[i].updateSemester();
						}						
					}
				}
				else if (semesterNumber == semesterAmount && simulationNumber < simulationParameters[11])				//if there are still simulations left
				{					
					simulationNumber++;
					semesterNumber = 1;

					simString = "Simulation: " + std::to_string(simulationNumber);
					simT.setString(simString);

					professors.assign(professorsRef.begin(), professorsRef.end());								//we need original values - we get them from reference vectors
					academics.assign(academicsRef.begin(), academicsRef.end());
					classroom.assign(classroomRef.begin(), classroomRef.end());
				}
				else if (semesterNumber == semesterAmount && simulationNumber == simulationParameters[11])
				{
					simulationNumber++;
				}
				else
				{
					event.type = sf::Event::Closed;
					window.close();
				}
			}
			else
			{
				if (dayNumber == 1 && semesterNumber > 0)
				{
					semesterString = "Semester: " + std::to_string(semesterNumber);
					semesterT.setString(semesterString);
				}
				if (dayNumber == 1 && simulationNumber > simulationParameters[11])
				{
					event.type = sf::Event::Closed;
					window.close();
				}
				for (short i = 0; i < classroom.size(); i++)													//drawing everything
				{
					window.draw(classroomDisplay[i]);
					window.draw(classroomDisplayText[i]);
					window.draw(dayT);
					window.draw(semesterT);
					window.draw(simT);
				}
			}
			window.display();
		}
	}

	return 0;
}
