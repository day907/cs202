#ifndef BOX_HPP
#define BOX_HPP

class Box {
public:
	int getHeight();
	void setHeight(int);
	int getWidth();
	void setWidth(int);
	bool getFill();
	void setFill(bool);
private:
	int _height;
	int _width;
	bool _fill;
};

#endif