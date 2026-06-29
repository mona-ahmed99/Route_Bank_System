#include "Employee.h"
#include <iostream>
std::vector<Employee> Employee::employees;

void Employee::printAllClients() {
    for (auto& c : Client::clients) {
        c.Display();
    }
}

Client* Employee::findClient(int id) {
    for (auto& c : Client::clients) {
        if (c.getId() == id) {
            return &c;
        }
    }
    return nullptr;
}

Employee* Employee::findById(int id) {
    for (auto& e : employees) {
        if (e.getId() == id) {
            return &e;
        }
    }
    return nullptr;
}
