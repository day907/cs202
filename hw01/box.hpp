#ifndef BOX_HPP
#define BOX_HPP

class Box {
public:
	Box();
	Box(const int&, const int&);
	Box(const int&, const int&, const bool&);
	int const getHeight();
	void setHeight(int&);
	int const getWidth();
	void setWidth(int&);
	bool const getFill();
	void setFill(bool&);
private:
	int _height;
	int _width;
	bool _fill;
};

#endif