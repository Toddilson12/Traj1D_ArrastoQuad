#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "common.h"
 

class io_manager
{
	std::fstream fileHandler;

	std::string outputFile;
	std::string inputFile;

	// Gnuplot gnuInstance;
	// unsigned int graphic_layout;
	// ...
public:
	io_manager(const std::string& inputFile_ = ".", const std::string& outputFile_ = ".");

	// File system
	void ReadDataFile(common_input& input, const std::string& inputFile_ = ".");
	void PrintDataFile(const common_output& input, const std::string& ouputFile_ = ".");

	// Console system
	void ReadDataCon(common_input& input);
	void PrintDataCon(const common_output& output);

	// Graphic system
	// ...
};

