#pragma once
#include <iostream>
#include "ClientManager.h"
#include "EmployeeManager.h"
#include "AdminManager.h"
using namespace std;

class Screen {
public:
	// Display the bank name
    static void bankName() {
        cout << "\n========== Route Bank System ==========" << endl;
    }
	// Display the welcome message
    static void welcome() {
        bankName();
        cout << "Welcome to the Route Bank System!\n";
    }
	// Display the login options
    static void loginOptions() {
        cout << "\nLogin Options:" << endl;
        cout << "1. Client" << endl;
        cout << "2. Employee" << endl;
        cout << "3. Admin" << endl;
        cout << "4. Exit" << endl;
    }
	// Get the login type from the user
    static int loginAs() {
        int c;
        loginOptions();
        cout << "Choose login type: ";
        cin >> c;
        return c;
    }
	// Display invalid option message
    static void invalid(int c) {
        cout << "Invalid option: " << c << "\n";
    }
	// Display logout message
    static void logout() {
        cout << "You have been logged out.\n";
    }
	// Handle the login process based on the user type
    static void loginScreen(int c) {
        if (c == 1) {
            int id; string password;
            cout << "\n--- Client Login ---\nID: "; cin >> id;
            cout << "Password: "; cin >> password;
            Client* client = ClientManager::login(id, password);
            if (client) {
                cout << "Login successful!\n";
                ClientManager::clientOptions(client);
            } else {
                cout << "Login failed.\n";
            }
        } else if (c == 2) {
            int id; string password;
            cout << "\n--- Employee Login ---\nID: "; cin >> id;
            cout << "Password: "; cin >> password;
            Employee* emp = EmployeeManager::login(id, password);
            if (emp) {
                cout << "Login successful!\n";
                EmployeeManager::employeeOptions(emp);
            } else {
                cout << "Login failed.\n";
            }
        } else if (c == 3) {
            int id; string password;
            cout << "\n--- Admin Login ---\nID: "; cin >> id;
            cout << "Password: "; cin >> password;
            Admin* admin = AdminManager::login(id, password);
            if (admin) {
                cout << "Login successful!\n";
                AdminManager::AdminOptions(admin);
            } else {
                cout << "Login failed.\n";
            }
        } else if (c == 4) {
            cout << "Exiting...\n";
        } else {
            invalid(c);
        }
    }
	// Run the main application loop
    static void runApp() {
        welcome();
        while (true) {
            int c = loginAs();
            if (c == 4) break;
            loginScreen(c);
            logout();
        }
        cout << "Thank you for using Route Bank System!\n";
    }
};