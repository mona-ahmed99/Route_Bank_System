#pragma once

#include "Employee.h"
#include "FilesHelper.h"
#include <vector>

using namespace std;

class Admin : public Employee
{
public:
	static vector<Admin> allAdmins;

	// Default Constructor
	Admin() : Employee() {}

	Admin(int id, string name, string password, double salary)
		: Employee(id, name, password, salary) {
	}

	// display admin info
	void Display() {
		cout << "Admin Information:" << endl;
		Employee::Display();
	}

	// add employee
	void addEmployee(Employee& employee) {
		Employee::allEmployees.push_back(employee);
		FilesHelper::saveEmployee(employee);
	}

	// search employee
	Employee* searchEmployee(int id) {
		for (int i = 0; i < Employee::allEmployees.size(); i++) {
			if (Employee::allEmployees[i].getId() == id) {
				return &Employee::allEmployees[i];
			}
		}
		return nullptr;
	}

	// list employees
	void listEmployee() {
		for (int i = 0; i < Employee::allEmployees.size(); i++) {
			Employee::allEmployees[i].Display();
			cout << endl;
		}
	}

	// edit employee
	void editEmployee(int id, string name, string password, double salary) {
		for (int i = 0; i < Employee::allEmployees.size(); i++) {
			if (Employee::allEmployees[i].getId() == id) {
				Employee::allEmployees[i].setName(name);
				Employee::allEmployees[i].setPassword(password);
				Employee::allEmployees[i].setSalary(salary);
			}
		}

		// rewrite file after edit
		FilesHelper::clearFile("Employees.txt", "LastEmployeeId.txt");

		for (int i = 0; i < Employee::allEmployees.size(); i++) {
			FilesHelper::saveEmployee(Employee::allEmployees[i]);
		}
	}
};