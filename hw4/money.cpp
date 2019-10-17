#include "money.hpp"
#include <iostream>
using std::cout;
using std::endl;

Money::Money() : _value(0) {};
Money::Money(const int dollars, const int cents) :
	_value(dollars*100 + roundCents(cents))
{};
Money::Money(const double dvalue) :
	_value(((int)dvalue) * 100 + (roundCents(dvalue)))
{};


int Money::roundCents(int cents) {
	//TODO
	return 0;
}
int Money::roundCents(double dcents) {
	//TRUNCATES CENTS, BUT  STILL NEEDS ROUNDING
	return ((int)(dcents * 100))%100;
}