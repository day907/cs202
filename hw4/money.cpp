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
	while (abs(cents) >= 100) {
		if (cents % 10 >= 5) {
			cents = (cents / 10) + 1;
		}
		else if (cents % 10 <= -5) {
			cents = (cents / 10) - 1;
		}
		else {
			cents /= 10;
		}
	}
	return cents;
}

int Money::roundCents(double dcents) {
	//if cents round up, returns truncated cents +1.
	//otherwise returns truncated cents
	if ((int)(dcents * 1000) % 10 >= 5) {
		return (((int)(dcents * 100)) % 100) + 1;
	}
	if ((int)(dcents * 1000) % 10 <= -5) {
		return (((int)(dcents * 100) % 100) - 1);
	}
	return ((int)(dcents * 100))%100;
}

void Money::printMoney() {
	cout << _value;
}

int main() {
	Money money1(-45.672);
	money1.printMoney();
	return 0;
}