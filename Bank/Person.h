#pragma once
#include "Validation.h"
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
		this->name = name;
    }

    void setId(int id) {
        this->id = id;
    }

    void setPassword(string password) {
		this->password = password;
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

	void Display() {
		cout << "ID: " << id << endl;
		cout << "Name: " << name << endl;
		cout << "Password: " << password << endl;
	}
};

