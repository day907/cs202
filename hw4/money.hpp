//CS202
//Jordan Day
//10/24/19
//Homework 4
//"money.hpp" contains prototypes for the Money class

#ifndef MONEY_HPP
#define MONEY_HPP
#include <iostream>

class Money {
//all other comparison operators rely on these two
friend bool operator==(const Money&, const Money&);
friend bool operator<(const Money&, const Money&);

public:
	Money();
	Money(const int, const int);
	Money(const double);
	double getValue() const;
	void setValue(double);
	Money& operator+=(const Money& rhs);
	Money& operator-=(const Money& rhs);
	Money& operator*=(const double rhs);
	Money& operator/=(const double rhs);
private:
	double roundCents(double);
	int roundCents(int);
	double _value;
};

std::ostream& operator<<(std::ostream&, const Money&);
bool operator!=(const Money&, const Money&);
bool operator<=(const Money&, const Money&);
bool operator>(const Money&, const Money&);
bool operator>=(const Money&, const Money&);
Money operator+(const Money&, const Money&);
Money operator-(const Money&, const Money&);
Money operator*(const double, const Money&);
Money operator*(const Money&, const double);
Money operator/(const Money&, const double);

#endif