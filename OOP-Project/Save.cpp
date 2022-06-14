#include "Save.h"
#include "Staff.h"
#include "Student.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

void getObjectsInfo(std::string filename_ppl, std::vector<Professor>& professors_, std::vector<Academic>& academics_, std::vector<Student>& classroom_)			//loading data from file
{
	std::ifstream input(filename_ppl, std::ios::in);

	if (!input.is_open())
	{
		std::cout << "ERROR\Objects file not found!\tERROR";
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

			input >> idS;
			input >> firstNameS;
			input >> lastNameS;
			input >> courseDifficultyS;
			
			professors_.emplace_back(idS,firstNameS,lastNameS,courseDifficultyS);					//aaaand into vector you go!

			char occurenceS;
			bool examCheckS;

			input >> courseDifficultyS;																//getting day number
			input >> occurenceS;
			input >> idS;																			//reusing variable for knowledgeToGain
			input >> examCheckS;

			professors_[professors_.size() - 1].lecture.setLParameters(courseDifficultyS, occurenceS, idS, 0, examCheckS);

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

			char occurenceS;
			short testAmountS;

			input >> courseDifficultyS;																//getting day number
			input >> occurenceS;
			input >> idS;																			//reusing variable for knowledgeToGain
			input >> testAmountS;

			academics_[academics_.size() - 1].exercise.setEParameters(courseDifficultyS, occurenceS, idS, 0, testAmountS);

			std::cout << "Academic number " << academics_.size() << " created!" << "\n";
			readString = "";																			//clearing a string to make sure we can check for another object
		}
		else if (readString == "S")																		//create Student
		{																								//gather info
			short knowledgeS;
			short fatigueS;
			short semesterS;
			bool studyingS;
			bool workingS;

			input >> idS;
			input >> knowledgeS;
			input >> fatigueS;
			input >> semesterS;
			input >> studyingS;
			input >> workingS;

			classroom_.emplace_back(idS, knowledgeS, fatigueS, semesterS, studyingS, workingS);					//aaaand into vector you go!
			std::cout << "Student number " << classroom_.size() << " created!" << "\n";
			
			readString = "";
		}
	}

	input.close();
}

void getSimulationInfo(std::string filename_set, std::string saveFile_, std::vector<short>& simulationParameters_)
{
	//std::cout << 1 << "\n";
	std::ifstream settings(filename_set, std::ios::in);

	if (!settings.is_open())
	{
		std::cout << "WARNING\tDefault simulation settings!\tWARNING";
		simulationParameters_[0] = 1; simulationParameters_[1] = -6; simulationParameters_[2] = -2; simulationParameters_[3] = 1;
		simulationParameters_[4] = 4; simulationParameters_[5] = -1; simulationParameters_[6] = 4; simulationParameters_[7] = 2;
		simulationParameters_[8] = -1; simulationParameters_[9] = 4; simulationParameters_[10] = -3; simulationParameters_[11] = -50;
		goto save;
	}
	else
	{
		short input = 0;
		short i = 0;

		while (!settings.eof())
		{
			settings >> input;
			if(i < 12)simulationParameters_[i] = input;
			i++;
		}
	}
	save:
	settings.close();

	std::ofstream output(saveFile_, std::ios::out | std::ios::app);

	if (!output.is_open())
	{
		std::cout << "ERROR\tFile not open!\tERROR";
		return;
	}
	
	for (short i = 0; i < simulationParameters_.size(); i++)
	{
		std::cout << simulationParameters_[i] << "\t";
		output << simulationParameters_[i] << "\t";
	}
	std::cout << "\n";
	output << "\n";
	output.close();
}

void saveToFile(std::string filename_, std::vector<Professor>& professors_, std::vector<Academic>& academics_, std::vector<Student>& classroom_, short dayNumber_, short semesterNumber_)			//updateStatus(professors, academics, classroom) substitute/evolution with saving
{
	std::ofstream output(filename_, std::ios::out | std::ios::app);

	if (!output.is_open())
	{
		std::cout << "ERROR\tFile not open!\tERROR";
		return;
	}

	std::cout << "Semester: " << semesterNumber_ << "\tDay: " << dayNumber_ << "\n";
	output << "Semester: " << semesterNumber_ << "\tDay: " << dayNumber_ << "\n";
	std::cout << "Professors: \n";
	output << "Professors: \n";
	for (int i = 0; i < professors_.size(); i++)
	{
		std::cout << professors_[i].showId() << "\t" << professors_[i].showFirstName() << "\t" << professors_[i].showLastName() << "\t" << professors_[i].showPCourseDifficulty();
		output << professors_[i].showId() << "\t" << professors_[i].showFirstName() << "\t" << professors_[i].showLastName() << "\t" << professors_[i].showPCourseDifficulty();
		std::cout << "\t" << professors_[i].lecture.showDay() << "\t" << professors_[i].lecture.showOccurence() << "\t" << professors_[i].lecture.showKnowledgeToGain() << "\t" << professors_[i].lecture.showCurrLesson() << "\t" << professors_[i].lecture.showLExamCheck() << "\n";
		output << "\t" << professors_[i].lecture.showDay() << "\t" << professors_[i].lecture.showOccurence() << "\t" << professors_[i].lecture.showKnowledgeToGain() << "\t" << professors_[i].lecture.showCurrLesson() << "\t" << professors_[i].lecture.showLExamCheck() << "\n";
	}
	std::cout << "Academics: \n";
	output << "Academics: \n";
	for (int i = 0; i < academics_.size(); i++)
	{
		std::cout << academics_[i].showId() << "\t" << academics_[i].showFirstName() << "\t" << academics_[i].showLastName() << "\t" << academics_[i].showACourseDifficulty();
		output << academics_[i].showId() << "\t" << academics_[i].showFirstName() << "\t" << academics_[i].showLastName() << "\t" << academics_[i].showACourseDifficulty();
		std::cout << "\t" << academics_[i].exercise.showDay() << "\t" << academics_[i].exercise.showOccurence() << "\t" << academics_[i].exercise.showKnowledgeToGain() << "\t" << academics_[i].exercise.showCurrLesson() << "\t" << academics_[i].exercise.showETestAmount() << "\n";
		output << "\t" << academics_[i].exercise.showDay() << "\t" << academics_[i].exercise.showOccurence() << "\t" << academics_[i].exercise.showKnowledgeToGain() << "\t" << academics_[i].exercise.showCurrLesson() << "\t" << academics_[i].exercise.showETestAmount() << "\n";
	}
	std::cout << "Classroom: \n";
	output << "Classroom: \n";
	for (int i = 0; i < classroom_.size(); i++)
	{
		std::cout << classroom_[i].showSId() << "\t" << classroom_[i].showKnowledge() << "\t" << classroom_[i].showFatigue() << "\t" << classroom_[i].showSemester() << "\t" << classroom_[i].showStudying() << "\t" << classroom_[i].showWorking() << "\n";
		output << classroom_[i].showSId() << "\t" << classroom_[i].showKnowledge() << "\t" << classroom_[i].showFatigue() << "\t" << classroom_[i].showSemester() << "\t" << classroom_[i].showStudying() << "\t" << classroom_[i].showWorking() << "\n";
	}

	output.close();
}
