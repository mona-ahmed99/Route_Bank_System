

#pragma once
#include <iostream>
#include <string>
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
        password = "0";
    }

    person(string name, int id, string password) {
        this->name = name;
        this->id = id;
        this->password = password;
    }

    void setname(string name) {
        this->name = name;
    }

    void setid(int id) {
        this->id = id;
    }

    void setpassword(string password) {
        this->password = password;
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
