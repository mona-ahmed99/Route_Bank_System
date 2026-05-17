#pragma once
#include "Person.h"
class Client :
	public Person
{
private:
	double balance;
public:
	Client() {
		balance = 1500;
	}
	void setBalance(double balance) {
		if (Validation::isValidBalance(balance)) {
			this->balance = balance;
		}
		else {
			cout << "Invalid balance. Minimum balance is 1500" << endl;
		}
	}
	double getBalance() {
		return balance;
	}
	void deposit(double amount) {
		if (amount > 0) {
			balance += amount;
			cout << "Deposite Done Succesfully" << endl;
		}
		else {
			cout << "Invalid amount" << endl;

		}
	}
	void withdraw(double amount) {
		if (amount > 0 && balance - amount >= 1500) {
			balance -= amount;
			cout << "Withdraw Done Succesfully" << endl;
		}
		else {
			cout << "Invalid Withdraw Amount. Minimum Balance Must Remain 1500" << endl;
		}
	}
	void transferTo(double amount, Client& recipient) {
		if (amount > 0 && balance - amount >= 1500) {
			balance -= amount;
			recipient.deposit(amount);
			cout << "Transfer Done Successfully." << endl;
		}
		else {
			cout << "Transfer failed. Minimum Balance Must Remain 1500." << endl;
		}
	}
	void checkBalance() {
		cout << "Current Balance: " << balance << endl;
	}
	void Display() {
		cout << "ID: " << id << endl;
		cout << "Name: " << name << endl;
		cout << "Password: " << password << endl;
		cout << "Balance: " << balance << endl;
	}
};

