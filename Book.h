#include <string>
#include <ctime>

using namespace std;
class Book {
private:
	string isbn;
	string title;
	string author;
	string publisher;
	time_t dateAdded;
	unsigned int quantityOnHand;
	float wholesaleCost;
	float retailPrice;

public:
	Book(string isbn, string title, string author, string publisher, time_t dateAdded, unsigned int quantityOnHand, float wholesaleCost, float retailPrice) {
		this->isbn = isbn;
		this->title = title;
		this->author = author;
		this->publisher = publisher;
		this->dateAdded = dateAdded;
		this->quantityOnHand = quantityOnHand;
		this->wholesaleCost = wholesaleCost;
		this->retailPrice = retailPrice;
	}

	Book() {
		this->isbn = "";
		this->title = "";
		this->author = "";
		this->publisher = "";
		this->dateAdded = time(NULL);
		this->quantityOnHand = 0;
		this->wholesaleCost = 0;
		this->retailPrice = 0;
	}

	string getIsbn() {
		return this->isbn;
	}
	string getTitle() {
		return this->title;
	}
	string getAuthor() {
		return this->author;
	}
	string getPublisher() {
		return this->publisher;
	}
	time_t getDateAdded() {
		return this->dateAdded;
	}
	unsigned int getQuantityOnHand() {
		return this->quantityOnHand;
	}
	float getWholesaleCost() {
		return this->wholesaleCost;
	}
	float getRetailPrice() {
		return this->retailPrice;
	}

	void setIsbn(string isbn) {
		this->isbn = isbn;
	}
	void setTitle(string title) {
		this->title = title;
	}
	void setAuthor(string author) {
		this->author = author;
	}
	void setPublisher(string publisher) {
		this->publisher = publisher;
	}
	void setDateAdded(time_t dateAdded) {
		this->dateAdded = dateAdded;
	}
	void setQuantityOnHand(unsigned int quantityOnHand) {
		this->quantityOnHand = quantityOnHand;
	}
	void setWholesaleCost(float wholesaleCost) {
		this->wholesaleCost = wholesaleCost;
	}
	void setRetailPrice(float retailPrice) {
		this->retailPrice = retailPrice;
	}

	string bookDataAsString() {
		const time_t dateAdded = this->getDateAdded();
		char str[26];
		ctime_s(str, sizeof str, &dateAdded);
		string data = this->getIsbn() + "|" +
			this->getTitle() + "|" +
			this->getAuthor() + "|" +
			this->getPublisher() + "|" +
			str + "|" +
			to_string(this->getQuantityOnHand()) + "|" +
			to_string(this->getWholesaleCost()) + "|" +
			to_string(this->getRetailPrice());
		return data;
	}
};