//CS202
//Jordan Day
//10/24/19
//Homework 4
//"money.cpp" contains definitions for the Money class


#include "money.hpp"
#include <iostream>
using std::ostream;
using std::cout;
using std::endl;
#include <iomanip>
using std::setprecision;
using std::fixed;

//Money constructors
//Default constructor sets _value to zero
Money::Money() : _value(0) {};

//Rounds the cents parameter to a two digit number, casts it to a double, and
//adds it to the dollars.
//e.g. 10, 157 would assign 10.16
Money::Money(const int dollars, const int cents) :
	_value(dollars + ((double)roundCents(cents))/100)
{};

//Rounds the double to nearest hundredths and initializes it to _value
Money::Money(const double dvalue) :
	_value(roundCents(dvalue))
{};

//Tried to make the rounding functions for construction
//pretty robust to make dealing with Money objects
//after construction easier.
//
//Rounds the cents integer used in two int argument constructor
int Money::roundCents(int cents) {

	//Procedurally rounds up each digit until it reaches a 2 digit number
	//could cause a problem with something like cents = 10489 rounding to
	//11 cents instead of 10.
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

//Rounds double argument constructor to nearest hundredths
//All the int casting seemed like the easiest way to truncate?
double Money::roundCents(double dvalue) {
	//Extracts thousandths place, maintains sign bit
	int roundVal = ((int)(dvalue * 1000)) % 10;

	//Checks if the cents round, and if they round positively or negatively
	if (roundVal >= 5) {
		dvalue = ((int)(dvalue * 100)) / 100.0 + 0.01;
	}
	else if (roundVal <= -5) {
		dvalue = ((int)(dvalue * 100)) / 100.0 - 0.01;
	}
	return dvalue;
}

//Get/set value functions
double Money::getValue() const {
	return _value;
}
void Money::setValue(double value) {
	_value = value;
	return;
}

//Operator overloads
//Boolean operators
//== and > are friend functions, the rest are reliant
//on using == and <
bool operator==(const Money& mon1, const Money& mon2) {
	return (mon1._value == mon2._value);
}
bool operator!=(const Money& mon1, const Money& mon2) {
	return (!(mon1 == mon2));
}
bool operator<(const Money& mon1, const Money& mon2) {
	return (mon1._value < mon2._value);
}
bool operator<=(const Money& mon1, const Money& mon2) {
	return (mon1 < mon2 || mon1 == mon2);
}
bool operator>(const Money& mon1, const Money& mon2) {
	return !(mon1 <= mon2);
}
bool operator>=(const Money& mon1, const Money& mon2) {
	return (!(mon1 < mon2) || mon1 == mon2);
}

//Arithmetic operators
//Add Money to an existing Money object (+=)
	//canonical
Money& Money::operator+=(const Money& rhs) {
	return *this = *this + rhs;
}

//Subtract Money from an existing Money object (-=)
	//canonical
Money& Money::operator-=(const Money& rhs) {
	return *this = *this - rhs;
}

//Add two Money objects
Money operator+(const Money& mon1, const Money& mon2) {
	Money newMon(mon1.getValue() + mon2.getValue());
	return newMon;
}

//Subtract two Money objects
Money operator-(const Money& mon1, const Money& mon2) {
	Money newMon(mon1.getValue() - mon2.getValue());
	return newMon;
}

//Multiply a double times a Money object
Money operator*(const double mon1, const Money& mon2) {
	Money newMon(mon1 * mon2.getValue());
	return newMon;
}

//Multiply a Money object times a double(*)
Money operator*(const Money& mon1, const double mon2) {
	//Creating a new Money object ensures the quotient rounds
	Money newMon(mon1.getValue() * mon2);
	return newMon;
}

//Multiply a Money object times a double (*=)
	//canonical
Money& Money::operator*=(const double rhs) {
	return *this = *this * rhs;
}

//Divide a Money object by a double (/)
Money operator/(const Money& mon1, const double mon2) {
	//Creating a new Money object ensures the quotient rounds
	Money newMon(mon1.getValue() / mon2);
	return newMon;
}

//Divide a Money object by a double (/=)
	//canonical
Money& Money::operator/=(const double rhs) {
	return *this = *this / rhs;
}

//Formats Money _value into appropriate form and inserts to ostream
//This works, but I'm not sure how using iomanip will affect test functions.
//may need to change later
ostream& operator<<(ostream& ost, const Money& mon) {
	ost << fixed << setprecision(2);
	if (mon.getValue() >= 0) {
		ost << '$' << mon.getValue();
	}
	else {
		ost << "-$" << abs(mon.getValue());
	}
	return ost;
}