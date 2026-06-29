#pragma once
#include "Validation.h"
#include <iostream>
#include <string>

using namespace std;

class Person
{
protected:
    string name;
    int id;
    string password;

public:
    Person(): id(0), name(""), password("") {}

    Person(string name, int id, string password): name(name), id(id), password(password) {}

    void setName(string name) {
		if (Validation::isValidName(name)) {
			this->name = name;
		}
		else {
			this->name = "";
		}
    }

    void setId(int id) {
        this->id = id;
    }

    void setPassword(string password) {
		if (Validation::isValidPassword(password)) {
			this->password = password;
		}
		else {
			this->password = "";
		}
    }

    string getName() {
        return name;
    }

    int getId() {
        return id;
    }

    string getPassword() {
        return password;
    }

	void Display() const {
		cout << "ID: " << id << endl;
		cout << "Name: " << name << endl;
		cout << "Password: " << password << endl;
	}
};

