#pragma once
#include "Person.h"
#include "Client.h"
#include "FilesHelper.h"
#include <vector>
#include <fstream>
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
		cout << "Employee Information:" << endl;
		Person::Display();
		cout << "Salary: " << salary << endl;
	}

	//add client
	void addClient(Client& client) {
		FilesHelper::saveClient(client);
	}
	//search client
	Client* searchClient(int id) {
		static vector<Client> clients;
		clients = FilesHelper::getClients();
		for (int i = 0; i < clients.size(); i++) {
			if (clients[i].getId() == id) {
				return &clients[i];
			}
		}
		return nullptr;
	}
	//list client
	void listClient() {
		vector<Client> clients;
		clients = FilesHelper::getClients();
		for (int i = 0; i < clients.size(); i++) {
			clients[i].Display();
			cout << endl;
		}
	}
	//edit client
	void editClient(int id, string name, string password, double balance) {
		vector<Client> clients;
		clients = FilesHelper::getClients();
		for (int i = 0; i < clients.size(); i++) {
			if (clients[i].getId() == id) {
				clients[i].setName(name);
				clients[i].setPassword(password);
				clients[i].setBalance(balance);
			}
		}
		ofstream file("Clients.txt");
		for (int i = 0; i < clients.size(); i++) {
			file << clients[i].getId() << "-" 
				 << clients[i].getName() << "-"
				 << clients[i].getPassword() << "-"
				 << clients[i].getBalance() << endl;
		}
		file.close();
	}
};