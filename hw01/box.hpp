#ifndef BOX_HPP
#define BOX_HPP

class Box {
public:
	Box();
	Box(const int&, const int&);
	Box(const int&, const int&, const bool&);

//	void print(ostringstream & os);
	int getHeight() const;
	void setHeight(int);
	int getWidth() const;
	void setWidth(int);

private:
	int _height;
	int _width;
	bool _fill;
};

#endif