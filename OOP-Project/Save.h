#ifndef SAVE_H
#define SAVE_H

#include <string>
#include <vector>
#include "Staff.h"
#include "Student.h"

void getObjectsInfo(std::string filename, std::vector<Professor>& professors_, std::vector<Academic>& academics_, std::vector<Student>& classroom_);		//loading data from file
void getSimulationInfo(std::string filename_set, std::string saveFile_, std::vector<short>& simulationParameters_);

void saveToFile(std::string filename_, std::vector<Professor>& professors_, std::vector<Academic>& academics_, std::vector<Student>& classroom_, short dayNumber_, short semesterNumber_);		//save to file & displays full information about the simulation during the current day

#endif
