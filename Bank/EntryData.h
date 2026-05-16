#pragma once
#include "Validation.h"
class EntryData
{
public:
	// get name from user and validate it using Validation class
	static string getName()  { 
		string name;
		
		cout << "Enter name:\n ";
		cin.ignore();
		getline(cin, name);

		while (!Validation::isValidName(name)) {
			cout << "Invalid name. Please enter a valid name (3-20 characters, alphabetic characters and spaces only):\n ";
			getline(cin, name);
		}	
		return name;
	}

	// get password from user and validate it using Validation class
	static string getPassword()  { 
		
		string password;
		cout << "Enter password:\n ";
		cin >> password;
		while (!Validation::isValidPassword(password)) {
			cout << "Invalid password. Please enter a valid password (8-20 characters, no spaces):\n ";
			cin >> password;
		}
		return password; 
	}
	// get balance from user and validate it using Validation class
	static double getBalance() {
		double balance;
		cout << "Enter balance:\n ";
		cin >> balance;
		while (!Validation::isValidBalance(balance)) {
			cout << "Invalid balance. Please enter a valid balance (at least 1500):\n ";
			cin >> balance;
		}
		return balance; 
	}

	// get salary from user and validate it using Validation class
	static double getSalary() {

		double salary;
		cout << "Enter salary:\n ";
		cin >> salary;
		while (!Validation::isValidSalary(salary)) {
			cout << "Invalid salary. Please enter a valid salary (at least 5000):\n ";
			cin >> salary;
		}
		
		return salary; 
	}

	//get amount from user and validate it using Validation class
	static double getAmount()  {
		
		double amount;
		cout << "Enter amount:\n ";
		cin >> amount;
		while (!Validation::isValidAmount(amount)) {
			cout << "Invalid amount. Please enter a valid amount (positive number):\n ";
			cin >> amount;
		}

		return amount; 
	}

};

