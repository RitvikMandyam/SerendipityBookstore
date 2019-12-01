#pragma once

#include "Book.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

namespace Helpers {

	// Function to get file size
	int getDataFIleSize(std::string fileName);

	// Set Data File to Inventory
	Book* installDataToInventory(string fileName, int fileSize);

	// Function to split string with delimeter 
	std::string* splitString(std::string input, std::string delimiter, int* length);

	// Function to get consold line
	std::string getConsoleLine();

	// Function to validate input and correct it - int
	void correctingValidInput(int& userInput);

	// Function to validate input and correct it - double
	void correctingValidInput(double& userInput);
}