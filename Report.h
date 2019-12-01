#pragma once
#include "Helpers.h"
#include "Book.h"
#include "Date.h"
#include "InventoryDatabase.h"
#include <fstream>
#include <string>
#include <iostream>
class ReportModule
{
private:
	Book* Books;
	std::string information;

	int menu;
	int bookcount;
	InventoryDatabase* currentInventori;


public:
	ReportModule(InventoryDatabase& currentInventori);
	void ReportMainMenu(InventoryDatabase& currentInventori);
	void ReportInventoryList(InventoryDatabase& currentInventori);
	ReportModule() {

		Books = NULL;
		menu = 0;
		bookcount = 0;
		information = '\0';

	}
	void ReportWholeSaleValue(InventoryDatabase& currentInventori);
	void ReportRetailValue(InventoryDatabase& currentInventori);
	void ReportListByQuantity(InventoryDatabase& currentInventori);
	void ReportListByCost(InventoryDatabase& currentInventori);
	void ReportListByAge(InventoryDatabase& currentInventori);;
};

