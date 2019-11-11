#include "Helpers.h"
#include "Book.h"

using namespace std;
int main() {
	return 0;
}

void addBook() {
	Book* book = new Book;
	cout << "Enter the ISBN of the book: ";
	book->setIsbn(getConsoleLine());
	cout << "Enter the title of the book: ";
	book->setTitle(getConsoleLine());
	cout << "Enter the author of the book: ";
	book->setAuthor(getConsoleLine());
	cout << "Enter the publisher of the book: ";
	book->setPublisher(getConsoleLine());
	book->setDateAdded(time(NULL));
	cout << "Enter the quantity of the book on hand: ";
	book->setQuantityOnHand(stoi(getConsoleLine()));
	cout << "Enter the wholesale cost of the book: ";
	book->setWholesaleCost(stof(getConsoleLine()));
	cout << "Enter the retail price of the book: ";
	book->setRetailPrice(stof(getConsoleLine()));
}

void mainMenu() {
	int selection;
	cout << "Welcome to Serendipity Bookstore's inventory database!" << endl;
	cout << "1: Find books" << endl;
	cout << "2: Add books" << endl;
	cout << "3: Delete books" << endl;
	cout << "4: Edit books" << endl;
	cout << "What would you like to do? ";
	cin >> selection;
	switch (selection) {
	case 1:
		cout << "Searching...";
		break;

	case 2:
		cout << "Searching...";
		break;

	case 3:
		cout << "Searching...";
		break;

	case 4:
		cout << "Searching...";
		break;
	}
}