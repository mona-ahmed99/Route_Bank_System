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
		Employee::employees.push_back(employee);
		FilesHelper::saveEmployee(employee);
	}

	// search employee
	Employee* searchEmployee(int id) {
		for (int i = 0; i < Employee::employees.size(); i++) {
			if (Employee::employees[i].getId() == id) {
				return &Employee::employees[i];
			}
		}
		return nullptr;
	}

	// list employees
	void listEmployee() {
		for (int i = 0; i < Employee::employees.size(); i++) {
			Employee::employees[i].Display();
			cout << endl;
		}
	}

	// edit employee
	void editEmployee(int id, string name, string password, double salary) {
		for (int i = 0; i < Employee::employees.size(); i++) {
			if (Employee::employees[i].getId() == id) {
				Employee::employees[i].setName(name);
				Employee::employees[i].setPassword(password);
				Employee::employees[i].setSalary(salary);
			}
		}

		// rewrite file after edit
		FilesHelper::clearFile("Employees.txt", "LastEmployeeId.txt");

		for (int i = 0; i < Employee::employees.size(); i++) {
			FilesHelper::saveEmployee(Employee::employees[i]);
		}
	}
};