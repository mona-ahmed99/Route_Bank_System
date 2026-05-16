#pragma once
#include <iostream>
#include <string>
#include <cctype>
using namespace std;
class Validation
{
public:
	// Check if the name is between 3 and 20 characters and contains only alphabetic characters and spaces
	static bool isValidName(const string& name) {
		// Check if the name length is between 3 and 20 characters
		if (name.length() < 3 || name.length() > 20) {
			return false;
		}
		//check if the name contains only alphabetic characters and spaces
		for (int i = 0; i < name.length(); i++) {
			if (!isalpha(name[i]) && name[i] != ' ') {
				return false;
			}
		}
		return true;
	}

	// Check if the password is at least 8 characters and at most 20 characters without spaces
	static bool isValidPassword(const string& password) {
		// Check if the password length is between 8 and 20 characters
		if (password.length() < 8 || password.length() > 20) {
			return false;
		}
		//check if the password contains spaces
		for (int i = 0; i < password.length(); i++) {
			if (password[i] == ' ') {
				return false;
			}
		}
		return true;
	}

	// Check if the balance is at least 1500
	static bool isValidBalance(const double& balance) {
		if (balance < 1500) {
			return false;
		}
		return true;
	}

	// Check if the salary is at least 5000
	static bool isValidSalary(const double& salary) {
		if (salary < 5000) {
			return false;
		}
		return true;
	}

	//check if the amount is positive
	static bool isValidAmount(const double& amount) {
		if (amount <= 0) {
			return false;
		}
		return true;
	}
};


