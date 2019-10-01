#include <string>
using std::string;
#include <iostream>
using std::istream;
using std::ostream;
#include <fstream>
using std::ifstream;
using std::cout;
using std::cin;

int getIdFromFile(const string & fileName,
	const istream & instream, ostream & outstream) {
	
	ifstream theFile;
	theFile.open(fileName);

	if (theFile) {
		outstream << "File opened";
	}
	else if (!theFile) {
		outstream << "File did not open";
	}

	theFile.close();
	return 0;
}

int main() {
	getIdFromFile("test.txt", cin, cout);
	return 0;
}