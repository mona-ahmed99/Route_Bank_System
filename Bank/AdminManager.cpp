#include "AdminManager.h"
#include "Admin.h"
#include <iostream>
using namespace std;

void AdminManager::printAdminMenu() {
    cout << "\n========== Admin Menu ==========" << endl;
    cout << "--- Client Management ---" << endl;
    cout << "1. Add New Client" << endl;
    cout << "2. List All Clients" << endl;
    cout << "3. Search For Client" << endl;
    cout << "4. Edit Client Info" << endl;
    cout << "--- Employee Management ---" << endl;
    cout << "5. Add New Employee" << endl;
    cout << "6. List All Employees" << endl;
    cout << "7. Search For Employee" << endl;
    cout << "8. Edit Employee Info" << endl;
    cout << "================================" << endl;
    cout << "9. Logout" << endl;
    cout << "Enter your choice: ";
}

Admin* AdminManager::login(int id, std::string password) {
    for (auto& a : Admin::allAdmins) {
        if (a.getId() == id && a.getPassword() == password) {
            return &a;
        }
    }
    return nullptr;
}

void AdminManager::newClient(Admin* admin) {
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
    admin->addClient(newClient);
    cout << "Client added successfully!" << endl;
}

void AdminManager::listAllClients(Admin* admin) {
    cout << "\n--- All Clients ---" << endl;
    admin->printAllClients();
}

void AdminManager::searchForClient(Admin* admin) {
    cout << "\n--- Search For Client ---" << endl;
    int clientId;
    cout << "Enter Client ID to search: ";
    cin >> clientId;
    Client* found = admin->findClient(clientId);
    if (found != nullptr) {
        cout << "Client Found:" << endl;
        found->Display();
    } else {
        cout << "Client with ID " << clientId << " not found." << endl;
    }
}

void AdminManager::editClientInfo(Admin* admin) {
    cout << "\n--- Edit Client Info ---" << endl;
    int clientId;
    cout << "Enter Client ID to edit: ";
    cin >> clientId;
    Client* client = admin->findClient(clientId);
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

void AdminManager::newEmployee(Admin* admin) {
    cout << "\n--- Add New Employee ---" << endl;
    int empId;
    string name, password;
    double salary;
    cout << "Enter Employee ID: ";
    cin >> empId;
    cin.ignore();
    cout << "Enter Employee Name: ";
    getline(cin, name);
    cout << "Enter Employee Password: ";
    cin >> password;
    cout << "Enter Employee Salary: ";
    cin >> salary;
    Employee emp(empId, name, password, salary);
    admin->addEmployee(emp);
    cout << "Employee added successfully!" << endl;
}

void AdminManager::listAllEmployees(Admin* admin) {
    cout << "\n--- All Employees ---" << endl;
    admin->listEmployee();
}

void AdminManager::searchForEmployee(Admin* admin) {
    cout << "\n--- Search For Employee ---" << endl;
    int empId;
    cout << "Enter Employee ID to search: ";
    cin >> empId;
    Employee* found = admin->searchEmployee(empId);
    if (found != nullptr) {
        cout << "Employee Found:" << endl;
        found->Display();
    } else {
        cout << "Employee with ID " << empId << " not found." << endl;
    }
}

void AdminManager::editEmployeeInfo(Admin* admin) {
    cout << "\n--- Edit Employee Info ---" << endl;
    int empId;
    cout << "Enter Employee ID to edit: ";
    cin >> empId;
    Employee* emp = admin->searchEmployee(empId);
    if (emp == nullptr) {
        cout << "Employee with ID " << empId << " not found." << endl;
        return;
    }
    cout << "Current Info:" << endl;
    emp->Display();
    string newName, newPassword;
    double newSalary;
    cin.ignore();
    cout << "Enter New Name (leave blank to keep current): ";
    getline(cin, newName);
    if (!newName.empty()) {
        emp->setName(newName);
    }
    cout << "Enter New Password (leave blank to keep current): ";
    getline(cin, newPassword);
    if (newPassword.empty()) {
        newPassword = emp->getPassword();
    }
    cout << "Enter New Salary (-1 to keep current): ";
    cin >> newSalary;
    if (newSalary < 0) {
        newSalary = emp->getSalary();
    }
    admin->editEmployee(empId, newName.empty() ? emp->getName() : newName, newPassword, newSalary);
    cout << "Employee info updated successfully!" << endl;
}

bool AdminManager::AdminOptions(Admin* admin) {
    int choice;
    while (true) {
        printAdminMenu();
        cin >> choice;
        switch (choice) {
            case 1: newClient(admin); break;
            case 2: listAllClients(admin); break;
            case 3: searchForClient(admin); break;
            case 4: editClientInfo(admin); break;
            case 5: newEmployee(admin); break;
            case 6: listAllEmployees(admin); break;
            case 7: searchForEmployee(admin); break;
            case 8: editEmployeeInfo(admin); break;
            case 9:
                cout << "Logging out...\n";
                return false;
            default:
                cout << "Invalid option. Please try again.\n";
                break;
        }
    }
    return true;
}
