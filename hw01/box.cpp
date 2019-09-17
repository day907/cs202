#include "box.hpp"
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

//Constructors
Box::Box(): _height(0), _width(0), _fill(true) {};

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
	return 0;
}