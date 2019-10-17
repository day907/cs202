#ifndef MONEY_HPP
#define MONEY_HPP

class Money {
public:
	Money();
	Money(const int, const int);
	Money(const double);
private:
	int roundCents(double);
	int roundCents(int);
	int _value;
};

#endif