#include "BookSoldInfo.h"

// Default constructor
BookSoldInfo::BookSoldInfo()
{
	*bookSold;
	dateSold;
	saleTax = 0.0;
	totalSalePrice = 0.0;
	quantitySale = 0;
	quanityRemaining = 0;
}

// Constructor which takes parameter
BookSoldInfo::BookSoldInfo(Book *bookSold, double saleTax, double totalSalePrice, int quantitySale, int quanityRemaining, int daySold
	, int monthSold, int yearSold) {
	this->bookSold = bookSold;
	this->saleTax = saleTax;
	this->totalSalePrice = totalSalePrice;
	this->quantitySale = quantitySale;
	this->quanityRemaining = quanityRemaining;
	dateSold = Date(daySold, monthSold, yearSold);
}

// Default Destructor
BookSoldInfo::~BookSoldInfo() {};

// Accessor 
Book* BookSoldInfo::getBookObject() { return bookSold; }
int BookSoldInfo::getQuantityRemaining() { return quanityRemaining; };
int BookSoldInfo::getQuantitySale() { return quantitySale; };
double BookSoldInfo::getSaleTax() { return saleTax; };
double BookSoldInfo::getTotalSalePrice() { return totalSalePrice; };
string BookSoldInfo::getDateSold() { return dateSold.toString(); };

