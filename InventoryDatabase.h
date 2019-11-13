#pragma once
#include "Helpers.h"
#include "Book.h"
#include <fstream>

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
	InventoryDatabase(string invFile) {
		this->books = new Book[this->maxBooks];
		this->invFilePath = invFile;
		instream.open(this->invFilePath);
		if (instream.is_open()) {
			while (!instream.eof()) {
				string line;
				int length;
				getline(instream, line);
				string* fields = splitString(line, "|", &length);
				Book* book = new Book;
				for (int i = 0; i < length; i++) {
					switch (i) {
					case 0:
						book->setIsbn(fields[i]);
						break;
					case 1:
						book->setTitle(fields[i]);
						break;
					case 2:
						book->setAuthor(fields[i]);
						break;
					case 3:
						book->setPublisher(fields[i]);
						break;
					case 4: {
						chrono::system_clock::time_point dateAdded(std::chrono::milliseconds(std::stoll(fields[i])));
						book->setDateAdded(dateAdded);
						break;
					}
					case 5:
						book->setQuantityOnHand(stoi(getConsoleLine()));
						break;
					case 6:
						book->setWholesaleCost(stof(getConsoleLine()));
						break;
					case 7:
						book->setRetailPrice(stof(getConsoleLine()));
						break;
					}
				}
				this->books[bookCount] = *book;
				delete book;
				this->bookCount++;
			}
			this->bookCount--;
		}
	}

	Book* findBook(string isbn, int* index=nullptr) {
		for (int i = 0; i < this->bookCount; i++) {
			if (this->books[i].getIsbn() == isbn) {
				if (index != nullptr) *index = i;
				return &(this->books[i]);
			}
		}
		if (index != nullptr) *index = -1;
		return nullptr;
	}

	void lookUpBook() {
		cout << "------------------------------------------------------------" << endl;
		cout << "Looking up a book" << endl;
		cout << "------------------------------------------------------------" << endl;
		string isbn;
		cout << "Enter the ISBN to search for: ";
		cin >> isbn;
		Book* book = findBook(isbn);
		if (book != nullptr) {
			cout << "------------------------------------------------------------" << endl;
			cout << "Found book" << endl;
			cout << "------------------------------------------------------------" << endl;
			cout << book->bookDataAsHumanReadableString();
			cout << "========================================================================================================================" << endl;
		}
		else {
			cout << "------------------------------------------------------------" << endl;
			cout << "Could not find a book with the specified ISBN in the database." << endl;
			cout << "========================================================================================================================" << endl;
		}
	}

	void deleteBook() {
		Book* newBooks = new Book[this->maxBooks];
		string isbn;
		cout << "------------------------------------------------------------" << endl;
		cout << "Deleting a book" << endl;
		cout << "------------------------------------------------------------" << endl;
		cout << "Enter the ISBN of the book to delete: ";
		cin >> isbn;
		int deleteIndex;
		Book* bookToDelete = findBook(isbn, &deleteIndex);
		if (bookToDelete != nullptr) {
			for (int i = 0; i < this->bookCount; i++) {
				if (i < deleteIndex) {
					newBooks[i] = this->books[i];
				}
				else if (i > deleteIndex) {
					newBooks[i - 1] = this->books[i];
				}
			}
			delete[] this->books;
			delete bookToDelete;
			this->books = newBooks;
			cout << "------------------------------------------------------------" << endl;
			cout << "Deleted book with ISBN " << isbn << endl;
			cout << "========================================================================================================================" << endl;
			this->bookCount--;
		}
		else {
			cout << "------------------------------------------------------------" << endl;
			cout << "Could not find book with specified ISBN." << endl;
			cout << "========================================================================================================================" << endl;
		}
	}

	void addBook() {
		cout << "------------------------------------------------------------" << endl;
		cout << "Adding a new book                                          " << endl;
		cout << "------------------------------------------------------------" << endl;
		if (this->bookCount < this->maxBooks) {
			Book* book = new Book;
			string isbn;
			Book* bookExists;
			cout << "ISBN: ";
			isbn = getConsoleLine();
			bookExists = findBook(isbn);
			if (bookExists == nullptr) {
				book->setIsbn(getConsoleLine());
			}
			else {
				cout << "We already have this book in our inventory, adding another copy.";
				book->setQuantityOnHand(book->getQuantityOnHand + 1);
				return;
			}
			cout << "Title: ";
			book->setTitle(getConsoleLine());
			cout << "Author: ";
			book->setAuthor(getConsoleLine());
			cout << "Publisher: ";
			book->setPublisher(getConsoleLine());
			book->setDateAdded(chrono::system_clock::now());
			cout << "Quantity on hand: ";
			book->setQuantityOnHand(stoi(getConsoleLine()));
			cout << "Wholesale cost: $";
			book->setWholesaleCost(stof(getConsoleLine()));
			cout << "Retail price: $";
			book->setRetailPrice(stof(getConsoleLine()));
			books[this->bookCount++] = *book;
			delete book;
			cout << "========================================================================================================================" << endl;
		}
		else {
			cout << "No more space in inventory database!";
			cout << "========================================================================================================================" << endl;
		}
	}

	void editBook() {
		string isbn;
		cout << "------------------------------------------------------------" << endl;
		cout << "Editing a book                                              " << endl;
		cout << "------------------------------------------------------------" << endl;
		cout << "Enter an ISBN to edit: ";
		cin >> isbn;
		Book* bookToEdit = findBook(isbn);
		if (bookToEdit != nullptr) {
			int selection = 0;
			while (selection != 7) {
				cout << "What would you like to change?" << endl;
				cout << "1. Title" << endl;
				cout << "2. Author" << endl;
				cout << "3. Publisher" << endl;
				cout << "4. Quantity on hand" << endl;
				cout << "5. Wholesale cost" << endl;
				cout << "6. Retail price" << endl;
				cout << "7. Exit" << endl;
				cin >> selection;
				string newValue;
				switch (selection) {
				case 1:
					cout << "Current title: " << bookToEdit->getTitle() << endl;
					cout << "New title (leave empty for unchanged): ";
					newValue = getConsoleLine();
					if (newValue != "") bookToEdit->setTitle(newValue);
				case 2:
					cout << "Current author: " << bookToEdit->getAuthor() << endl;
					cout << "New author (leave empty for unchanged): ";
					newValue = getConsoleLine();
					if (newValue != "") bookToEdit->setAuthor(newValue);
				case 3:
					cout << "Current publisher: " << bookToEdit->getPublisher() << endl;
					cout << "New publisher (leave empty for unchanged): ";
					newValue = getConsoleLine();
					if (newValue != "") bookToEdit->setPublisher(newValue);
				case 4:
					cout << "Current quantity on hand: " << bookToEdit->getQuantityOnHand() << endl;
					cout << "New quantity on hand (leave empty for unchanged): ";
					newValue = getConsoleLine();
					if (newValue != "") bookToEdit->setQuantityOnHand(stoi(newValue));
				case 5:
					cout << "Current wholesale cost: $" << bookToEdit->getWholesaleCost() << endl;
					cout << "New wholesale cost (leave empty for unchanged): $";
					newValue = getConsoleLine();
					if (newValue != "") bookToEdit->setWholesaleCost(stof(newValue));
				case 6:
					cout << "Current retail price: " << bookToEdit->getRetailPrice() << endl;
					cout << "New retail price (leave empty for unchanged): ";
					newValue = getConsoleLine();
					if (newValue != "") bookToEdit->setRetailPrice(stof(newValue));
				}
			}
		}
		else {
			cout << "------------------------------------------------------------" << endl;
			cout << "Could not find a book with the specified ISBN.              " << endl;
			cout << "========================================================================================================================" << endl;
		}
	}
	void mainMenu() {
		int selection = 0;
		while (selection != 5) {
			cout << "========================================================================================================================" << endl;
			cout << "Welcome to Serendipity Bookstore's inventory database!" << endl;
			cout << "We have " << this->bookCount << " book(s) available right now." << endl;
			cout << "------------------------------------------------------------" << endl;
			cout << "1: Look up books" << endl;
			cout << "2: Add books" << endl;
			cout << "3: Delete books" << endl;
			cout << "4: Edit books" << endl;
			cout << "5: Exit" << endl;
			cout << endl;
			cout << "What would you like to do? (enter an option between 1 and 5): ";
			cin >> selection;
			cin.ignore();
			switch (selection) {
			case 1: {
				lookUpBook();
				break;
			}
			case 2: {
				addBook();
				break;
			}
			case 3: {
				deleteBook();
				break;
			}
			case 4: {
				cout << "Editing...";
				break;
			}
			default:
				break;
			}
		}
	}
};