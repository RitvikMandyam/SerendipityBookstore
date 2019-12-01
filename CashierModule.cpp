#include "CashierModule.h"
#include "Helpers.h"

//Default Constructor 
CashierModule::CashierModule(InventoryDatabase& currentInventory)
	: currentInventory(currentInventory) {
};

// Destructor - it is used to remove bookSoldArray
CashierModule::~CashierModule() {
	delete[] bookSoldArray;
};

// Accessor 
// Get Book Sold Array Size 
int CashierModule::getSoldBookArraySize() {
	return this->size;
}

// Function to calculate sale tax
double CashierModule::calculateSaleTax(double saleTax, double retailPrice, int quantitySold) {
	saleTax = saleTax / 100;

	// Calculate total sale tax 
	double totalSaleTax = retailPrice * saleTax;

	// Calculate total price which customer will have to pay 
	double totalSalePrice = (totalSaleTax + retailPrice) * quantitySold;

	return totalSalePrice;
}


// Main Function 
void CashierModule::cashierMenu() {
	int selection = 0;
	while (selection != 3) {
		std::cout << "Welcome to Serendipity Cashier" << std::endl;
		std::cout << "1. Cashier" << std::endl;
		std::cout << "2. Cashier Report" << std::endl;
		std::cout << "3. Exit" << std::endl;
		std::cout << "What would you like to do? (enter a choice between 1 and 3): ";
		Helpers::correctingValidInput(selection);
		switch (selection)
		{
		case 1:
			cashierFunction();
			break;
		case 2:
			showCashierRecord();
			break;
		default:
			break;
		}
	}
}

// Print out sold book info 
void CashierModule::printSaleBookInfo(std::string title, std::string isbn, std::string author, std::string publiser)
{
	// Print out the information
	std::cout << "-------------------------------------------------------------------------------------------------------------------------------------------------" << std::endl;
	std::cout << "The book you are looking for is" << std::endl;
	std::cout << "Book " << title << std::endl;
	std::cout << "ISBN " << isbn << std::endl;
	std::cout << "Author " << author << std::endl;
	std::cout << "Publisher " << publiser << std::endl;
}


//Function to add sold Book To Temp Array
void CashierModule::addSoldBookdToArray(BookSoldInfo bookSoldObject) {
	// Declare new temp array
	BookSoldInfo* tempArray = new BookSoldInfo[size + 1];

	// Copy old array to new temp array 
	for (int i = 0; i < size; i++) {
		tempArray[i] = bookSoldArray[i];
	}

	// Add sold book to sale record at the end
	tempArray[size] = bookSoldObject;

	// Update sale record array 
	size++;

	// Free old memory 
	delete[] bookSoldArray;

	// Copy new array to original array 
	bookSoldArray = tempArray;
}

// Function to show field for the item 
void CashierModule::showField() {
	//Show customer record 
	std::cout << "CASHIER REPORT" << std::endl;
	std::cout << "=============================================================================================================================================" << std::endl;
	std::cout << left << setw(50) << "Item";
	std::cout << setw(25) << "ISBN";
	std::cout << setw(25) << "PRICE";
	std::cout << setw(25) << "QUANTITY";
	std::cout << setw(35) << "DATE SOLD" << std::endl;
}

// Overload function to show each iterm for the field 
void CashierModule::showField(std::string title, std::string isbn, double retailPrice, int quantity, std::string daySold) {
	std::cout << left << setw(50) << title;
	std::cout << setw(25) << isbn;
	std::cout << setw(25) << retailPrice;
	std::cout << setw(25) << quantity;
	std::cout << setw(35) << daySold << std::endl;
}

// Show customer receipt 
void CashierModule::showCustomeReceiptScreen(int startingPoint, double saleTax) {
	// Ask custermer which method do they want to pay 
	int choice;
	std::string selection;
	std::cout << "Please choose a payment method (1/Credit card       2/Cash)? ";
	std::cin >> choice;
	while (choice != 1 && choice != 2)
	{
		std::cout << "Invalid entry. Please choose your payment method (1/Credit card       2/Cash)";
		std::cin >> choice;
	}
	if (choice == 1)
		selection = "Credit card";
	else
		selection = "Cash";

	//Show customer record 
	showField();

	// Loop through array and show item
	// it will also update subtotal and total of all sold item
	double subTotal = 0.0;
	double totalPrice = 0.0;

	for (int i = startingPoint; i < size; i++) {
		Book* tempBook = bookSoldArray[i].getBookObject();

		// Use Overload Function to show each book sold
		showField(tempBook->getTitle(), tempBook->getIsbn(), tempBook->getRetailPrice(),
			bookSoldArray[i].getQuantitySale(), bookSoldArray[i].getDateSold());
		// Update subtotal
		subTotal = subTotal + (bookSoldArray[i].getQuantitySale() * tempBook->getRetailPrice());

		// Update total price 
		totalPrice = totalPrice + bookSoldArray[i].getTotalSalePrice();
	}
	std::cout << std::endl;
	// Let Customer know Subtotal, Tax and Total Price
	std::cout << "SUBTOTAL " << subTotal << std::endl;
	std::cout << "TAX " << saleTax << "%" << std::endl;
	std::cout << "TOTAL " << totalPrice << std::endl;
	std::cout << "=============================================================================================================================================" << std::endl;
	std::cout << "Paid by " << selection << std::endl;
	std::cout << "=============================================================================================================================================" << std::endl;
	std::cout << "Thank you so much for your purchase!" << std::endl;
	std::cout << "See you again" << std::endl;

}

