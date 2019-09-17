#include "box.hpp"
#include <iostream>
using std::cout;
using std::cin;
using std::endl;
#include <string>
using std::string;
#include <ostream>
using std::ostream;

//Constructors
Box::Box(): _height(1), _width(1), _fill(true) {
	cout << "default constructor" << endl;
};

Box::Box(const int& width, const int& height) :
	_height(height),
	_width(width),
	_fill(true)
	{};

Box::Box(const int& width, const int& height, const bool& fill) :
	_height(height),
	_width(width),
	_fill(fill)
{};

//Getter and Setter functions
int const Box::getHeight() {
	return _height;
}
void Box::setHeight(int & height) {
	_height = height;
}
int const Box::getWidth() {
	return _width;
}
void Box::setWidth(int & width) {
	_width = width;
}
bool const Box::getFill() {
	return _fill;
}
void Box::setFill(bool & fill) {
	_fill = fill;
}

//Utility functions
void Box::print(/*ostream oss1*/) {

	//loops for each unit of height
	for (int j = 0; j < _height; j++) {

		//loops for each unit of width
		for (int i = 0; i < _width; i++) {
			//checks if X should be printed
			if (_fill || i == 0 || i == _width - 1 || j == 0 || j == _height-1) {
				cout << 'x';
			}
			else {
				cout << ' ';
			}
		}
		cout << "\n";
	}
}

int main() {
	Box b(10, 5, false);
	cout << b.getHeight() << " " << b.getWidth() << " " << b.getFill() << endl;
	b.print();
	return 0;
}