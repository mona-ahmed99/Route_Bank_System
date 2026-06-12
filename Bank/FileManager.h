#pragma once
#include "DataSourceInterface.h"
#include "FilesHelper.h"

class FileManager : public DataSourceInterface
{
public:

    // Client
    void addClient(Client obj) override {
        FilesHelper::saveClient(obj);
    }

    void getAllClients() override {
        vector<Client> clients = FilesHelper::getClients();
        for (int i = 0; i < clients.size(); i++) {
            clients[i].Display();
            cout << "------------------" << endl;
        }
    }

    void removeAllClients() override {
        FilesHelper::clearFile("Clients.txt", "LastClientId.txt");
    }

    // Employee
    void addEmployee(Employee obj) override {
        FilesHelper::saveEmployee(obj);
    }

    void getAllEmployees() override {
        vector<Employee> employees = FilesHelper::getEmployees();
        for (int i = 0; i < employees.size(); i++) {
            employees[i].Display();
            cout << "------------------" << endl;
        }
    }

    void removeAllEmployees() override {
        FilesHelper::clearFile("Employees.txt", "LastEmployeeId.txt");
    }

    // Admin
    void addAdmin(Admin obj) override {
        FilesHelper::saveAdmin(obj);
    }

    void getAllAdmins() override {
        vector<Admin> admins = FilesHelper::getAdmins();
        for (int i = 0; i < admins.size(); i++) {
            admins[i].Display();
            cout << "------------------" << endl;
        }
    }

    void removeAllAdmins() override {
        FilesHelper::clearFile("Admins.txt", "LastAdminId.txt");
    }
};