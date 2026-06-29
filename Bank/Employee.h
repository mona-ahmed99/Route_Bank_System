#pragma once

#include "Person.h"
#include "Client.h"
#include "FilesHelper.h"
#include <vector>
#include <fstream>

using namespace std;

class Employee : public Person
{
protected:
	double salary;

public:
	static vector<Employee> employees;
	Employee() : Person(), salary(5000) {}
	Employee(int id, std::string name, std::string password, double salary) : Person(name, id, password), salary(salary) {}

	void setSalary(double salary) {
		if (Validation::isValidSalary(salary)) {
			this->salary = salary;
		}
		else {
			this->salary = 0;
		}
	}
	double getSalary() {
		return salary;
	}
	void Display() {
		cout << "Employee Information:" << endl;
		Person::Display();
		cout << "Salary: " << salary << endl;
	}
	void addClient(Client& client) {
		FilesHelper::saveClient(client);
	}
	void printAllClients();
	Client* findClient(int id);
	static Employee* findById(int id);
};