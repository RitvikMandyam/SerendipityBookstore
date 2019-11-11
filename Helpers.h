#include <iostream>
#include <string>

using namespace std;
std::string getConsoleLine()
{
	string str;
	getline(cin, str, '\n');
	return str;
}
