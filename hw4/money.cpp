#include "money.hpp"
#include <iostream>
using std::ostream;
using std::cout;
using std::endl;


Money::Money() : _value(0) {};
Money::Money(const int dollars, const int cents) :
	_value(dollars*100 + roundCents(cents))
{};
Money::Money(const double dvalue) :
	_value(((int)dvalue) * 100 + (roundCents(dvalue)))
{};

//Tried to make the rounding functions for construction
//pretty robust to make dealing with Money objects
//after construction easier.
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
int Money::getValue() const {
	return _value;
}

bool operator==(const Money& mon1, const Money& mon2) {
	return (mon1._value == mon2._value);
}
bool operator!=(const Money& mon1, const Money& mon2) {
	return (!(mon1 == mon2));
}
ostream& operator<<(ostream& ost, const Money& mon) {
	ost << '$' << (mon.getValue()) / 100 << '.' << abs(mon.getValue() % 100);
	return ost;
}

int main() {
	Money money1(45.678);
	cout << money1;
	return 0;
}