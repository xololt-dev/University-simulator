#include "Animation.h"

void objectsStudentsCircles(std::vector<Student>& classroom_, std::vector<sf::CircleShape>& classroomDisplay_, short semesterNumber_, short windowX_, bool new_)
{
	short rgbRed;
	short rgbGreen;
	short rgbRedO;	//outline color
	short rgbGreenO;
	short halfwayKnowledge = 14 * semesterNumber_ / 2;
	sf::Color color(0, 0, 0);
	short x = 0;
	short y = 0;

	for (short i = 0; i < classroom_.size(); i++)
	{
		if (new_)	//creating both objects with their parameters
		{
			classroomDisplay_.emplace_back(36);
			classroomDisplay_[i].move(x, y);
			classroomDisplay_[i].setOutlineThickness(-6);
			classroomDisplay_[i].setOutlineColor(sf::Color::White);
		}		

		if (x < windowX_ - 146)	x += 73;				//going to next line if students don't fit
		else
		{
			x = 0;
			y += 73;
		}
		if (classroom_[i].showStudying())
		{
			if (classroom_[i].showKnowledge() < halfwayKnowledge)						//from red to yellow
			{
				rgbRed = 255;
				rgbGreen = (510 * classroom_[i].showKnowledge()) / ((14 * semesterNumber_) + 1);		//510 colours red-yellow-green
			}
			else if (classroom_[i].showKnowledge() > (2 * halfwayKnowledge))			//green - too knowledgeable ;p
			{
				rgbGreen = 255;
				rgbRed = 0;
			}
			else																		//yellow to green 
			{
				rgbGreen = 255;
				rgbRed = 255 - (510 * (classroom_[i].showKnowledge() - halfwayKnowledge)) / ((14 * semesterNumber_) + 1);
			}

			if (classroom_[i].showFatigue() > 49)			//green - too knowledgeable ;p
			{
				rgbRedO = 255;
				rgbGreenO = (510 * (100 - classroom_[i].showFatigue())) / 100;		//510 colours red-yellow-green
			}
			else																		//yellow to green 
			{
				rgbGreenO = 255;
				rgbRedO = (510 * classroom_[i].showFatigue()) / 100;
			}
		}
		else
		{
			rgbGreen = 0;
			rgbRed = 255;
			rgbGreenO = 0;
			rgbRedO = 255;
		}
		color.r = rgbRed;
		color.g = rgbGreen;
		classroomDisplay_[i].setFillColor(color);
		color.r = rgbRedO;
		color.g = rgbGreenO;
		classroomDisplay_[i].setOutlineColor(color);
	}
}

void objectsStudentsText(std::vector<Student>& classroom_, std::vector<sf::Text>& classroomDisplayText_, short semesterNumber_, sf::Font& font_, short windowX_)
{
	std::string id_;
	short x = 0;
	short y = 0;

	for (short i = 0; i < classroom_.size(); i++)
	{
		id_ = std::to_string(classroom_[i].showSId());
		classroomDisplayText_.emplace_back(id_, font_);		
		classroomDisplayText_[i].setCharacterSize(36);
		classroomDisplayText_[i].setFillColor(sf::Color::Black);

		if (i < 9)	classroomDisplayText_[i].move(25 + x, 12 + y);		//id inside students
		else	classroomDisplayText_[i].move(14 + x, 12 + y);

		if (x < windowX_ - 146)	x += 73;				//going to next line if students don't fit
		else
		{
			x = 0;
			y += 73;
		}
	}
}

void objectsStudents(std::vector<Student>& classroom_, std::vector<sf::CircleShape>& classroomDisplay_, std::vector<sf::Text>& classroomDisplayText_, short semesterNumber_, sf::Font& font_, short windowX_, bool new_)
{
	objectsStudentsCircles(classroom_, classroomDisplay_, semesterNumber_, windowX_, new_);
	if(new_)	objectsStudentsText(classroom_, classroomDisplayText_, semesterNumber_, font_, windowX_);
}
