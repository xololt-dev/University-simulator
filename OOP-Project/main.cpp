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
const short semesterLength = 105;
const short semesterAmount = 7;

std::vector<Professor> professors;										//vectors to contain Professors, Academics and Students
std::vector<Academic> academics;
std::vector<Student> classroom;

std::vector<sf::CircleShape> professorsDisplay;										//vectors to contain Professors, Academics and Students
std::vector<sf::CircleShape> academicsDisplay;
std::vector<sf::CircleShape> classroomDisplay;
std::vector<sf::Text> professorsDisplayText;										//vectors to contain Professors, Academics and Students
std::vector<sf::Text> academicsDisplayText;
std::vector<sf::Text> classroomDisplayText;

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

	if (professors.size() < 11 && academics.size() < 11 && classroom.size() < 57)
	{
		sf::RenderWindow window(sf::VideoMode(windowX, windowY), "OOP Project");

		sf::Font font;
		font.loadFromFile("LatoWeb-Bold.ttf");
		std::string dayString = std::to_string(dayNumber);
		sf::Text dayT(dayString, font);
		dayT.setFillColor(sf::Color::White);
		dayT.setPosition(512, 512);

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
			for (short i = 0; i < classroom.size(); i++)
			{
				window.draw(classroomDisplay[i]);
				window.draw(classroomDisplayText[i]);
				window.draw(dayT);
			}
			if (dayNumber == 107)
			{
				dayNumber = 0;
				if (semesterNumber < 7) semesterNumber++;
				else event.type = sf::Event::Closed;
				for (short i = 0; i < classroom.size(); i++)
				{
					classroom[i].updateFatigue(-33);
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
