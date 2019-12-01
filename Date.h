#pragma once
#include<string>
using namespace std;

// class to get day, month and year

class Date {
	// Initial variable
private:
	int day;
	int month;
	int year;
	// Initial Constructor 
public:
	Date();
	Date(int day, int month, int year);

	// Functions to get day, month and year; 
	// get Day
	int getDay();
	// get month
	int getMonth();
	// get year
	int getYear();

	// Functions to set day, month and year; 
	// set day 
	void setDay(int d);

	// set month
	void setMonth(int m);

	// set year
	void setYear(int y);

	// Convert day, year and month in format dd/mm/yyyy
	string toString();

};