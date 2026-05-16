#pragma once

#include "Client.h"
#include "Employee.h"
#include "Admin.h"
#include "EntryData.h"

class Screen
{
private:

    // Display Main Menu
    static void displayMenu() {
        cout << "1. Login as Client\n";
        cout << "2. Login as Employee\n";
        cout << "3. Login as Admin\n";
        cout << "4. Exit\n";
    }

public:

    static void runApp() {

        cout << "========== BANK SYSTEM ==========\n press to continue";

        cin.get();

        system("cls");

        int choice;

        do {

            displayMenu();

            cout << "Enter your choice:\n ";
            cin >> choice;

            system("cls");

            switch (choice) {

                // ================= CLIENT =================

            case 1: {

                cout << "========== CLIENT TEST ==========\n";

                int id;

                cout << "Enter Client ID:\n ";
                cin >> id;

                string name = EntryData::getName();

                string password = EntryData::getPassword();

                double balance = EntryData::getBalance();

                // Create Client Object
                Client c1(id, name, password, balance);

                cout << "\nClient Created Successfully\n";

                c1.Display();

                // ===== Deposit =====

                cout << "\n========== DEPOSIT TEST ==========\n";

                double amount = EntryData::getAmount();

                c1.deposit(amount);

                c1.checkBalance();

                // ===== Withdraw =====

                cout << "\n========== WITHDRAW TEST ==========\n";

                amount = EntryData::getAmount();

                // validation before calling withdraw
                while (!Validation::canWithdraw(amount, c1.getBalance())) {

                    cout << "Insufficient Balance.\n";

                    amount = EntryData::getAmount();
                }

                c1.withdraw(amount);

                c1.checkBalance();

                // ===== Transfer =====

                cout << "\n========== TRANSFER TEST ==========\n";

                // Recipient Client
                Client c2(2, "Ahmed", "12345678", 5000);

                cout << "\nRecipient Client:\n";

                c2.Display();

                amount = EntryData::getAmount();

                // validation before transfer
                while (!Validation::canWithdraw(amount, c1.getBalance())) {

                    cout << "Insufficient Balance.\n";

                    amount = EntryData::getAmount();
                }

                c1.transferTo(amount, c2);

                cout << "\nSender Data After Transfer:\n";

                c1.Display();

                cout << "\nRecipient Data After Transfer:\n";

                c2.Display();

                break;
            }

                  // ================= EMPLOYEE =================

            case 2: {

                cout << "========== EMPLOYEE TEST ==========\n";

                int id;

                cout << "Enter Employee ID:\n ";
                cin >> id;

                string name = EntryData::getName();

                string password = EntryData::getPassword();

                double salary = EntryData::getSalary();

                // Create Employee Object
                Employee e(id, name, password, salary);

                cout << "\nEmployee Created Successfully\n";

                e.Display();

                break;
            }

                  // ================= ADMIN =================

            case 3: {

                cout << "========== ADMIN TEST ==========\n";

                int id;

                cout << "Enter Admin ID:\n ";
                cin >> id;

                string name = EntryData::getName();

                string password = EntryData::getPassword();

                double salary = EntryData::getSalary();

                // Create Admin Object
                Admin a(id, name, password, salary);

                cout << "\nAdmin Created Successfully\n";

                a.Display();

                break;
            }

                  // ================= EXIT =================

            case 4:

                cout << "Exiting Program...\n";

                break;

                // ================= INVALID =================

            default:

                cout << "Invalid Choice.\n";
            }

            cout << "\nPress Enter to continue...";
            cin.ignore();
            cin.get();

            system("cls");

        } while (choice != 4);
    }
};