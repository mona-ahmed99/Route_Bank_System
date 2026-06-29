#pragma once

#include "Person.h"
#include "Validation.h"
#include <vector>

using namespace std;

class Client : public Person
{
private:
	double balance;

public:
	static vector<Client> clients;

	Client() : Person(), balance(1500) {}

	Client(int id, string name, string password, double balance)
		: Person(name, id, password), balance(balance) {
	}

	void setBalance(double balance) {
		if (Validation::isValidBalance(balance)) {
			this->balance = balance;
		}
		else {
			this->balance = 0;
		}
	}
	double getBalance() {
		return balance;
	}
	void deposit(double amount) {
		if (Validation::isValidAmount(amount)) {
			balance += amount;
			cout << "Deposit Done Successfully" << endl;
		}
		else {
			cout << "Invalid deposit amount." << endl;
		}
	}
	void withdraw(double amount) {
		if (Validation::isValidAmount(amount) &&
			Validation::canWithdraw(amount, balance)) {
			balance -= amount;
			cout << "Withdraw Done Successfully" << endl;
		}
		else {
			cout << "Invalid withdraw amount." << endl;
		}
	}
	void transferTo(double amount, Client& recipient) {
		if (Validation::isValidAmount(amount) &&
			Validation::canWithdraw(amount, balance)) {
			balance -= amount;
			recipient.deposit(amount);
			cout << "Transfer Done Successfully." << endl;
		}
		else {
			cout << "Invalid transfer amount." << endl;
		}
	}
	void checkBalance() {
		cout << "Current Balance: " << balance << endl;
	}
	void Display() const {
		cout << "Client Information:" << endl;
		Person::Display();
		cout << "Balance: " << balance << endl;
	}
};