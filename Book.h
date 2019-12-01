#pragma once

#include <string>
#include "Date.h"

using namespace std;

class Book {
private:
	string isbn;
	string title;
	string author;
	string publisher;
	Date dateAdded;
	unsigned int quantityOnHand;
	double wholesaleCost;
	double retailPrice;

public:
	// Default Constructor 
	Book();

	// Constructor with parameter
	Book(string isbn, string title, string author, string publisher, unsigned int quantityOnHand,
		float wholesaleCost, float retailPrice, int day, int month, int year);


	// Accessor 
	// get ISBN 
	string getIsbn();
	// get Titile 
	string getTitle();
	// get Author 
	string getAuthor();
	// get publisher
	string getPublisher();
	// get Date Added
	string getDateAdded();
	// get quantity on hand 
	unsigned int getQuantityOnHand();
	// float whole sale cost
	double getWholesaleCost();
	//float get retail price 
	double getRetailPrice();
	int getDay();
	int getMonth();
	int getYear();

	// Mutator 
	// Set ISBN 
	void setIsbn(string isbn);
	// Set Title
	void setTitle(string title);
	// Set Author
	void setAuthor(string author);
	// Set Publisher
	void setPublisher(string publisher);
	// set Date added
	// set Day 
	void setDay(int day);
	// set month 
	void setMonth(int month);
	// set year
	void setYear(int year);
	// Set Quantity on Hand 
	void setQuantityOnHand(unsigned int quantityOnHand);
	// Set Whole Sale Cost
	void setWholesaleCost(double wholesaleCost);
	// Set Retail Price 
	void setRetailPrice(double retailPrice);

	// Function 
	// convert to Data String 
	string bookDataAsString();

	// conver to Human readable
	string bookDataAsHumanReadableString();

	//Get Fields
	static string* getFields();

	// Get Human Readable Field 
	static string* getHumanReadableFields();
};