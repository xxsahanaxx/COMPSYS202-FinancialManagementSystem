#include "Customer.hpp"
#include <string>

// Static member field initialisation
int Customer::nextID = 0;

Customer::Customer(const std::string &name) {
	custName = name;
	uID = nextID++;
}

std::string Customer::getName() const {
	return custName;
}

int Customer::getID() const {
	return uID;
}

Customer::~Customer() {
	// TODO implement
}

