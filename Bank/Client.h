#pragma once
#include "Person.h"
class Client :
	public Person
{
private:
	double balance;
public:
	Client(): Person(), balance(1500) {}
	Client(int id, string name, string password, double balance) : Person(name, id, password), balance(balance) {}
	//setters balance
	void setBalance(double balance) {
		this->balance = balance;
	}
	//gettters balance
	double getBalance() {
		return balance;
	}
	//deposit
	void deposit(double amount) {
			balance += amount;
			cout << "Deposite Done Succesfully" << endl;
	}

	//withdraw
	void withdraw(double amount) {
			balance -= amount;
			cout << "Withdraw Done Succesfully" << endl;
	}
	//transfer
	void transferTo(double amount, Client& recipient) {
			balance -= amount;
			recipient.deposit(amount);
			cout << "Transfer Done Successfully." << endl;
	}
	//check balance
	void checkBalance() {
		cout << "Current Balance: " << balance << endl;
	}
	//display client info
	void Display() {
		cout << "Client Information:" << endl;
		Person::Display();
		cout << "Balance: " << balance << endl;
	}
};

