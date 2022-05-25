#include "Save.h"
#include "Professor.h"
#include "Student.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

void getFromFile(std::string filename, std::vector<Professor> &professors_)
{
	std::ifstream input;

	input.open(filename);					//opening a file

	if (!input.is_open())
	{
		std::cout << "ERROR\tFile not found!\tERROR";
		return;
	}
	
	std::string readString;
	short readShort;
	bool readBool;
	/*Professor secondaryP;
	Academic secondaryA;
	Student secondaryS;*/

	while (!input.eof())	//reading from file
	{
		input >> readShort;
		std::cout << readShort;
		/*
		* https://stackoverflow.com/questions/8011887/how-can-i-create-multiple-objects-with-for-loop-in-c
		* 
		first - what are we importing (P(rofessor), A(cademic), S(tudent))	so need string/char
		input >> readString;
		if(readString == "P")					//create Professor
		{
			int idS;
			std::string firstNameS;
			std::string lastNameS;
			short courseDifficultyS;
			input >> idS;
			input >> firstNameS;
			input >> lastNameS;
			input >> courseDifficultyS; 

			professors_.emplace_back(idS,firstNameS,lastNameS,courseDifficultyS);
		}
		else if(readString == "A")
		else if(readString == "S")		
		*/

	}

	input.close();
}
