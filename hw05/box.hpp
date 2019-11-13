//CS202
//Jordan Day
//09/26/19
//HW01
//"box.hpp"
//Header file for HW01, contains class Box and derived class declarations

#ifndef BOX_HPP
#define BOX_HPP
#include <iostream>
using std::ostream;
#include <string>
using std::string;
#include <memory>
using std::unique_ptr;

class Box {
public:
	Box();
	Box(const int&, const int&);
	Box(const Box&);
	virtual ~Box();
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

//Derived classes
class FilledBox : public Box {
public:
	using Box::Box;
	~FilledBox();
	string type() const override;
	void print(ostream&) const override;
};

class HollowBox : public Box {
public:
	using Box::Box;
	~HollowBox();
	string type() const override;
	void print(ostream&) const override;
};

class CheckeredBox : public Box {
public:
	using Box::Box;
	~CheckeredBox();
	string type() const override;
	void print(ostream&) const override;
};


unique_ptr<Box> boxFactory(char c, int w, int h);
ostream& operator<<(ostream&, const Box&);

#endif