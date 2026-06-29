#include "EmployeeManager.h"
#include <iostream>
#include <string>
using namespace std;

void EmployeeManager::printEmployeeMenu() {
    cout << "\n===== Employee Menu =====" << endl;
    cout << "1. Add New Client" << endl;
    cout << "2. List All Clients" << endl;
    cout << "3. Search For Client" << endl;
    cout << "4. Edit Client Info" << endl;
    cout << "5. Logout" << endl;
    cout << "=========================" << endl;
    cout << "Enter your choice: ";
}

void EmployeeManager::newClient(Employee* employee) {
    if (employee == nullptr) {
        cout << "Error: Invalid employee." << endl;
        return;
    }
    cout << "\n--- Add New Client ---" << endl;
    int clientId;
    string name, password;
    double balance;
    cout << "Enter Client ID: ";
    cin >> clientId;
    cin.ignore();
    cout << "Enter Client Name: ";
    getline(cin, name);
    cout << "Enter Client Password: ";
    cin >> password;
    cout << "Enter Client Balance: ";
    cin >> balance;
    Client newClient(clientId, name, password, balance);
    employee->addClient(newClient);
    cout << "Client added successfully!" << endl;
}

void EmployeeManager::listAllClients(Employee* employee) {
    if (employee == nullptr) {
        cout << "Error: Invalid employee." << endl;
        return;
    }
    cout << "\n--- All Clients ---" << endl;
    employee->printAllClients();
}

void EmployeeManager::searchForClient(Employee* employee) {
    if (employee == nullptr) {
        cout << "Error: Invalid employee." << endl;
        return;
    }
    cout << "\n--- Search For Client ---" << endl;
    int clientId;
    cout << "Enter Client ID to search: ";
    cin >> clientId;
    Client* found = employee->findClient(clientId);
    if (found != nullptr) {
        cout << "Client Found:" << endl;
        found->Display();
    } else {
        cout << "Client with ID " << clientId << " not found." << endl;
    }
}

void EmployeeManager::editClientInfo(Employee* employee) {
    if (employee == nullptr) {
        cout << "Error: Invalid employee." << endl;
        return;
    }
    cout << "\n--- Edit Client Info ---" << endl;
    int clientId;
    cout << "Enter Client ID to edit: ";
    cin >> clientId;
    Client* client = employee->findClient(clientId);
    if (client == nullptr) {
        cout << "Client with ID " << clientId << " not found." << endl;
        return;
    }
    cout << "Current Info:" << endl;
    client->Display();
    string newName;
    double newBalance;
    cin.ignore();
    cout << "Enter New Name (leave blank to keep current): ";
    getline(cin, newName);
    if (!newName.empty()) {
        client->setName(newName);
    }
    cout << "Enter New Balance (-1 to keep current): ";
    cin >> newBalance;
    if (newBalance >= 0) {
        client->setBalance(newBalance);
    }
    cout << "Client info updated successfully!" << endl;
}

Employee* EmployeeManager::login(int id, string password) {
    cout << "\n--- Employee Login ---" << endl;
    Employee* emp = Employee::findById(id);
    if (emp != nullptr && emp->getPassword() == password) {
        cout << "Login successful! Welcome, " << emp->getName() << endl;
        return emp;
    }
    cout << "Invalid ID or password." << endl;
    return nullptr;
}

bool EmployeeManager::employeeOptions(Employee* employee) {
    if (employee == nullptr) {
        cout << "Error: No employee logged in." << endl;
        return false;
    }
    int choice;
    bool keepRunning = true;
    while (keepRunning) {
        printEmployeeMenu();
        cin >> choice;
        switch (choice) {
            case 1:
                newClient(employee);
                break;
            case 2:
                listAllClients(employee);
                break;
            case 3:
                searchForClient(employee);
                break;
            case 4:
                editClientInfo(employee);
                break;
            case 5:
                cout << "Logging out..." << endl;
                keepRunning = false;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    }
    return true;
}
