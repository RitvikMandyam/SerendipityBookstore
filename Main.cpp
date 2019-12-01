// bookSeller1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "InventoryDatabase.h"
#include "CashierModule.h"
#include "Helpers.h"
#include "ReportModule.h"
using namespace std;

void mainMenu();

int main() {
	mainMenu();
	system("pause");
	return 0;
}

void mainMenu() {
	InventoryDatabase db = InventoryDatabase("inv.txt");
	CashierModule cashier = CashierModule(db);
	ReportModule Report = ReportModule(db);
	//*********** when you finsih the report, please include the report module here 
	int selection;
	std::string answer;
	do {
		cout << "Welcome to Serendipity Bookstore!" << endl;
		cout << "1. Make sale" << endl;
		cout << "2. Check inventory" << endl;
		cout << "3. Create reports" << endl;
		cout << "4. Exit" << endl;
		cout << "What would you like to do? (enter a choice between 1 and 4): ";
		Helpers::correctingValidInput(selection);
		switch (selection) {
		case 1:
			cashier.cashierMenu();
			break;
		case 2:
			db.mainMenu();
			break;
		case 3:

			Report.ReportMainMenu(db);
			break;
			//*********** when you finish the report, please include the report module here as case 3
		}
		std::cout << "Do you want to continue? ";
		std::getline(std::cin, answer);
	} while (answer != "N");
}
