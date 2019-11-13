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
#include <memory>
using std::unique_ptr;

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
public:
	using Box::Box;
	//FilledBox();
	//FilledBox(const int&, const int&);
	string type() const override;
	void print(ostream&) const override;
};

class HollowBox : public Box {
public:
	using Box::Box;
	//HollowBox();
	//HollowBox(const int&, const int&);
	string type() const override;
	void print(ostream&) const override;
};

class CheckeredBox : public Box {
public:
	using Box::Box;
	//CheckeredBox();
	//CheckeredBox(const int&, const int&);
	string type() const override;
	void print(ostream&) const override;
};

unique_ptr<Box> boxFactory(char c, int w, int h);

ostream& operator<<(ostream&, const Box&);

#endif