// Main Cashier Function 
void CashierModule::cashierFunction() {

	// Validate inventory if there is book in inventory or not 
	// if not it will exit
	if (currentInventory.getBookCount() == 0) {
		std::cout << "There is no book(s) in inventory" << std::endl;
		return;
	}

	// Start cashier Function
	// Get the current inventory
	Book* currentBookArray = currentInventory.getBooksDatabase();

	// Create temp Book Sold Array 
	BookSoldInfo* tempBookSoldArray = new BookSoldInfo[1];

	// Asking Customer
	char confirm;
	double saleTax;
	std::cout << "Please enter sale tax (ex: 9.75 for 9.75%): ";
	Helpers::correctingValidInput(saleTax);
	std::cin.ignore();

	// Variable for keeping track of temp array size
	int lastIndex = size;
	do {
		// Asking ISBN number
		std::string isbn;
		std::cout << "Enter the ISBN Number: ";
		std::getline(std::cin, isbn);

		// Checking if the book exist, if not
		// ask restart the loop 
		Book* bookSold = currentInventory.findBook(isbn);
		if (bookSold == nullptr) continue;

		// Print out the information
		printSaleBookInfo(bookSold->getTitle(), bookSold->getIsbn(), bookSold->getAuthor(), bookSold->getPublisher());

		// confirm to continue the sale or not
		// by restart the loop

		std::cout << "Is it correct (y/n)? ";
		std::cin >> confirm;
		while (toupper(confirm) != 'Y' && toupper(confirm) != 'N')
		{
			std::cout << "Invalid entry. Please enter 'y/Y' to confirm or 'n/N' to go back to main menu. Re-enter: ";
			std::cin >> confirm;
		}
		if (toupper(confirm) == 'N') continue;

		// Asking for quantity and calculating total price 
		int quantitySold;
		std::cout << "Price " << bookSold->getRetailPrice() << std::endl;
		std::cout << "There are " << bookSold->getQuantityOnHand() << std::endl;
		std::cout << "How many ? ";
		Helpers::correctingValidInput(quantitySold);

		// IF quantity sold is greater than quantity on Hand
		// Let user konw and ask if they want to contiue buying
		if (quantitySold > bookSold->getQuantityOnHand()) {
			std::cout << "Not enough item in the stock" << std::endl;
		}
		else {

			// Let user know total price before tax 
			std::cout << "Amount due before Tax: " << bookSold->getRetailPrice() * quantitySold << std::endl;

			// Asking for day, month and year  sold 
			int daySold, monthSold, yearSold;
			std::cout << "Day Sold (today date)";
			Helpers::correctingValidInput(daySold);
			std::cout << "Month Sold (today month) ";
			Helpers::correctingValidInput(monthSold);
			std::cout << "Year Sold (today year)";
			Helpers::correctingValidInput(yearSold);
			std::cin.ignore();

			// Start calculating total price and add bookSold to temp array
			double totalPrice = calculateSaleTax(saleTax, bookSold->getRetailPrice(), quantitySold);

			// Update inventory 
			int newRemaining = bookSold->getQuantityOnHand() - quantitySold;
			bookSold->setQuantityOnHand(newRemaining);

			// Initialize book sold info object and update temp array size
			BookSoldInfo bookSoldObject = BookSoldInfo(bookSold, saleTax, totalPrice, quantitySold, newRemaining, daySold, monthSold, yearSold);

			// Add book object to temparray 
			addSoldBookdToArray(bookSoldObject);
		}
		std::cout << "Do you want to make another purchase (Enter 'n/N' to stop)? ";
		std::cin >> confirm;
	} while (toupper(confirm) != 'N');

	// Show Customer Screen
	showCustomeReceiptScreen(lastIndex, saleTax);
}

// Show Cashier Record
void CashierModule::showCashierRecord() {

	// Show Field Title 
	showField();


	// If no book sold yet, let user know and return
	if (size == 0) {
		std::cout << "There is no sold book yet" << std::endl;
		return;
	}

	// Loop through sold book array and show 
	// each sold item 
	for (int i = 0; i < size; i++) {
		Book* tempBook = bookSoldArray[i].getBookObject();

		// Use Overload Function to show each book sold
		showField(tempBook->getTitle(), tempBook->getIsbn(), tempBook->getRetailPrice(),
			bookSoldArray[i].getQuantitySale(), bookSoldArray[i].getDateSold());
	}
}