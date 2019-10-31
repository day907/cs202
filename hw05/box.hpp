
//CS202
//Jordan Day
//09/26/19
//HW01
//"box.hpp"
//Header file for HW01, contains class Box declarations

#ifndef BOX_HPP
#define BOX_HPP
#include <iostream>
using std::ostream;
#include <string>
using std::string;

//To add or remove a layout type to enum layout,
//modifications are needed in Box::type(),
//and Box::print(). If removing FILLED layout,
//modifications needed in Box() default constructor,
//and Box(const int&, const int&) constructor.
class Box {
public:
	enum layout { FILLED, HOLLOW, CHECKERED };
	Box();
	Box(const int&, const int&);
	Box(const int&, const int&, const layout&);
	Box(const Box&);
	~Box();
	void print(ostream&) const;
	string type() const;
	int getHeight() const;
	void setHeight(int);
	int getWidth() const;
	void setWidth(int);
	static int howMany();
private:
	int _height;
	int _width;
	layout _layout;
	static int _currentboxes;
};

ostream& operator<<(ostream&, const Box&);

#endif