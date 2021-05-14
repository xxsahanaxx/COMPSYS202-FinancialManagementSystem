#ifndef TRANSACTION_HPP_
#define TRANSACTION_HPP_

#include <string>
#include "Account.hpp"
#include "Money.hpp"


/* An ENUMERATION data type is created that stores three states as follows. Any transaction being created by default
 * gets initialised to PENDING unless it is performed upon. */

enum TransactionState {
	COMPLETED,
	PENDING,
	FAILED
};


class Transaction {
private:
	int transactionID;
	Account *fromAccount;	// pointer pointing to the fromAccount
	Account *toAccount;		// pointer pointing to the toAccount
	Money transAmount;		// amount being transferred between the accounts
	static int nextTransactionID;
	Transaction& operator=(const Transaction &other);
    Transaction(const Transaction &other);
protected:
    TransactionState state;	// state of current transaction
public:
	Transaction(Account* fromAccount, Account* toAccount, Money amount);
	bool performTransaction();
	TransactionState getState() const;
	Money getAmount() const;
	Account* getFromAccount() const;
	Account* getToAccount() const;
	int getID() const;
	virtual ~Transaction();
};

#endif /* TRANSACTION_HPP_ */
