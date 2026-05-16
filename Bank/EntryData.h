#pragma once
#include <iostream>
#include <string>
#include "Validation.h"
using namespace std;
class EntryData
{
public:
	// get name from user and validate it using Validation class
	const string getName() const { 
		string name;
		cin >> name;

		while (!Validation::isValidName(name)) {
			cout << "Invalid name. Please enter a valid name (3-20 characters, alphabetic characters and spaces only):\n ";
			cin >> name;
		}	
		return name;
	}

	// get password from user and validate it using Validation class
	const string getPassword() const { 
		
		string password;
		cin >> password;
		while (!Validation::isValidPassword(password)) {
			cout << "Invalid password. Please enter a valid password (8-20 characters, no spaces):\n ";
			cin >> password;
		}
		return password; 
	}
	// get balance from user and validate it using Validation class
	const double getBalance() const {
		double balance;
		cin >> balance;
		while (!Validation::isValidBalance(balance)) {
			cout << "Invalid balance. Please enter a valid balance (at least 1500):\n ";
			cin >> balance;
		}
		return balance; 
	}

	// get salary from user and validate it using Validation class
	const double getSalary() const {

		double salary;
		cin >> salary;
		while (!Validation::isValidSalary(salary)) {
			cout << "Invalid salary. Please enter a valid salary (at least 5000):\n ";
			cin >> salary;
		}
		
		return salary; 
	}

	//get amount from user and validate it using Validation class
	const double getAmount() const {
		
		double amount;
		cin >> amount;
		while (!Validation::isValidAmount(amount)) {
			cout << "Invalid amount. Please enter a valid amount (positive number):\n ";
			cin >> amount;
		}

		return amount; 
	}

};

