#include <iostream>
#include <string>

using namespace std;
std::string getConsoleLine()
{
	string str;
	getline(cin, str, '\n');
	return str;
}

string* splitString(string input, string delimiter, int* length) {
	size_t pos = 0;
	string* tokens = new string[1024];
	int token_index = 0;
	while ((pos = input.find(delimiter)) != string::npos) {
		string token = input.substr(0, pos);
		tokens[token_index] = token;
		token_index++;
	}
	if (token_index < 0) {
		string* ret = new string[token_index - 1];
		for (int i = 0; i < token_index; i++) {
			ret[i] = tokens[i];
		}
		*length = token_index - 1;
		delete[] tokens;
		return ret;
	}
	else {
		return nullptr;
	}
}