#ifndef MONEY_HPP
#define MONEY_HPP
#include <iostream>

class Money {
friend bool operator==(const Money&, const Money&);
public:
	Money();
	Money(const int, const int);
	Money(const double);
	int getValue() const;
private:
	int roundCents(double);
	int roundCents(int);
	int _value;
};
std::ostream& operator<<(std::ostream&, const Money&);
bool operator!=(const Money&, const Money&);
#endif