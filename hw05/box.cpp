//CS202
//Jordan Day
//09/26/19
//HW01
//"box.cpp"
//Contains constructors and member functions for class Box
//for use in HW01

#include "box.hpp"
#include <iostream>
using std::ostream;
#include <string>
using std::string;
#include <memory>
using std::unique_ptr;

int Box::_currentboxes = 0;

//Constructors
//Default constructor
Box::Box() : _height(1), _width(1) { _currentboxes++; };

//Constructor with width and height
Box::Box(const int& width, const int& height) :
	_height(height),
	_width(width) {
	_currentboxes++;
};

//Copy constructor
Box::Box(const Box& cBox) :
	_height(cBox._height),
	_width(cBox._width) {
	_currentboxes++;
}
//Destructor
Box::~Box() { _currentboxes--; };

//Getter and Setter member functions
int Box::getHeight() const {
	return _height;
}
void Box::setHeight(int height) {
	_height = height;
}
int Box::getWidth() const {
	return _width;
}
void Box::setWidth(int width) {
	_width = width;
}


int Box::howMany() {
	return _currentboxes;
}



//Box Factory, takes param c to determine what type of box to make,
//ints w and h assign box's width and height.
unique_ptr<Box> boxFactory(char c, int w, int h) {
	switch (c) {
	case 'f':
	case 'F':
		return std::make_unique<FilledBox>(w,h);

	case 'h':
	case 'H':
		return std::make_unique<HollowBox>(w,h);

	case 'c':
	case 'C':
		return std::make_unique<CheckeredBox>(w,h);

	default:
		return std::make_unique<FilledBox>(w,h);
	}
}

//<< overload for box class
ostream& operator<<(ostream& os, const Box& theBox) {
	theBox.print(os);
	return os;
}

//FILLED BOX DERIVED CLASS
//
//overrides to virtual functions in Box class
FilledBox::~FilledBox() {};
string FilledBox::type() const {
	return "Filled";
}
void FilledBox::print(ostream& os) const {
	for (int y = 0; y < getHeight(); y++) {
		for (int x = 0; x < getWidth(); x++) {
			os << 'x';
		}
		os << '\n';
	}
	return;
}



//HOLLOW BOX DERIVED CLASS
//
//overrides to virtual functions in Box class
HollowBox::~HollowBox() {};
string HollowBox::type() const {
	return "Hollow";
}
void HollowBox::print(ostream& os) const {

	for (int y = 0; y < getHeight(); y++) {
		for (int x = 0; x < getWidth(); x++) {
			if (y == 0 || y == getHeight() - 1 || x == 0 || x == getWidth() - 1) {
				os << 'x';
			}
			else {
				os << ' ';
			}
		}
		os << '\n';
	}
	return;
}



//CHECKERED BOX DERIVED CLASS
//
//overrides to virtual functions in Box class
CheckeredBox::~CheckeredBox() {};
string CheckeredBox::type() const {
	return "Checkered";
}
void CheckeredBox::print(ostream& os) const {
	//loops for each unit of height
	for (int j = 0; j < getHeight(); j++) {

		//loops for each unit of width
		for (int i = 0; i < getWidth(); i++) {
			if ((i + j) % 2 == 0) {
				os << 'x';
			}
			else {
				os << ' ';
			}
			continue;
		}
		os << '\n';
	}
	return;
}