#include <iostream>
#include <string>
#include <ctime>
#include "Book.h"
#include "InventoryDatabase.h"

using namespace std;

void mainMenu();

int main() {
	mainMenu();
	system("pause");
	return 0;
}

void mainMenu() {
	int selection;
	cout << "Welcome to Serendipity Bookstore!" << endl;
	cout << "1. Make sale" << endl;
	cout << "2. Check inventory" << endl;
	cout << "3. Create reports" << endl;
	cout << "What would you like to do? (enter a choice between 1 and 3): ";
	cin >> selection;
	switch (selection) {
	case 2:
		InventoryDatabase db = InventoryDatabase("inv.dat");
		db.mainMenu();
		break;
	}
}