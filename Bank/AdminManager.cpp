#include "AdminManager.h"
#include "Admin.h"
#include <iostream>
using namespace std;


void AdminManager::printEmployeeMenu() {
    cout << "\n========== Admin Menu ==========" << endl;
    cout << "1. Logout" << endl;
}

Admin* AdminManager::login(int id, std::string password) {
    for (auto& a : Admin::allAdmins) {
        if (a.getId() == id && a.getPassword() == password) {
            return &a;
        }
    }
    return nullptr;
}

bool AdminManager::AdminOptions(Admin* admin) {
    int choice;
    while (true) {
        printEmployeeMenu();
        cin >> choice;
        if (choice == 1) {
            cout << "Logging out...\n";
            return false;
        } else {
            cout << "Invalid option.\n";
        }
    }
    return true;
}
