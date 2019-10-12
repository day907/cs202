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

//Constructors
//Default constructor
Box::Box() : _height(1), _width(1), _layout(FILLED) {};
//Constructor with width and height
Box::Box(const int& width, const int& height) :
	_height(height),
	_width(width),
	_layout(FILLED)
{};
//Constructor with width, height, and fill
Box::Box(const int& width, const int& height, const layout& layout) :
	_height(height),
	_width(width),
	_layout(layout)
{};

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
}
//Print function
void Box::print(ostream& os) const {

	//loops for each unit of height
	for (int j = 0; j < _height; j++) {

		//loops for each unit of width
		for (int i = 0; i < _width; i++) {
			//checks if X should be printed
			//CHANGE LAYOUT CHECK
			if (_layout || i == 0 || i == _width - 1 || j == 0 || j == _height - 1) {
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