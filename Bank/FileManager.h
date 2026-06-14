#pragma once

#include "DataSourceInterface.h"
#include "FilesHelper.h"

class FileManager : public DataSourceInterface
{
public:

    // =========================
    // CLIENT
    // =========================
    void addClient(Client obj) override
    {
        FilesHelper::saveClient(obj);
    }

    vector<Client> getAllClients() override
    {
        return FilesHelper::getClients();
    }

    void removeAllClients() override
    {
        FilesHelper::clearFile("Clients.txt", "LastClientId.txt");
    }

    // =========================
    // EMPLOYEE
    // =========================
    void addEmployee(Employee obj) override
    {
        FilesHelper::saveEmployee(obj);
    }

    vector<Employee> getAllEmployees() override
    {
        return FilesHelper::getEmployees();
    }

    void removeAllEmployees() override
    {
        FilesHelper::clearFile("Employees.txt", "LastEmployeeId.txt");
    }

    // =========================
    // ADMIN
    // =========================
    void addAdmin(Admin obj) override
    {
        FilesHelper::saveAdmin(obj);
    }

    vector<Admin> getAllAdmins() override
    {
        return FilesHelper::getAdmins();
    }

    void removeAllAdmins() override
    {
        FilesHelper::clearFile("Admins.txt", "LastAdminId.txt");
    }
};