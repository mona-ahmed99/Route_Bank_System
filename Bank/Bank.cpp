
#pragma once
#include <iostream>
#include <string>
#include <cctype>
using namespace std;
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