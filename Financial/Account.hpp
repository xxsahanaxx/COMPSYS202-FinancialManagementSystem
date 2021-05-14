#ifndef ACCOUNT_HPP_
#define ACCOUNT_HPP_

#include "Money.hpp"


/* The ACCOUNT class is abstract because it has one/more purely virtual functions (assigned to zero)
 * which can be overriden by their derived classes. It can hence NOT have any instances of its OWN. */

class Account {
private:
	int custID;
	int accountID;
	static int nextaccID;
	Account& operator=(const Account &other);  // Copy-assignment constructor changes an EXISTING instance
	Account(const Account &other);  // Copy constructor changes the value of the NEW instance

protected:  // These members can be INHERITED but are still hidden from the outside world.
	Money balance;

public:
	Account(const int customerID);
	virtual bool withdrawMoney(Money amount) = 0;
	virtual bool depositMoney(Money amount) = 0;
	virtual bool withdrawSuccess(Money amount) = 0; 	// checks if withdraw can happen
	virtual bool depositSuccess(Money amount) = 0;		// checks if deposit can happen
	int getCustomerID() const;
	int getAccountID() const;
	Money getBalance() const;
	virtual ~Account();
};

#endif /* ACCOUNT_HPP_ */
