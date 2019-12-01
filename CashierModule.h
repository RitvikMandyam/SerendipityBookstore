#pragma once


#include <iomanip>
#include "BookSoldInfo.h"
#include "InventoryDatabase.h"

class CashierModule {
private:
	InventoryDatabase& currentInventory;
	BookSoldInfo* bookSoldArray;
	int size;
public:
	// Default constructor
	CashierModule();

	// Constructor which take parameter 
	CashierModule(InventoryDatabase& currentInventory);

	// Destructor
	~CashierModule();

	// Acessor 
	int getSoldBookArraySize();

	// Cashier Menu
	void cashierMenu();

	// Function to add sold Book to Array 
	void addSoldBookdToArray(BookSoldInfo bookSoldObject);

	// Function to calculate sale tax
	double calculateSaleTax(double saleTax, double retailPrice, int quantitySold);

	// Print out sale book info 
	void printSaleBookInfo(std::string title, std::string isbn, std::string author, std::string publisher);

	// Main Cashier Function
	void cashierFunction();


	// Function to print out recipe
	void showCustomeReceiptScreen(int size, double saleTax);

	// Function to show field for the item 
	void showField();

	// Overload function to show each iterm for the field 
	void showField(std::string title, std::string isbn, double retailPrice, int quantity, std::string daySold);

	// FUnction to show book sold array element 
	// or get cashier record
	void showCashierRecord();
};