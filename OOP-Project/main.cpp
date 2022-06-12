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
const short windowY = 768;
const short semesterLength = 112;
const short semesterAmount = 7;

std::vector<Professor> professors;										//vectors to contain Professors, Academics and Students
std::vector<Academic> academics;
std::vector<Student> classroom;
std::vector<Professor> professorsRef;
std::vector<Academic> academicsRef;
std::vector<Student> classroomRef;

std::vector<sf::CircleShape> professorsDisplay;										//vectors to contain displayed objects
std::vector<sf::CircleShape> academicsDisplay;
std::vector<sf::CircleShape> classroomDisplay;
std::vector<sf::Text> professorsDisplayText;
std::vector<sf::Text> academicsDisplayText;
std::vector<sf::Text> classroomDisplayText;

short dayNumber = 0;												//tracking days passed
short semesterNumber = 1;
short simulationNumber = 1;

int main(int argc, char* argv[])
{
	unsigned char button;
	
	getFromFile(argv[1], professors, academics, classroom);

	professorsRef.assign(professors.begin(), professors.end());
	academicsRef.assign(academics.begin(), academics.end());
	classroomRef.assign(classroom.begin(), classroom.end());

	saveToFile(argv[2], professors, academics, classroom, dayNumber, semesterNumber);

	if (professors.size() < 11 && academics.size() < 11 && classroom.size() < 57)
	{
		sf::RenderWindow window(sf::VideoMode(windowX, windowY), "OOP Project");

		sf::Font font;
		font.loadFromFile("LatoWeb-Bold.ttf");

		std::string dayString = std::to_string(dayNumber);
		std::string semesterString = std::to_string(simulationNumber);
		std::string simString = std::to_string(simulationNumber);
		sf::Text dayT(dayString, font);
		sf::Text semesterT(semesterString, font);
		sf::Text simT(simString, font);
		dayT.setFillColor(sf::Color::White);
		dayT.setPosition(412, 512);
		semesterT.setFillColor(sf::Color::White);
		semesterT.setPosition(512, 512);
		simT.setFillColor(sf::Color::White);
		simT.setPosition(612, 512);

		objectsStudents(classroom, classroomDisplay, classroomDisplayText, semesterNumber, font, windowX, 1);

		while (window.isOpen())
		{
			sf::Event event;
			while (window.pollEvent(event))
			{
				if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Enter))
				{
					getLectures(professors, classroom, dayNumber, isOdd(dayNumber), semesterNumber);
					getExercises(academics, classroom, dayNumber, isOdd(dayNumber));
					Afterhours(classroom, isWeekend(dayNumber));
					objectsStudents(classroom, classroomDisplay, classroomDisplayText, semesterNumber, font, windowX, 0);
					saveToFile(argv[2], professors, academics, classroom, dayNumber, semesterNumber);

					dayString = std::to_string(dayNumber);
					dayT.setString(dayString);
					dayNumber++;
				}

				if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape))	event.type = sf::Event::Closed;

				if (event.type == sf::Event::Closed)
					window.close();
			}

			window.clear();
			
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
							classroom[i].updateFatigue(-50);
							classroom[i].updateSemester();
						}						
					}
				}
				else if (semesterNumber == semesterAmount && simulationNumber < std::atoi(argv[3]))			//if there are still simulations left
				{					
					simulationNumber++;
					semesterNumber = 1;
					
					semesterString = std::to_string(semesterNumber);
					semesterT.setString(semesterString);

					simString = std::to_string(simulationNumber);
					simT.setString(simString);

					professors.assign(professorsRef.begin(), professorsRef.end());
					academics.assign(academicsRef.begin(), academicsRef.end());
					classroom.assign(classroomRef.begin(), classroomRef.end());
				}
				else if (semesterNumber == semesterAmount && simulationNumber == std::atoi(argv[3]))
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
				if (dayNumber == 1 && semesterNumber > 1)
				{
					semesterString = std::to_string(semesterNumber);
					semesterT.setString(semesterString);
				}
				if (dayNumber == 1 && simulationNumber > std::atoi(argv[3]))
				{
					event.type = sf::Event::Closed;
					window.close();
				}
				for (short i = 0; i < classroom.size(); i++)
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
	/*do
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
	*/
	return 0;
}
