#pragma once

#include "Helpers.h"
#include "Book.h"
#include <fstream>
#include <string>
#include <iostream>

using namespace std;

class InventoryDatabase {
private:
	Book* books;
	string invFilePath;
	ifstream instream;
	ofstream ostream;
	size_t bookCount = 0;
	size_t maxBooks = 1024;
public:
	// Default Constructor 
	InventoryDatabase();

	// Constructor which take parameter
	InventoryDatabase(std::string invFile);

	// Accessor
	// return array books object
	Book* getBooksDatabase();

	// return book in inventory 
	int getBookCount();

	// Function
	// Find book object 
	Book* findBook(string isbn, int* index = nullptr);

	// Function to look up book 
	void lookUpBook();

	// Function to delete Book 
	void deleteBook();

	// Function to add book 
	void addBook();

	// Function to edit book 
	void editBook();

	// Main Menu 
	void mainMenu();

};