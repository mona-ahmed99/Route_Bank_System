#include "ClientManager.h"
#include <iostream>
using namespace std;

void ClientManager::printClientMenu() {
    cout << "\n========== Client Menu ==========\n";
    cout << "1. Deposit\n";
    cout << "2. Withdraw\n";
    cout << "3. Transfer\n";
    cout << "4. Check Balance\n";
    cout << "5. Update Password\n";
    cout << "6. Logout\n";
}

void ClientManager::updatePassword(Person* person) {
    string password = EntryData::getPassword();
    person->setPassword(password);
    cout << "Password Updated Successfully.\n";
}

Client* ClientManager::login(int id, string password) {
    static vector<Client> clients;
    clients = FilesHelper::getClients();
    for (int i = 0; i < clients.size(); i++) {
        if (clients[i].getId() == id && clients[i].getPassword() == password) {
            return &clients[i];
        }
    }
    return nullptr;
}

void ClientManager::saveClients(vector<Client>& clients) {
    ofstream file("Clients.txt");
    for (int i = 0; i < clients.size(); i++) {
        file << clients[i].getId() << "-"
             << clients[i].getName() << "-"
             << clients[i].getPassword() << "-"
             << clients[i].getBalance()
             << endl;
    }
    file.close();
}

bool ClientManager::clientOptions(Client* client) {
    int choice;
    do {
        vector<Client> clients = FilesHelper::getClients();
        printClientMenu();
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
        case 1: {
            double amount = EntryData::getAmount();
            client->deposit(amount);
            for (int i = 0; i < clients.size(); i++) {
                if (clients[i].getId() == client->getId()) {
                    clients[i] = *client;
                }
            }
            saveClients(clients);
            break;
        }
        case 2: {
            double amount = EntryData::getAmount();
            client->withdraw(amount);
            for (int i = 0; i < clients.size(); i++) {
                if (clients[i].getId() == client->getId()) {
                    clients[i] = *client;
                }
            }
            saveClients(clients);
            break;
        }
        case 3: {
            int id;
            cout << "Enter Recipient ID: ";
            cin >> id;
            double amount = EntryData::getAmount();
            bool found = false;
            for (int i = 0; i < clients.size(); i++) {
                if (clients[i].getId() == id) {
                    client->transferTo(amount, clients[i]);
                    found = true;
                    break;
                }
            }
            if (!found) {
                cout << "Client Not Found.\n";
            }
            for (int i = 0; i < clients.size(); i++) {
                if (clients[i].getId() == client->getId()) {
                    clients[i] = *client;
                }
            }
            saveClients(clients);
            break;
        }
        case 4: {
            client->checkBalance();
            break;
        }
        case 5: {
            updatePassword(client);
            for (int i = 0; i < clients.size(); i++) {
                if (clients[i].getId() == client->getId()) {
                    clients[i] = *client;
                }
            }
            saveClients(clients);
            break;
        }
        case 6: {
            cout << "Logging out...\n";
            return true;
        }
        default:
            cout << "Invalid Choice.\n";
        }
    } while (true);
}

