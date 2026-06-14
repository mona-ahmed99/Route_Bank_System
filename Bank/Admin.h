#pragma once
#include "Employee.h"
#include "FilesHelper.h"
#include <vector>
#include <fstream>
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

	//add employee
	void addEmployee(Employee& employee) {
		FilesHelper::saveEmployee(employee);
	}
	//search employee
	Employee* searchEmployee(int id) {
		static vector<Employee> employees;
		employees = FilesHelper::getEmployees();
		for (int i = 0; i < employees.size(); i++) {
			if (employees[i].getId() == id) {
				return &employees[i];
			}
		}
		return nullptr;
	}
	//list employee
	void listEmployee() {
		vector<Employee> employees;
		employees = FilesHelper::getEmployees();
		for (int i = 0; i < employees.size(); i++) {
			employees[i].Display();
			cout << endl;
		}
	}
	//edit employee
	void editEmployee(int id, string name, string password, double salary) {
		vector<Employee> employees;
		employees = FilesHelper::getEmployees();
		for (int i = 0; i < employees.size(); i++) {
			if (employees[i].getId() == id) {
				employees[i].setName(name);
				employees[i].setPassword(password);
				employees[i].setSalary(salary);
			}
		}
		ofstream file("Employees.txt");
		for (int i = 0; i < employees.size(); i++) {
			file << employees[i].getId() << "-"
				<< employees[i].getName() << "-"
				<< employees[i].getPassword() << "-"
				<< employees[i].getSalary() << endl;
		}
		file.close();
	}
};
