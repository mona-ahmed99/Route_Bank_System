#include "FileManager.h"

vector<Client> Client::allClients;
vector<Employee> Employee::allEmployees;
vector<Admin> Admin::allAdmins;

int main() {
	//FileManager fm;

	//Client::allClients = fm.getAllClients();
	//Employee::allEmployees = fm.getAllEmployees();
	//Admin::allAdmins = fm.getAllAdmins();


	FileManager fm;

	Client::allClients = fm.getAllClients();

	Client c;
	c.setName("Mona");
	c.setPassword("12345678");
	c.setBalance(5000);

	fm.addClient(c);

	// مهم جدًا
	Client::allClients = fm.getAllClients();

	for (Client c : Client::allClients)
	{
		c.Display();
	}
};