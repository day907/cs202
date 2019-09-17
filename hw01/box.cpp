#include "box.hpp"
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

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

int main() {
	Box b;
	cout << b.getHeight() << " " << b.getWidth() << " " << b.getFill();
	return 0;
}