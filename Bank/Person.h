#pragma once
#include "Validation.h"
class Person
{
protected:
    string name;
    int id;
    string password;

public:
    Person() {
        name = "admin";
        id = 0;
        password = "12345678";
    }

    Person(string name, int id, string password) {
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

