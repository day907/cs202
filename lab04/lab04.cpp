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

	//1.
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

	//2.
	int nCopies;
	string copyLine;

	//retrieves integer input
	while (true) {
		//prompt
		cout << "Input positive integer: ";

		//input retrieval + error checking
		cin >> nCopies;
		if (!cin || nCopies < 0) {
			cin.clear();
			cin.ignore(999, '\n');
			cout << "Improper input, try again" << endl;
			continue;
		}
		cin.clear();
		cin.ignore(999, '\n');
		break;
	}

	//retrieves string input
	cout << "Input a line of text: ";
	getline(cin, copyLine);

	//3.
	ofstream ofile("output.txt", std::ios::app);
	for (int i = 0; i < nCopies; i++) {
		ofile << copyLine << '\n';
	}

	return 0;
}