#include "Transaction.hpp"
#include <string>

int Transaction::nextTransactionID = 0;


/* This constructor is responsible for copying all the values passed through it into private variables belonging to the
 * instance currently being created. */
Transaction::Transaction(Account* fromAccount, Account* toAccount, Money amount) {
	this->fromAccount = fromAccount;
	this->toAccount = toAccount;

	// By default, for a new transaction object, the state should be 'pending'
	state = PENDING;
	if(amount.asCents() < 0)
		amount = Money(0,0);
	transAmount = amount;
	transactionID = nextTransactionID++;
}

/* The 'performTransaction' function performs a transaction. The conditions
 * 	that need to be checked are:
 * 		1. If withdrawal is possible from the 'fromAccount'
 * 		2. If deposit is possible into 'toAccount'
 * 	If both are possible, and the amount has a valid value, the transaction should take place and the transaction state
 * 	 should change to 'COMPLETED' otherwise the state should change to 'FAILED'. */

bool Transaction::performTransaction(){
	bool testWithdrawSuccess = this->fromAccount->withdrawSuccess(transAmount);
	if(testWithdrawSuccess == true)
	{
		bool testDepositSuccess = this->toAccount->depositSuccess(transAmount);
		if(testDepositSuccess == true)
		{
			this->fromAccount->withdrawMoney(transAmount);
			this->toAccount->depositMoney(transAmount);
			state = COMPLETED;
			return true;
		}
	}
	state = FAILED;
	return false;
}

TransactionState Transaction::getState() const {
	return state;
}

Money Transaction::getAmount() const {
	return transAmount;
}

Account* Transaction::getToAccount() const {
	return toAccount;
}

Account* Transaction::getFromAccount() const {
	return fromAccount;
}


int Transaction::getID() const {
	return transactionID;
}

Transaction::~Transaction() {
	// TODO implement
}

