#ifndef FINANCIALSERVICESSYSTEM_HPP_
#define FINANCIALSERVICESSYSTEM_HPP_


#include "Customer.hpp"
#include "Account.hpp"
#include "Transaction.hpp"
#include "Money.hpp"
#include <vector>
#include <iostream>

/* There is a composition relationship where FinancialServicesSystem comprises of
 * 		Customers AND Accounts.
 * 	Accounts are aggregated to Customers.
 *
 * When 'vector's are returned, it is a 'list' stored of the type of vector declared. When 'const' is written at
 * 		the end of the function declaration, the returned vector is a constant type vector that cannot be modified. */

class FinancialServicesSystem {
private:
	std::vector<Customer*> customerList;
	std::vector<Account*> accountList;
	std::vector<Transaction*> transactionList;
public:
	FinancialServicesSystem();
	static std::string author();
	bool addCustomer(Customer* customer);
	bool addAccount(Account* account);
	bool addTransaction(Transaction* transaction);

	std::vector<Transaction*> performPendingTransactions();
	Money getCustomerBalance(int customerID) const;

	bool verifyCustomer(int customerID) const;
	bool verifyAccount(int accountID) const;
	bool verifyTransaction(int transactionID) const;

	std::vector<Account*> getAccounts() const;
	std::vector<Customer*> getCustomers() const;
	std::vector<Transaction*> getTransactions() const;
	std::vector<Transaction*> getTransactions(TransactionState state) const;

	virtual ~FinancialServicesSystem();
};

#endif /* FINANCIALSERVICESSYSTEM_HPP_ */
