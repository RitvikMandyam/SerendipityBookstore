#include "Book.h"

// Constructor with parameter
Book::Book(string isbn, string title, string author, string publisher, unsigned int quantityOnHand, float wholesaleCost, float retailPrice,
	int day, int month, int year) {
	this->isbn = isbn;
	this->title = title;
	this->author = author;
	this->publisher = publisher;
	this->dateAdded = Date(day, month, year);
	this->quantityOnHand = quantityOnHand;
	this->wholesaleCost = wholesaleCost;
	this->retailPrice = retailPrice;
}

// Default Constructor
Book::Book() {
	this->isbn = "";
	this->title = "";
	this->author = "";
	this->publisher = "";
	this->dateAdded;
	this->quantityOnHand = 0;
	this->wholesaleCost = 0;
	this->retailPrice = 0;
}


// Accessor
string Book::getIsbn() { return this->isbn; }
string Book::getTitle() { return this->title; }
string Book::getAuthor() { return this->author; }
string Book::getPublisher() { return this->publisher; }
string Book::getDateAdded() { return this->dateAdded.toString(); }
unsigned int Book::getQuantityOnHand() { return this->quantityOnHand; }
double Book::getWholesaleCost() { return this->wholesaleCost; }
double Book::getRetailPrice() { return this->retailPrice; }
int Book::getDay() { return this->dateAdded.getDay(); }
int Book::getMonth() { return this->dateAdded.getMonth(); }
int Book::getYear() { return this->dateAdded.getYear(); }
//Mutator 
void Book::setIsbn(string isbn) { this->isbn = isbn; }
void Book::setTitle(string title) { this->title = title; }
void Book::setAuthor(string author) { this->author = author; }
void Book::setPublisher(string publisher) { this->publisher = publisher; }
void Book::setDay(int day) { dateAdded.setDay(day); }
void Book::setMonth(int month) { dateAdded.setMonth(month); }
void Book::setYear(int year) { dateAdded.setYear(year); }
void Book::setQuantityOnHand(unsigned int quantityOnHand) { this->quantityOnHand = quantityOnHand; }
void Book::setWholesaleCost(double wholesaleCost) { this->wholesaleCost = wholesaleCost; }
void Book::setRetailPrice(double retailPrice) { this->retailPrice = retailPrice; }

// Function 
// convert to Data String
string Book::bookDataAsString() {
	string data = this->getIsbn() + "|" +
		this->getTitle() + "|" +
		this->getAuthor() + "|" +
		this->getPublisher() + "|" +
		to_string(this->getQuantityOnHand()) + "|" +
		to_string(this->getWholesaleCost()) + "|" +
		to_string(this->getRetailPrice()) + "|" +
		to_string(this->dateAdded.getDay()) + "|" +
		to_string(this->dateAdded.getMonth()) + "|" +
		to_string(this->dateAdded.getYear()) + "|";
	return data;
}

string Book::bookDataAsHumanReadableString() {



	string data = "ISBN: " + this->getIsbn() + '\n' +
		"Title: " + this->getTitle() + '\n' +
		"Author: " + this->getAuthor() + '\n' +
		"Publisher: " + this->getPublisher() + '\n' +
		"Added on: " + this->dateAdded.toString() + '\n' +
		"Quantity on hand: " + to_string(this->getQuantityOnHand()) + '\n' +
		"Wholesale cost: $" + to_string(this->getWholesaleCost()) + '\n' +
		"Retail price: $" + to_string(this->getRetailPrice()) + '\n';
	return data;
}

string* Book::getFields() {
	string fields[8] = { "isbn", "title", "author", "publisher", "dateAdded", "quantityOnHand", "wholesaleCost", "retailPrice" };
	return fields;
}
string* Book::getHumanReadableFields() {
	string humanReadableFields[8] = { "ISBN", "Title", "Author", "Publisher", "Date added", "Quantity on hand", "Wholesale cost", "Retail price" };
	return humanReadableFields;
}