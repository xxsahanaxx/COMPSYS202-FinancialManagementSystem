#include "Account.hpp"

#ifndef SAVINGSACCOUNT_HPP_
#define SAVINGSACCOUNT_HPP_



/* The class SavingsAccount is a derived class of Account. It inherits the features of the Account
 * class however, through public inheritance which means the derived class has access to both the
 * protected and public members and methods of the Account class. */


class SavingsAccount : public Account {
	Money bonus;
	int countDeposits;
private:
	SavingsAccount& operator=(const SavingsAccount &other);
    SavingsAccount(const SavingsAccount &other);
public:
	SavingsAccount(const int customerID);
	bool withdrawSuccess(Money amount);
	bool depositSuccess(Money amount);
	bool withdrawMoney(Money amount);
	bool depositMoney(Money amount);
	Money getBonusValue() const;
	virtual ~SavingsAccount();
};

#endif /* SAVINGSACCOUNT_HPP_ */
