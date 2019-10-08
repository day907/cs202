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
	string theline, username;
	int id=12;
	ifstream thefile;
	thefile.open(fileName);
	if (!thefile) return -1; //returns -1 if file didn't open


	while (true) {
		instream >> username;
		if (!instream) {
			break;
		}

		//sequential search through formatted unsorted file
		while (true) {
			//getline might not be ideal for this
			getline(thefile, theline);
			//outputs error if username not found
			if (!thefile) {
				if (thefile.eof()) {
					outstream << "error" << endl;
					break;
				}
			}

			//probably a crude solution? feels very cs201
			if(theline.substr(0, username.length()) == username) {
				istringstream isstr(theline.substr(username.length()), theline.length());
				isstr >> id;
				outstream << id << endl;
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