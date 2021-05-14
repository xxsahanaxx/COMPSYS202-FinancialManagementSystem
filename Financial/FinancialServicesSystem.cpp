#include "FinancialServicesSystem.hpp"
#include <iostream>
#include <vector>


FinancialServicesSystem::FinancialServicesSystem() {
	// TODO implement
}

std::string FinancialServicesSystem::author(){
	return "ssri365";
}

/* The 'addCustomer' function adds a customer by customerID to the list of existing customers in a
 * 		private variable of the class called 'customerList'.
 * If a duplicate is created, a customer should not added to the list. */
bool FinancialServicesSystem::addCustomer(Customer* customer) {

	/* In the beginning, when the customerList is empty, this part of the code won't be
	 * 	executed. */
	for(int i = 0; i < customerList.size(); i++)
	{
		// Test if a duplicate exists
		if(customerList[i]->getID() == customer->getID())
			return false;
	}
	customerList.push_back(customer);
	return true;
}


bool FinancialServicesSystem::addAccount(Account* account) {

	/* Test if a customer exists first with the customerID of the 'account' variable, since only
	 * then an account can be created for that customerID. */
	bool verifyCond = verifyCustomer(account->getCustomerID());
	if(verifyCond == true)
	{
		int i;

		// Test for checking a duplicate of an account being created
		for(i = 0; i < accountList.size(); i++)
		{
			if(accountList[i]->getAccountID() == account->getAccountID())
				return false;
		}
		accountList.push_back(account);
		return true;
	}
	return false;
}


/* This function checks if a Transaction instance that is created can be added into a vector of
 * 		type 'Transaction'. */
 bool FinancialServicesSystem::addTransaction(Transaction* transaction) {
	// Test to check if both fromAccount and toAccount exist first.
	bool fromAccVerify = verifyAccount(transaction->getFromAccount()->getAccountID());
	bool toAccVerify = verifyAccount(transaction->getToAccount()->getAccountID());

	// If both accounts exist, the transaction is VALID and can be added to the list.
	if(fromAccVerify == true && toAccVerify == true)
	{
		int flag = 0, i;
		for(i = 0; i < transactionList.size(); i++)
		{
			// Test to check duplicate, in which case insertion must not happen
			if(transactionList[i] == transaction)
				flag = 1;
		}
		if(flag == 0)
		{
			transactionList.push_back(transaction);
			return true;
		}
	}
	return false;
}



/* This function is a helper function that gets passed into the 'std::sort' function as
 * one of the parameters. This ensures that sorting happens based on the transactionID. */

bool sortingWithID(const Transaction* lhs, const Transaction* rhs)
{
	return (lhs->Transaction::getID() < rhs->Transaction::getID());
}


/* 'PerformPendingTransactions' is a function that acts on transactions whose state is 'PENDING'. Here the transactions
 * 	should be sorted by transactionID and then once state is 'COMPLETED', they must be entered into a vector of type
 * 	Transaction. */

std::vector<Transaction*> FinancialServicesSystem::performPendingTransactions() {

	// Creating a temporary list that stores an unsorted array of pending transactions.
	std::vector<Transaction*> temp = getTransactions(PENDING);

	// Variable declared as a resultant sorted array.
	std::vector<Transaction*> resultVector;

	/* The std::sort function takes in two or three parameters, the first being a pointer pointing
	 * 		to the first element of the list, the second pointing to the end of the list and the
	 * 		third that determines on what basis the list is sorted. */
	std::sort(temp.begin(), temp.end(), sortingWithID);

	// If the transaction is successfully performed, the transaction is added to the resultant list.
	for(int i = 0; i < temp.size(); i++)
	{
		bool success = temp[i]->performTransaction();
		if(success == true)
		{
			resultVector.push_back(temp[i]);
		}
	}

	// Returning the sorted array
	return resultVector;
}



/* This function adds all the balances linked with the customerID together and returns the summed
 * 		balances at the end of the function. */

Money FinancialServicesSystem::getCustomerBalance(int customerID) const {
	int i;
	// CashUp is a temporary variable that stores the balances from each account as an integer
	int cashUp = 0;
	std::vector<Account*> getAccountList = getAccounts();
	for(i = 0; i < getAccountList.size(); i++)
	{
		/* If the customerID of any account matches with that of the parameter passed, considering no duplication occurs,
		 * the balance of the existing account must be summed with the amount in cashUp already. */
		if(getAccountList[i]->getCustomerID() == customerID)
			cashUp = cashUp + getAccountList[i]->getBalance().asCents();
	}

	/* Now cashUp has the summed balances but stored in cents. The function returns a Money object though. So cashUp must
	 * be converted to dollars and cents and passed as parameters through a Money constructor that creates a Money
	 * instance. */
	Money tempObj(cashUp / 100, cashUp % 100);
	return tempObj;
}


/* The 'verifyCustomer' function checks if a customer already exists in the database and returns true
 * 		if a customerID with the same one as passed through is present. */
bool FinancialServicesSystem::verifyCustomer(int customerID) const {
	int i;
	std::vector<Customer*> resultCustList = getCustomers();
	for(i = 0; i < resultCustList.size(); i++)
	{
		if(resultCustList[i]->getID() == customerID)
			return true;
	}
	return false;
}

// Test for an account existing with the 'accountID' passed through
bool FinancialServicesSystem::verifyAccount(int accountID) const {
	int i;
	std::vector<Account*> resultAccList = getAccounts();
	for(i = 0; i < resultAccList.size(); i++)
	{
		if(resultAccList[i]->getAccountID() == accountID)
			return true;
	}
	return false;
}

// Test to verify if a transaction exists with the same 'transactionID' that is passed through.
bool FinancialServicesSystem::verifyTransaction(int transactionID) const {
	int i;
	std::vector<Transaction*> resultTransList = getTransactions();
	for(i = 0; i < resultTransList.size(); i++)
	{
		if(resultTransList[i]->getID() == transactionID)
			return true;
	}
	return false;
}

std::vector<Account*> FinancialServicesSystem::getAccounts() const {
	return accountList;
}

std::vector<Customer*> FinancialServicesSystem::getCustomers() const {
	return customerList;
}

std::vector<Transaction*> FinancialServicesSystem::getTransactions() const {
	return transactionList;
}

/* This function returns a list of transactions whose state matches the state that is passed through as a parameter. */
std::vector<Transaction*> FinancialServicesSystem::getTransactions(TransactionState state) const {
	int i;
	std::vector<Transaction*> resultTransList = getTransactions();

	// A new array holding the particular 'state' being concerned is created
	std::vector<Transaction*> newTransList;
	for(i = 0; i < resultTransList.size(); i++)
	{
		if(resultTransList[i]->getState() == state)
			newTransList.push_back(resultTransList[i]);
	}
	return newTransList;
}

FinancialServicesSystem::~FinancialServicesSystem() {
	// TODO implement
}

