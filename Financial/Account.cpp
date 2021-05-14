#include "Account.hpp"

// Static member fields are declared using the scope resolution operator (::) outside the class.
int Account::nextaccID = 0;


/* An Account object cannot exist independently ie. without a Customer object. Therefore, there is
 * an AGGREGATION relationship between the two where the Customer class is the whole and the Account
 * class is a part of that whole. */

/* Constructor of the Account class by default creates a zero balance for the Account. The accountID
 * is a static field whose value is unique for each instance of the class. */
Account::Account(const int customerID) {
	custID = customerID;
	accountID = nextaccID++;
}

int Account::getAccountID() const {
	return accountID;
}

int Account::getCustomerID() const {
	return custID;
}

Money Account::getBalance() const {
	return balance;
}

Account::~Account() {
	// TODO implement
}

