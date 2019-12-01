
#include "Helpers.h"


// Function to get file size
int Helpers::getDataFIleSize(std::string fileName) {
	std::ifstream myFile;
	// Opening File to read data
	myFile.open(fileName);

	// initialize size variable to counting size of file 
	int size = 0;
	std::string line;

	// open file and calculate couting size of file
	while (myFile.is_open() && !myFile.eof()) {
		std::getline(myFile, line);
		// Ignore empty line in data file
		if (line == "") continue;
		size++;
	}

	// close file 
	myFile.close();
	return size;
}

// FUnction to initiate data file to inventory 
Book* Helpers::installDataToInventory(string fileName, int fileSize) {
	// Initialzie empty inventory array with size of fileSize
	Book* bookArray = new Book[fileSize];

	// Open file to read data
	std::ifstream myFile;
	myFile.open(fileName);

	// Continue if file is open 
	if (myFile.is_open()) {
		std::string line;

		// initial count to for putting book info 
		// to approriate slot of inventory array 
		int count = 0;

		// Loop through the end of the file 
		while (getline(myFile, line)) {
			// Ignore empty line in data file
			if (line == "") continue;
			std::stringstream iss_line(line);

			// declare array with size 10 
			// each slot of array represend one field in Book 
			// book[0] - ISBN
			// book[1] - title 
			// book[2] - author 
			// book[3] - publisher
			// book[4] - quantity 
			// book[5] - wholesale 
			// book[6] - retail price
			// book[7] - day
			// book[8] - month
			// book[9] - year 
			std::string arrayString[10];

			// loop through array and put each field of text file 
			// to each slot in array
			for (int i = 0; i < 10; i++) {
				std::getline(iss_line, arrayString[i], '|');
			}

			// Start converting string to approriate int and double 
			int quantity = stoi(arrayString[4]); // quantity of book in inventory
			int day = stoi(arrayString[7]);  // day added to inventoty 
			int month = stoi(arrayString[8]); // month added to inventory 
			int year = stoi(arrayString[9]); // year added to inventoty 
			double wholesale = atof(arrayString[5].c_str()); // whole sale cost
			double retailPrice = atof(arrayString[6].c_str()); // retail price 
			//cout << quantity << endl; 

			// Construct BookInfo Object

			Book *tempBook = new Book(arrayString[0], arrayString[1], arrayString[2], arrayString[3],
				quantity, wholesale, retailPrice, day, month, year);


			bookArray[count] = *tempBook;
			count++;
		}
	}

	myFile.close();

	return bookArray;
}

std::string Helpers::getConsoleLine()
{
	std::string str;
	std::getline(std::cin, str, '\n');
	return str;
}

// Validate input and correct it - int 
void Helpers::correctingValidInput(int &userInput) {
	bool checking;
	do {
		std::cin >> userInput;
		if (std::cin.fail()) {
			std::cout << "Please Enter Valid Input. It must be integer ";
			std::cin.clear(); // Clear the error state
			std::cin.ignore(INT_MAX, '\n'); // Take the loop to maximum time then exit 
			checking = false;
		}
		else {
			checking = true;
		}
	} while (checking == false);
}

void Helpers::correctingValidInput(double &userInput) {
	bool checking;
	do {
		std::cin >> userInput;
		if (std::cin.fail()) {
			std::cout << "Please Enter Valid Input. It must be double ";
			std::cin.clear(); // Clear the error state
			std::cin.ignore(INT_MAX, '\n'); // Take the loop to maximum time then exit 
			checking = false;
		}
		else {
			checking = true;
		}
	} while (checking == false);
}