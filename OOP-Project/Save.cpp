#include "Save.h"
#include "Professor.h"
#include "Student.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

void getFromFile(std::string filename, std::vector<Professor>& professors_, std::vector<Academic>& academics_, std::vector<Student>& students_)
{
	std::ifstream input;

	input.open(filename);					//opening a file

	if (!input.is_open())
	{
		std::cout << "ERROR\tFile not found!\tERROR";
		return;
	}
	
	std::string readString;
	//short readShort;
	//bool readBool;
	/*Professor secondaryP;
	Academic secondaryA;
	Student secondaryS;*/

	while (!input.eof())	//reading from file
	{
	//	input >> readShort;
		//std::cout << readShort;
		/*
		* https://stackoverflow.com/questions/8011887/how-can-i-create-multiple-objects-with-for-loop-in-c
		* 
		first - what are we importing (P(rofessor), A(cademic), S(tudent))	so need string/char	*/
		input >> readString;
		if(readString == "P")																		//create Professor
		{
			int idS;																				//gather info
			std::string firstNameS;
			std::string lastNameS;
			short courseDifficultyS;
			input >> idS;
			input >> firstNameS;
			input >> lastNameS;
			input >> courseDifficultyS; 

			professors_.emplace_back(idS,firstNameS,lastNameS,courseDifficultyS);					//aaaand into vector you go!
			std::cout << "Professor number " << professors_.size() << " created!" << "\n";
			readString = "";																		//clearing a string to make sure we can check for another object
		}
		else if (readString == "A")																	//create Academic
		{
			int idS;																				//gather info
			std::string firstNameS;
			std::string lastNameS;
			short courseDifficultyS;
			input >> idS;
			input >> firstNameS;
			input >> lastNameS;
			input >> courseDifficultyS;

			academics_.emplace_back(idS, firstNameS, lastNameS, courseDifficultyS);				//aaaand into vector you go!
			std::cout << "Academic number " << academics_.size() << " created!" << "\n";
			readString = "";																		//clearing a string to make sure we can check for another object
		}
		else if (readString == "S")																	//create Student
		{
			int idS;																				//gather info
			short knowledgeS;
			short fatigueS;
			short semesterS;
			bool studyingS;
			input >> idS;
			input >> knowledgeS;
			input >> fatigueS;
			input >> semesterS;
			input >> studyingS;

			students_.emplace_back(idS, knowledgeS, fatigueS, semesterS, studyingS);					//aaaand into vector you go!
			std::cout << "Student number " << students_.size() << " created!" << "\n";
			readString = "";
		}
	}

	input.close();
}
