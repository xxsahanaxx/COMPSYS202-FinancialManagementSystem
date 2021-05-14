#include "CreditAccount.hpp"

/* The CreditAccount class is another derived class of Account.
 * 		There are two conditions that need to be satisfied again. Here the balance can drop below 0 dollars.
 * 		However, the balance must not exceed 5000 dollars too. */

CreditAccount::CreditAccount(const int customerID) : Account(customerID) {
	balance = Money(0,0);
}


/* Withdrawal must be possible if the amount passed in for a ChequeAccount withdrawal is non negative. */
bool CreditAccount::withdrawSuccess(Money amount) {
	if(amount.asCents() >= 0)
		return true;
	else
		return false;
}

/* The withdrawMoney function ensures a withdrawal takes place if the amount is a non negative value. */
bool CreditAccount::withdrawMoney(Money amount) {
	if(withdrawSuccess(amount) == true)
	{
		balance.subtractCents(amount.asCents());
		return true;
	}
	return false;
}


/* Depositing money into the account has a restriction for how much can be deposited ie. deposited amount should not be
 * 		greater than 5000 dollars. Also, the amount passed in should have a non negative value. */
bool CreditAccount::depositSuccess(Money amount) {
	if(amount.asCents() >= 0 && (amount.asCents() + balance.asCents() <= 500000))
		return true;
	else
		return false;
}

/* The 'depositMoney' function only gets implemented if the balance after deposit can be below 5000 dollars and if the
 * amount is a valid value. */
bool CreditAccount::depositMoney(Money amount) {
	if(depositSuccess(amount) == true)
	{
		balance.addCents(amount.asCents());
		return true;
	}
	return false;
}

CreditAccount::~CreditAccount() {
	// TODO implement
}
