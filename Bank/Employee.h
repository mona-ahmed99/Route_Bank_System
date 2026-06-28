#pragma once

#include "Person.h"
#include "Client.h"
#include "FilesHelper.h"
#include <vector>

using namespace std;

class Employee : public Person
{
protected:
	double salary;

public:
	static vector<Employee> allEmployees;

	Employee() : Person(), salary(5000) {}

	Employee(int id, string name, string password, double salary)
		: Person(name, id, password), salary(salary) {
	}

	// setters salary
	void setSalary(double salary) {
		if (Validation::isValidSalary(salary)) {
			this->salary = salary;
		}
		else {
			this->salary = 0;
		}
	}

	// getters salary
	double getSalary() {
		return salary;
	}

	// display employee info
	void Display() {
		cout << "Employee Information:" << endl;
		Person::Display();
		cout << "Salary: " << salary << endl;
	}

	// add client
	void addClient(Client& client) {
		Client::allClients.push_back(client);
		FilesHelper::saveClient(client);
	}

	// search client
	Client* searchClient(int id) {
		for (int i = 0; i < Client::allClients.size(); i++) {
			if (Client::allClients[i].getId() == id) {
				return &Client::allClients[i];
			}
		}
		return nullptr;
	}

	// list clients
	void listClient() {
		for (int i = 0; i < Client::allClients.size(); i++) {
			Client::allClients[i].Display();
			cout << endl;
		}
	}

	// edit client
	void editClient(int id, string name, string password, double balance) {
		for (int i = 0; i < Client::allClients.size(); i++) {
			if (Client::allClients[i].getId() == id) {
				Client::allClients[i].setName(name);
				Client::allClients[i].setPassword(password);
				Client::allClients[i].setBalance(balance);
			}
		}

		// rewrite file after edit
		FilesHelper::clearFile("Clients.txt", "LastClientId.txt");

		for (int i = 0; i < Client::allClients.size(); i++) {
			FilesHelper::saveClient(Client::allClients[i]);
		}
	}
};