//CS202
//Jordan Day
//Lab 4
//9/19/19

#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <sstream>
using std::istringstream;
using std::ostringstream;
#include <string>
using std::string;
#include <fstream>
using std::ofstream;
using std::ifstream;

int main() {
	string inString;
	ifstream fileIn("test.txt");

	//Checks if file was found
	if (!fileIn) {
		cout << "file did not open" << endl;
	}

	while (fileIn) {
		if (fileIn.eof()) {
			cout << "end of file";
			break;
		}
		getline(fileIn, inString);
		cout << inString << endl;
	}

	return 0;
}