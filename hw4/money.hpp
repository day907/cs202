#ifndef MONEY_HPP
#define MONEY_HPP
#include <iostream>

class Money {
friend bool operator==(const Money&, const Money&);
public:
	Money();
	Money(const int, const int);
	Money(const double);
	double getValue() const;
	void setValue(double);
private:
	double roundCents(double);
	int roundCents(int);
	double _value;
};
std::ostream& operator<<(std::ostream&, const Money&);
bool operator!=(const Money&, const Money&);
#endif