#pragma once
#include "Client.h"
#include "FilesHelper.h"
#include "EntryData.h"
#include <vector>
#include <fstream>
using namespace std;
class ClientManager {
public:
    static void printClientMenu();
    static void updatePassword(Person* person);
    static Client* login(int id, string password);
    static void saveClients(vector<Client>& clients);
    static bool clientOptions(Client* client);
};
