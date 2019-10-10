//Jordan Day
//10/08/19
//CS202
//Homework 2

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
#include <sstream>
using std::istringstream;

int getIdFromFile(const string & fileName,
		istream & instream, ostream & outstream) {
	string theline, username, testname;
	int id;
	ifstream thefile;
	thefile.open(fileName);
	if (!thefile) return -1; //returns -1 if file didn't open

	//Loops through all inputs
	while (true) {
		//Retrieves username input, exits loop if no input found
		instream >> username;
		if (!instream) {
			break;
		}

		//sequential search through formatted unsorted file
		thefile.seekg(0);
		while (true) {
			getline(thefile, theline);
			//outputs error if username not found
			if (!thefile) {
				if (thefile.eof()) {
					thefile.clear();
					outstream << "error" << endl;
					break;
				}
			}

			//takes username token from theline and compares it to username
			//then truncates the username and sends the id to outstream
			istringstream isstr1(theline);
			isstr1 >> testname;
			if(testname == username) {
				istringstream isstr2(theline.substr(testname.length()), theline.length());
				isstr2 >> id;
				if (isstr2) outstream << id << endl;
				break;
			}
		}
	}
	thefile.close();
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