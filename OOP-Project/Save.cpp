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
	int idS;

	while (!input.eof())	//reading from file
	{
		//first - what are we importing (P(rofessor), A(cademic), S(tudent))
		input >> readString;
		if(readString == "P")																		//create Professor
		{																							//gather info
			std::string firstNameS;
			std::string lastNameS;
			short courseDifficultyS;
			bool examCheckS;

			input >> idS;
			input >> firstNameS;
			input >> lastNameS;
			input >> courseDifficultyS;
			input >> examCheckS;

			professors_.emplace_back(idS,firstNameS,lastNameS,courseDifficultyS,examCheckS);					//aaaand into vector you go!

			char occurenceS;

			input >> courseDifficultyS;																//getting day number
			input >> occurenceS;
			input >> idS;																			//reusing variable for knowledgeToGain

			professors_[professors_.size() - 1].lecture.setLParameters(courseDifficultyS, occurenceS, idS, 0);
			std::cout << "Professor number " << professors_.size() << " created!" << "\n";
			readString = "";																		//clearing a string to make sure we can check for another object
		}
		else if (readString == "A")																	//create Academic
		{																							//gather info
			std::string firstNameS;
			std::string lastNameS;
			short courseDifficultyS;

			input >> idS;
			input >> firstNameS;
			input >> lastNameS;
			input >> courseDifficultyS;

			academics_.emplace_back(idS, firstNameS, lastNameS, courseDifficultyS);						//aaaand into vector you go!
			std::cout << "Academic number " << academics_.size() << " created!" << "\n";
			readString = "";																			//clearing a string to make sure we can check for another object
		}
		else if (readString == "S")																		//create Student
		{																								//gather info
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
