#pragma once
#include <Person.h>
#include <iostream>  // remove this if we add class person from rigiht menu----->
#include <string>  // remove this if we add class person from rigiht menu----->
#include <cctype>  // remove this if we add class person from rigiht menu----->
using namespace std;  // remove this if we add class person from rigiht menu----->

class Employee :public Person {
protected:
    double salary;
public:
    Employee() : Person() {
        salary = 5000;
    }
    Employee(int id, string name, string password, double salary) : Person(name, id, password) {
        this->salary = salary;  // validation in methid setSalary from class EntryData
    }

    double getSalary() {
        return salary;
    }
    void display() override {   // override display method from Person class 
        Person::display();     
        cout << "Salary: " << salary << endl;
    }
};

