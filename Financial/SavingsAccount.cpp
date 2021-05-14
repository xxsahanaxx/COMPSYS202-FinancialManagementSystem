#include "SavingsAccount.hpp"


/* The constructor for the SavingsAccount is a parametrised one, that takes in the customerID of an
 * existing customer and creates an account that links with that particular customer. This further
 * stresses on the foundation that an account CANNOT exist without a customer in the database. There
 * is a dependency involved. */

SavingsAccount::SavingsAccount(const int customerID) : Account(customerID) {
	bonus = Money(10,0);
	balance = Money(0,0);
	if(bonus.asCents() <= 0)
	{
		bonus = Money(0,0);
	}
	countDeposits = 0;
}

/* This function is a helper function that lets the user know if a withdrawal can be made. It checks two conditions:
 *  	1. whether the input is non-negative
 * 		2. whether the balance after the withdrawal is made is non-negative.
 * 	It returns true if both conditions are met, and false if one or both of them fail. */
bool SavingsAccount::withdrawSuccess(Money amount) {
	if(amount.asCents() >= 0 && amount.asCents() <= balance.asCents())
		return true;
	else
		return false;
}

// The 'withdrawMoney' function takes in a Money input and makes a withdrawal in the SavingsAccount.
bool SavingsAccount::withdrawMoney(Money amount) {
	if(withdrawSuccess(amount) == true)
	{
		balance.subtractCents(amount.asCents());

		// If a withdrawal is made, the SavingsAccount created loses its 'bonus' value.
		if(bonus.getDollars() >= 2)
			bonus.subtractDollars(2);
		else
			bonus.subtractCents(bonus.asCents());
			/* This statement ensures that if the 'bonus' value drops below 2 dollars, it will be
			 * 	cleared to zero. */
		return true;
	}
	else
		return false;
}


/* This helper function tests if a deposit can be made, which is possible if the amount entered is non negative.
 * It returns true or false depending on if the condition is satisfied. */
bool SavingsAccount::depositSuccess(Money amount) {
	if(amount.asCents() >= 0)
		return true;
	else
		return false;
}


/* The 'depositMoney' function deposits the amount passed through it into the account it is called by.
 * 		An important aspect to consider here is the increment in the 'bonus' value, that is added to the
 * 	existing balance after every SECOND deposit. */
bool SavingsAccount::depositMoney(Money amount) {
	if(depositSuccess(amount) == true)
	{
		balance.addCents(amount.asCents());
		countDeposits++;

		/* This counter keeps track of the number of deposits made in a SavingsAccount by a customer.
		 * If the number of countDeposits is an even number, then the 'bonus' must be added to the
		 * existing balance. */
		if(countDeposits % 2 == 0)
			balance.addCents(bonus.asCents());
		return true;
	}
	else
		return false;
}

Money SavingsAccount::getBonusValue() const {
	return bonus;
}

SavingsAccount::~SavingsAccount() {
	// TODO implement
}


