#include "Money.hpp"

// The default constructor of the MONEY class automatically initialises 'totalCents' to zero.
Money::Money() : totalCents(0) {
}

/* The parametrised constructor takes in two inputs, 'dollars' and 'cents', and converts them into a
 * uniform measure -> cents stored in 'totalCents'. */
Money::Money(int dollars, int cents)
{
	this->totalCents = dollars*100 + cents;
}

int Money::getDollars() const
{
	return totalCents/100;
}

int Money::getCents() const
{
	return totalCents%100;
}

int Money::asCents() const
{
	return totalCents;
}

void Money::addDollars(int dollars)
{
	if (dollars > 0)
	{
		this->totalCents += dollars*100;
	}
}

void Money::addCents(int cents)
{
	if (cents > 0)
	{
		this->totalCents += cents;
	}
}

void Money::subtractDollars(int dollars)
{
	if (dollars > 0)
	{
		this->totalCents -= dollars*100;
	}
}

void Money::subtractCents(int cents)
{
	if (cents > 0)
	{
		this->totalCents -= cents;
	}
}



/* The purpose of these functions is to take another instance of the class as an input to modify the
 * instance being acted upon. */

void Money::add(const Money &other)
{
	if(other.totalCents > 0)
	{
		this->totalCents += other.totalCents;
	}
}

void Money::subtract(const Money &other)
{
	if(other.totalCents > 0)
	{
		this->totalCents -= other.totalCents;
	}
}

void Money::split(Money &other)
{
	int newTotal = (this->totalCents + other.totalCents)/2;
	this->totalCents = newTotal;
	other.totalCents = newTotal;
}

Money::~Money() {
}
