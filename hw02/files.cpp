#include <string>
using std::string;
#include <iostream>
using std::istream;
using std::ostream;
#include <fstream>
using std::ifstream;
using std::cout;
using std::cin;
using std::getline;
using std::endl;

int getIdFromFile(const string & fileName,
		const istream & instream, ostream & outstream) {
	string theline;
	ifstream theFile;
	theFile.open(fileName);

	while (true) {
		getline(theFile, theline);
		if (!theFile) {
			if (theFile.eof()) {
				break;
			}
		}
		outstream << theline << endl; //for testing
	}

	theFile.close();
	return 0;
}

int main() {
	getIdFromFile("test.txt", cin, cout); //for testing
	return 0;
}