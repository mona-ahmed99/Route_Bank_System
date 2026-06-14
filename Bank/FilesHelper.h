#pragma once

#include <vector>
#include <string>

using namespace std;

class Client;
class Employee;
class Admin;

class FilesHelper
{
public:
    static void saveLast(const string& fileName, int id);
    static int getLast(const string& fileName);

    static void saveClient(Client& c);
    static void saveEmployee(Employee& e);
    static void saveAdmin(Admin& a);

    static vector<Client> getClients();
    static vector<Employee> getEmployees();
    static vector<Admin> getAdmins();

    static void clearFile(const string& fileName, const string& lastIdFile);
};
