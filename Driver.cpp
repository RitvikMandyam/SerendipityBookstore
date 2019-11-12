#include <iostream>
#include <string>
#include <ctime>
#include "Book.h"
#include "CashierModule.cpp"
#include "InventoryDatabase.cpp"

using namespace std;

std::string getConsoleLine();
int mainmenuapplication();
int main() {
	int mainmenu = 99;
	mainmenu = mainmenuapplication();
	
	switch (mainmenu) {
	case 1:
		pointOfSale();
	case 2:
		mainMenuInventory();
	case 3:

	case 4:

	case 0: 
		system("pause");
		return 0;
	}
	cout << book->bookDataAsString();
	system("pause");
	return 0;
}
int mainmenuapplication() {
	int menu = 0;
	cout << "Serenidipity Bookstore Software Application" << endl
		cout << "Type 1 to Cashier Module Application" << endl;
	cout << "Type 2 to Inventory Database Module Application" << endl;
	cout << "Type 3 to Report Module Application" << endl;
	cout << "Or press 0 to leave" << endl;
	cin >> menu;

	return menu;
}
