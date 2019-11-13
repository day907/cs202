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

//Commented out for use later in derived classes
//
//void Box::print(ostream& os) const {
//	//Loop to print all boxes
//	//loops for each unit of height
//	for (int j = 0; j < _height; j++) {
//
//		//loops for each unit of width
//		for (int i = 0; i < _width; i++) {
//			//Prints checkered box
//			if (_layout == CHECKERED) {
//				if ((i + j) % 2 == 0) {
//					os << 'x';
//				}
//				else {
//					os << ' ';
//				}
//				continue;
//			}
//
//			//Prints filled or hollow box
//			if (_layout == FILLED || i == 0 || i == _width - 1 || j == 0 || j == _height - 1) {
//				os << 'x';
//			}
//			else {
//				os << ' ';
//			}
//		}
//		os << "\n";
//	}
//	return;
//}

ostream& operator<<(ostream& os, const Box& theBox) {
	theBox.print(os);
	return os;
}

int Box::howMany() {
	return _currentboxes;
}

unique_ptr<Box> boxFactory(char c, int w, int h) {
	switch (c) {
	case 'f':
	case 'F':
		return std::make_unique<FilledBox>();

	case 'h':
	case 'H':
		return std::make_unique<HollowBox>();

	case 'c':
	case 'C':
		return std::make_unique<CheckeredBox>();

	default:
		return std::make_unique<FilledBox>();
	}
}


//FILLED BOX DERIVED CLASS
//
//Constructors
//FilledBox::FilledBox() : Box() {};
//FilledBox::FilledBox(const int& width, const int& height)
//	: Box(width, height)
//{};

//overrides to virtual function in Box class
string FilledBox::type() const {
	return "Filled";
}

void FilledBox::print(ostream&) const {

	return;
}



//HOLLOW BOX DERIVED CLASS
//
//Constructors
//HollowBox::HollowBox() : Box() {};
//HollowBox::HollowBox(const int& width, const int& height)
//	: Box(width, height)
//{};

//overrides to virtual function in Box class
string HollowBox::type() const {
	return "Hollow";
}
void HollowBox::print(ostream&) const {

	return;
}



//CHECKERED BOX DERIVED CLASS
//
//Constructors
//CheckeredBox::CheckeredBox() : Box() {};
//CheckeredBox::CheckeredBox(const int& width, const int& height)
//	: Box(width, height)
//{}; 

//overrides to virtual function in Box class
string CheckeredBox::type() const {
	return "Checkered";
}
void CheckeredBox::print(ostream&) const {
	
	return;
}