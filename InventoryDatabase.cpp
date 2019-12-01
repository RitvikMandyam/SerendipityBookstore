#include "InventoryDatabase.h"

using namespace std;

// Default constructor
InventoryDatabase::InventoryDatabase() {};

// Constructor with parameter 
InventoryDatabase::InventoryDatabase(string invFile) {
	this->invFilePath = invFile;
	this->bookCount = Helpers::getDataFIleSize(invFile);
	this->books = new Book[this->maxBooks];
	this->books = Helpers::installDataToInventory(invFile, this->maxBooks);
}

// Accessor
// return array books object
Book* InventoryDatabase::getBooksDatabase() {
	return this->books;
}

// Get book in inventory
int InventoryDatabase::getBookCount() {
	return this->bookCount;
}

//Function
// Find book object 
Book* InventoryDatabase::findBook(string isbn, int* index) {
	for (int i = 0; i < this->bookCount; i++) {
		if (this->books[i].getIsbn() == isbn) {
			if (index != nullptr) *index = i;
			return &(this->books[i]);
		}
	}
	if (index != nullptr) *index = -1;
	return nullptr;
}

// Function to look up book 
void InventoryDatabase::lookUpBook() {
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

// Function to delete Book 
void InventoryDatabase::deleteBook() {
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

// Function to add book 
void InventoryDatabase::addBook() {
	cout << "------------------------------------------------------------" << endl;
	cout << "Adding a new book                                          " << endl;
	cout << "------------------------------------------------------------" << endl;
	if (this->bookCount < this->maxBooks) {
		Book* book = new Book;
		string isbn;
		Book* bookExists;

		cout << "ISBN: ";
		std::getline(std::cin, isbn);
		bookExists = findBook(isbn);
		if (bookExists == nullptr) {
			book->setIsbn(Helpers::getConsoleLine());
		}
		else {
			cout << "We already have this book in our inventory, adding another copy.";
			book->setQuantityOnHand(book->getQuantityOnHand() + 1);
			return;
		}
		cout << "Title: ";
		book->setTitle(Helpers::getConsoleLine());
		cout << "Author: ";
		book->setAuthor(Helpers::getConsoleLine());
		cout << "Publisher: ";
		book->setPublisher(Helpers::getConsoleLine());
		cout << "Quantity on hand: ";
		book->setQuantityOnHand(stoi(Helpers::getConsoleLine()));
		cout << "Wholesale cost: $";
		book->setWholesaleCost(stof(Helpers::getConsoleLine()));
		cout << "Retail price: $";
		book->setRetailPrice(stof(Helpers::getConsoleLine()));
		cout << "Day Add (dd): ";
		book->setDay(stoi(Helpers::getConsoleLine()));
		cout << "Month Add (mm): ";
		book->setMonth(stoi(Helpers::getConsoleLine()));
		cout << "Year Add (yyyy): ";
		book->setYear(stoi(Helpers::getConsoleLine()));
		books[this->bookCount++] = *book;
		delete book;
		cout << "========================================================================================================================" << endl;
	}
	else {
		cout << "No more space in inventory database!";
		cout << "========================================================================================================================" << endl;
	}

}

// Function to edit book 
void InventoryDatabase::editBook() {
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
				newValue = Helpers::getConsoleLine();
				if (newValue != "") bookToEdit->setTitle(newValue);
			case 2:
				cout << "Current author: " << bookToEdit->getAuthor() << endl;
				cout << "New author (leave empty for unchanged): ";
				newValue = Helpers::getConsoleLine();
				if (newValue != "") bookToEdit->setAuthor(newValue);
			case 3:
				cout << "Current publisher: " << bookToEdit->getPublisher() << endl;
				cout << "New publisher (leave empty for unchanged): ";
				newValue = Helpers::getConsoleLine();
				if (newValue != "") bookToEdit->setPublisher(newValue);
			case 4:
				cout << "Current quantity on hand: " << bookToEdit->getQuantityOnHand() << endl;
				cout << "New quantity on hand (leave empty for unchanged): ";
				newValue = Helpers::getConsoleLine();
				if (newValue != "") bookToEdit->setQuantityOnHand(stoi(newValue));
			case 5:
				cout << "Current wholesale cost: $" << bookToEdit->getWholesaleCost() << endl;
				cout << "New wholesale cost (leave empty for unchanged): $";
				newValue = Helpers::getConsoleLine();
				if (newValue != "") bookToEdit->setWholesaleCost(stof(newValue));
			case 6:
				cout << "Current retail price: " << bookToEdit->getRetailPrice() << endl;
				cout << "New retail price (leave empty for unchanged): ";
				newValue = Helpers::getConsoleLine();
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

// Main Menu 
void InventoryDatabase::mainMenu() {
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
		Helpers::correctingValidInput(selection);
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