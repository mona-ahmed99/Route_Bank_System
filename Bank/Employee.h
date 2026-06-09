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
		if (Validation::isValidSalary(salary)) {
			this->salary = salary;
		}
		else {
			this->salary = 0;
		}
	}
	//gettters salary
	double getSalary() {
		return salary;
	}
	//display employee info
	void Display() {
		cout<<"Employee Information:"<<endl;
		Person::Display();
		cout << "Salary: " << salary << endl;
	}
};

