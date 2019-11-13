#pragma once
#include <string>
#include <chrono>
#include <ctime>
#include <sstream>
#include <iomanip>

using namespace std;
class Book {
private:
	string isbn;
	string title;
	string author;
	string publisher;
	chrono::system_clock::time_point dateAdded;
	unsigned int quantityOnHand;
	float wholesaleCost;
	float retailPrice;

public:
	Book(string isbn, string title, string author, string publisher, chrono::system_clock::time_point dateAdded, unsigned int quantityOnHand, float wholesaleCost, float retailPrice) {
		this->isbn = isbn;
		this->title = title;
		this->author = author;
		this->publisher = publisher;
		this->dateAdded = dateAdded;
		this->quantityOnHand = quantityOnHand;
		this->wholesaleCost = wholesaleCost;
		this->retailPrice = retailPrice;
	}

	Book() {
		this->isbn = "";
		this->title = "";
		this->author = "";
		this->publisher = "";
		this->dateAdded = chrono::system_clock::now();
		this->quantityOnHand = 0;
		this->wholesaleCost = 0;
		this->retailPrice = 0;
	}

	string getIsbn() {
		return this->isbn;
	}
	string getTitle() {
		return this->title;
	}
	string getAuthor() {
		return this->author;
	}
	string getPublisher() {
		return this->publisher;
	}
	chrono::system_clock::time_point getDateAdded() {
		return this->dateAdded;
	}
	unsigned int getQuantityOnHand() {
		return this->quantityOnHand;
	}
	float getWholesaleCost() {
		return this->wholesaleCost;
	}
	float getRetailPrice() {
		return this->retailPrice;
	}

	void setIsbn(string isbn) {
		this->isbn = isbn;
	}
	void setTitle(string title) {
		this->title = title;
	}
	void setAuthor(string author) {
		this->author = author;
	}
	void setPublisher(string publisher) {
		this->publisher = publisher;
	}
	void setDateAdded(chrono::system_clock::time_point dateAdded) {
		this->dateAdded = dateAdded;
	}
	void setQuantityOnHand(unsigned int quantityOnHand) {
		this->quantityOnHand = quantityOnHand;
	}
	void setWholesaleCost(float wholesaleCost) {
		this->wholesaleCost = wholesaleCost;
	}
	void setRetailPrice(float retailPrice) {
		this->retailPrice = retailPrice;
	}

	string bookDataAsString() {
		string data = this->getIsbn() + "|" +
			this->getTitle() + "|" +
			this->getAuthor() + "|" +
			this->getPublisher() + "|" +
			to_string(chrono::milliseconds(this->getDateAdded().time_since_epoch().count()).count()) + "|" +
			to_string(this->getQuantityOnHand()) + "|" +
			to_string(this->getWholesaleCost()) + "|" +
			to_string(this->getRetailPrice());
		return data;
	}

	string bookDataAsHumanReadableString() {
		char date[26];
		time_t dateAdded = chrono::system_clock::to_time_t(this->getDateAdded());
		ctime_s(date, 26, &dateAdded);
		ostringstream streamObj;

		streamObj << fixed << setprecision(2) << this->getWholesaleCost();
		string wholesaleCost = streamObj.str();

		streamObj.str("");
		streamObj.clear();

		streamObj << fixed << setprecision(2) << this->getRetailPrice();
		string retailPrice = streamObj.str();
		string data = "ISBN: " + this->getIsbn() + '\n' +
			"Title: " + this->getTitle() + '\n' +
			"Author: " + this->getAuthor() + '\n' +
			"Publisher: " + this->getPublisher() + '\n' +
			"Added on: " + date + '\n' +
			"Quantity on hand: " + to_string(this->getQuantityOnHand()) + '\n' +
			"Wholesale cost: $" + wholesaleCost + '\n' +
			"Retail price: $" + retailPrice + '\n';
		return data;
	}

	static string* getFields() {
		string fields[8] = { "isbn", "title", "author", "publisher", "dateAdded", "quantityOnHand", "wholesaleCost", "retailPrice" };
		return fields;
	}
	static string* getHumanReadableFields() {
		string humanReadableFields[8] = { "ISBN", "Title", "Author", "Publisher", "Date added", "Quantity on hand", "Wholesale cost", "Retail price" };
		return humanReadableFields;
	}
};