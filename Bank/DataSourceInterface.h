#pragma once
#include "Client.h"
#include "Employee.h"
#include "Admin.h"

class DataSourceInterface
{
public:
    // Client operations
    virtual void addClient(Client obj) = 0;
    virtual void getAllClients() = 0;
    virtual void removeAllClients() = 0;

    // Employee operations 
    virtual void addEmployee(Employee obj) = 0;
    virtual void getAllEmployees() = 0;
    virtual void removeAllEmployees() = 0;

    // Admin operations
    virtual void addAdmin(Admin obj) = 0;
    virtual void getAllAdmins() = 0;
    virtual void removeAllAdmins() = 0;

    // Virtual destructor 
    virtual ~DataSourceInterface() {}
};

