#ifndef ANIMATION_H
#define ANIMATION_H

#include <SFML/Graphics.hpp>
#include <string>
#include <vector>
#include "Staff.h"
#include "Student.h"

void objectsStudentsCircles(std::vector<Student>& classroom_, std::vector<sf::CircleShape>& classroomDisplay_, short semesterNumber_, short windowX_, bool new_);
void objectsStudentsText(std::vector<Student>& classroom_, std::vector<sf::Text>& classroomDisplayText_, short semesterNumber_, sf::Font& font_, short windowX_);
void objectsStudents(std::vector<Student>& classroom_, std::vector<sf::CircleShape>& classroomDisplay_, std::vector<sf::Text>& classroomDisplayText_, short semesterNumber_, sf::Font& font_, short windowX_, bool new_);

#endif