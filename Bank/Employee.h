#pragma once
#include "Person.h"
class Employee :
	public Person
{
protected:
	double salary;
public:
	Employee() : Person() {
		salary = 5000;
	}
	Employee(int id, string name, string password, double salary) : Person(name, id, password) {
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

