#pragma once
#include "Employee.h"
class Admin : public Employee
{
public:

	////// Default Constructor

	Admin() : Employee() {

	}
	Admin(int id, string name, string password, double salary) : Employee(id, name, password, salary) {}

	//display admin info
	void Display() {
		cout << "Admin Information:" << endl;
		Employee::Display();
	}

};
