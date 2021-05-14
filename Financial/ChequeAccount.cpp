#include "ChequeAccount.hpp"


/* The ChequeAccount class is a derived class of Account. This class has a 'transaction fee' variable that deducts some
 * money for each withdrawal that is being made. Also, the balance of a ChequeAccount cannot drop below 0 dollars. */

ChequeAccount::ChequeAccount(const int customerID) : Account(customerID) {
	// Initial transaction fee must be 1 dollar
	transFee = Money(1,0);
	balance = Money(0,0);

	/* A pointer 'transPoint' is created to point to the transaction fee variable, which is then used at a later point in
	 * the return statement. */
	transPoint = &transFee;
}


/* The 'withdrawSuccess' function is a helper function that tests to see if a withdrawal can be made. For this:
 *	 	1. the amount must be non negative.
 * 		2. a transaction fee must be added.
 * 		3. the balance must be sufficient to allow transaction to occur.
 * 		4. the balance after withdrawal must be non negative.
 * 	If everything works, the function returns true else false is returned. */
bool ChequeAccount::withdrawSuccess(Money amount) {
	if((amount.asCents() >= 0 && balance.getDollars() >= 0) && (amount.asCents() + transFee.asCents()) <= balance.asCents())
		return true;
	else
		return false;
}

bool ChequeAccount::withdrawMoney(Money amount) {
	if(withdrawSuccess(amount) == true)
	{
		/* Deduct the amount as well as the transaction fee from the balance and then increment the transaction fee by
		 * a dollar. */
		balance.subtractCents(amount.asCents()+transFee.asCents());
		transFee.addDollars(1);
		return true;
	}
	return false;
}


/* This helper function checks the condition to deposit into a ChequeAccount. If:
 * 		1. amount is non negative
 * 		2. deposit amount should be less than 3000 dollars. */
bool ChequeAccount::depositSuccess(Money amount) {
	if(amount.asCents() >= 0 && amount.asCents() <= 300000)
		return true;
	else
		return false;
}

/* The 'depositMoney' function deposits money into the balance of the account. */
bool ChequeAccount::depositMoney(Money amount) {
	if(depositSuccess(amount) == true)
	{
		balance.addCents(amount.asCents());
		return true;
	}
	return false;
}


// This function returns a pointer 'transPoint' that points to the variable transFee.
Money* ChequeAccount::getTransactionFee() const {
	return transPoint;
}

ChequeAccount::~ChequeAccount() {
	// TODO implement
}

