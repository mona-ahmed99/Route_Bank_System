#pragma once

#include "DataSourceInterface.h"
#include "FilesHelper.h"

class FileManager : public DataSourceInterface
{
public:

    // =========================
    // CLIENT
    // =========================
    void addClient(Client obj)
    {
        FilesHelper::saveClient(obj);
    }

    vector<Client> getAllClients()
    {
        return FilesHelper::getClients();
    }

    void removeAllClients()
    {
        FilesHelper::clearFile("Clients.txt", "LastClientId.txt");
    }

    // =========================
    // EMPLOYEE
    // =========================
    void addEmployee(Employee obj)
    {
        FilesHelper::saveEmployee(obj);
    }

    vector<Employee> getAllEmployees()
    {
        return FilesHelper::getEmployees();
    }

    void removeAllEmployees()
    {
        FilesHelper::clearFile("Employees.txt", "LastEmployeeId.txt");
    }

    // =========================
    // ADMIN
    // =========================
    void addAdmin(Admin obj)
    {
        FilesHelper::saveAdmin(obj);
    }

    vector<Admin> getAllAdmins()
    {
        return FilesHelper::getAdmins();
    }

    void removeAllAdmins()
    {
        FilesHelper::clearFile("Admins.txt", "LastAdminId.txt");
    }
};