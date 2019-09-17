#include "box.hpp"


//Getter and Setter functions
int Box::getHeight() {
	return _height;
}
void Box::setHeight(int height) {
	_height = height;
}
int Box::getWidth() {
	return _width;
}
void Box::setWidth(int width) {
	_width = width;
}
bool Box::getFill() {
	return _fill;
}
void Box::setFill(bool fill) {
	_fill = fill;
}