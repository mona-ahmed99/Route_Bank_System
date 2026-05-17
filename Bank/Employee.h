#pragma once
#include "Person.h"
class Employee :
	public Person
{
protected:
	double salary;
public:
	Employee() : Person(), salary(5000) {}
	Employee(int id, string name, string password, double salary) : Person(name, id, password), salary(salary) {}

	//setters salary
	void setSalary(double salary) {
			this->salary = salary;
	}
	//gettters salary
	double getSalary() {
		return salary;
	}
	//display employee info
	void Display() {
		cout<<"Employee Information:"<<endl;
		cout << "ID: " << id << endl;
		cout << "Name: " << name << endl;
		cout << "Password: " << password << endl;
		cout << "Salary: " << salary << endl;
	}
};

