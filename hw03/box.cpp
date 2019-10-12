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

int Box::_currentboxes = 0;

//Constructors
//Default constructor
Box::Box() : _height(1), _width(1), _layout(FILLED) { _currentboxes++; };
//Constructor with width and height
Box::Box(const int& width, const int& height) :
	_height(height),
	_width(width),
	_layout(FILLED) {
	_currentboxes++; 
};
//Constructor with width, height, and fill
Box::Box(const int& width, const int& height, const layout& layout) :
	_height(height),
	_width(width),
	_layout(layout) {
	_currentboxes++;
};
Box::Box(const Box& cBox) :
	_height(cBox._height),
	_width(cBox._width),
	_layout(cBox._layout) {
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
//Type function
string Box::type() const {
	if (_layout == FILLED) return "Filled";
	else if (_layout == HOLLOW) return "HOLLOW";
	else if (_layout == CHECKERED) return "CHECKERED";
	return "error";
}
//Print function
//I just use one loop that tests the layout every loop
//seemed to involve the simplest code, but would it
//have been better to test layout once and write two / three
//seperate loops?
void Box::print(ostream& os) const {
	//Loop to print all boxes
	//loops for each unit of height
	for (int j = 0; j < _height; j++) {

		//loops for each unit of width
		for (int i = 0; i < _width; i++) {
			//Prints checkered box
			if (_layout == CHECKERED) {
				if ((i + j) % 2 == 0) {
					os << 'x';
				}
				else {
					os << ' ';
				}
			}

			//Prints filled or hollow box
			if (_layout==FILLED || i == 0 || i == _width - 1 || j == 0 || j == _height - 1) {
				os << 'x';
			}
			else {
				os << ' ';
			}
		}
		os << "\n";
	}
	return;
}

ostream& operator<<(ostream& os, const Box& theBox) {
	theBox.print(os);
	return os;
}

int Box::howMany() {
	return _currentboxes;
}