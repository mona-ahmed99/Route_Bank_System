#include "FilesHelper.h"

#include <fstream>
#include "Client.h"
#include "Employee.h"
#include "Admin.h"
#include "Parser.h"

using namespace std;

void FilesHelper::saveLast(const string& fileName, int id)
{
	ofstream file(fileName);
	file << id;
	file.close();
}

int FilesHelper::getLast(const string& fileName)
{
	ifstream file(fileName);

	int id = 0;
	file >> id;

	file.close();

	return id;
}

void FilesHelper::saveClient(Client& c)
{
	int id = getLast("LastClientId.txt") + 1;
	c.setId(id);

	ofstream file("Clients.txt", ios::app);

	file << c.getId() << "-"
		<< c.getName() << "-"
		<< c.getPassword() << "-"
		<< c.getBalance()
		<< endl;

	file.close();

	saveLast("LastClientId.txt", id);
}

void FilesHelper::saveEmployee(Employee& e)
{
	int id = getLast("LastEmployeeId.txt") + 1;
	e.setId(id);

	ofstream file("Employees.txt", ios::app);

	file << e.getId() << "-"
		<< e.getName() << "-"
		<< e.getPassword() << "-"
		<< e.getSalary()
		<< endl;

	file.close();

	saveLast("LastEmployeeId.txt", id);
}

void FilesHelper::saveAdmin(Admin& a)
{
	int id = getLast("LastAdminId.txt") + 1;
	a.setId(id);

	ofstream file("Admins.txt", ios::app);

	file << a.getId() << "-"
		<< a.getName() << "-"
		<< a.getPassword() << "-"
		<< a.getSalary()
		<< endl;

	file.close();

	saveLast("LastAdminId.txt", id);
}

vector<Client> FilesHelper::getClients()
{
	vector<Client> clients;

	ifstream file("Clients.txt");
	string line;

	while (getline(file, line))
	{
		if (line != "")
			clients.push_back(Parser::parseToClient(line));
	}

	file.close();

	return clients;
}

vector<Employee> FilesHelper::getEmployees()
{
	vector<Employee> employees;

	ifstream file("Employees.txt");
	string line;

	while (getline(file, line))
	{
		if (line != "")
			employees.push_back(Parser::parseToEmployee(line));
	}

	file.close();

	return employees;
}

vector<Admin> FilesHelper::getAdmins()
{
	vector<Admin> admins;

	ifstream file("Admins.txt");
	string line;

	while (getline(file, line))
	{
		if (line != "")
			admins.push_back(Parser::parseToAdmin(line));
	}

	file.close();

	return admins;
}

void FilesHelper::clearFile(const string& fileName, const string& lastIdFile)
{
	ofstream file(fileName, ios::trunc);
	file.close();

	ofstream file2(lastIdFile, ios::trunc);
	file2 << 0;
	file2.close();
}
