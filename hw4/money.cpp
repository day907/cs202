#include "money.hpp"
#include <iostream>
using std::ostream;
using std::cout;
using std::endl;
#include <iomanip>
using std::setprecision;
using std::fixed;

Money::Money() : _value(0) {};
Money::Money(const int dollars, const int cents) :
	_value(dollars + ((double)roundCents(cents))/100)
{};
Money::Money(const double dvalue) :
	_value(roundCents(dvalue))
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

double Money::roundCents(double dvalue) {
	int roundVal = ((int)(dvalue * 1000)) % 10;
	if (roundVal >= 5) {
		dvalue = ((int)(dvalue * 100)) / 100.0 + 0.01;
	}
	else if (roundVal <= -5) {
		dvalue = ((int)(dvalue * 100)) / 100.0 - 0.01;
	}
	return dvalue;
}

double Money::getValue() const {
	return _value;
}
void Money::setValue(double value) {
	_value = value;
	return;
}

bool operator==(const Money& mon1, const Money& mon2) {
	return (mon1._value == mon2._value);
}
bool operator!=(const Money& mon1, const Money& mon2) {
	return (!(mon1 == mon2));
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

int main() {
	//Money money1(-2, -2456);
	//while (money1.getValue() <= 2) {
	//	money1.setValue(money1.getValue() + 0.01);
	//	cout << money1 << endl;
	//}
	double counter = -2.00;
	while(counter < 2.00) {
		Money money(counter);
		cout << setprecision(3) << "Counter: " << counter
			<< " | Money: " << money
			<< " | _value: " << money.getValue() << endl;
		counter += 0.008;
	}
	return 0;
}