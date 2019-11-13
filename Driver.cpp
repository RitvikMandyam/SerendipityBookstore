#include <iostream>
#include <string>
#include <ctime>
#include "Book.h"
#include "InventoryDatabase.h"

using namespace std;
int main() {
	InventoryDatabase db = InventoryDatabase("inv.dat");
	db.mainMenu();
	system("pause");
	return 0;
}