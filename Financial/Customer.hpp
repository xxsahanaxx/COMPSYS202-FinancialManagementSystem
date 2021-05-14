#include <string>
#ifndef CUSTOMER_HPP_
#define CUSTOMER_HPP_


/* The Customer objects are allowed to possess Accounts of different kinds. In this project, there
 * are three: SAVINGS, CHEQUE, CREDIT. Each of them perform a specific function and a customer
 * instance can have an account of each kind. */

class Customer {
private:
	std::string custName;
	int uID;
	static int nextID;
	Customer& operator=(const Customer &other);
    Customer(const Customer &other);

public:
	Customer(const std::string &name);
	std::string getName() const;
	int getID() const;
	virtual ~Customer();
};

#endif /* CUSTOMER_HPP_ */
