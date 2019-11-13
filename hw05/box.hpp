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

class Box {
public:
	Box();
	Box(const int&, const int&);
	Box(const Box&);
	~Box();
	int getHeight() const;
	void setHeight(int);
	int getWidth() const;
	void setWidth(int);
	static int howMany();
	virtual void print(ostream&) const = 0;
	virtual string type() const = 0;
private:
	int _height;
	int _width;
	static int _currentboxes;
};

class FilledBox : public Box {
	FilledBox();
	FilledBox(const int&, const int&);
};

class HollowBox : public Box {
	HollowBox();
	HollowBox(const int&, const int&);
};

class CheckeredBox : public Box {
	CheckeredBox();
	CheckeredBox(const int&, const int&);
};

ostream& operator<<(ostream&, const Box&);

#endif