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
		istream & instream, ostream & outstream) {
	string theline, username;
	int id;
	ifstream theFile;
	theFile.open(fileName);
	if (!theFile) return -1; //returns -1 if file didn't open

	while (true) {//repeatedly
		//get username input from instream
		instream >> username;
		if (!instream) {
			break;
		}

		//sequential search through formatted unsorted file
		while (true) {
			//getline might not be ideal for this
			getline(theFile, theline);

			//outputs error if username not found
			if (!theFile) {
				if (theFile.eof()) {
					outstream << "error" << endl;
					break;
				}
			}



			//TODO check for matching username, get id from line
			outstream << theline << endl; //for testing
		}
	}
	theFile.close();
	return 0;
}

void numberChase(const string& filename, ostream& output) {
	ifstream thefile;
	thefile.open(filename, std::ios::binary);
	if (!thefile) return;
	int currentvalue=0;

	//search loop
	while (currentvalue >=0) {
		thefile.seekg(currentvalue*sizeof(int));
		thefile.read(reinterpret_cast<char*>(&currentvalue), sizeof(int));
		output << currentvalue << "\n";
	}

	thefile.close();
	return;
}

/*		if (thefile.eof()) {
thefile.clear();
thefile.seekg(0);
continue;
		}*/