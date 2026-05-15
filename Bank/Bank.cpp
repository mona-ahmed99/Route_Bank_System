
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
	static bool isValidBalance(double balance) {
		if (balance < 1500) {
			return false;
		}
		return true;
	}

	// Check if the salary is at least 5000
	static bool isValidSalary(double salary) {
		if (salary < 5000) {
			return false;
		}
		return true;
	}


};
class person {
protected:
    string name;
    int id;
    string password;

public:
    person() {
        name = "admin";
        id = 0;
        password = "12345678";
    }

    person(string name, int id, string password) {
        this->id = id;
        setname(name);
        setpassword(password);
    }

    void setname(string name) {
        if (Validation::isValidName(name)) {
            this->name = name;
        }
        else {
            cout << "Invalid Name" << endl;
        }
    }

    void setid(int id) {
        this->id = id;
    }

    void setpassword(string password) {
        if (Validation::isValidPassword(password)) {
            this->password = password;
        }
        else {
            cout << "Invalid password" << endl;
        }
    }

    string getname() {
        return name;
    }

    int getid() {
        return id;
    }

    string getpassword() {
        return password;
    }
};
class client :public person {
private:
	double balance;
public:
	client() {
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
	void transferTo(double amount, client& recipient) {
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

class Employee :public person {
protected:
	double salary;
public:
	Employee() : person() {
		salary = 5000;
	}
	Employee(int id, string name, string password, double salary) : person(name, id, password) {
		setSalary(salary);
	}
	void setSalary(double salary) {
		if (Validation::isValidSalary(salary)) {
			this->salary = salary;
		}
		else {
			cout << "Invalid Salary" << endl;
		}
	}
	double getSalary() {
		return salary;
	}
	void Display() {
		cout << "ID: " << id << endl;
		cout << "Name: " << name << endl;
		cout << "Password: " << password << endl;
		cout << "Salary: " << salary << endl;
	}
};