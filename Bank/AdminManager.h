#pragma once
#include "Admin.h"
#include <string>
class AdminManager {
public:
	static void printAdminMenu();
	static Admin* login(int id, std::string password);
	static bool AdminOptions(Admin* admin);

	// Employee (client) operations
	static void newClient(Admin* admin);
	static void listAllClients(Admin* admin);
	static void searchForClient(Admin* admin);
	static void editClientInfo(Admin* admin);

	// Admin-only (employee management) operations
	static void newEmployee(Admin* admin);
	static void listAllEmployees(Admin* admin);
	static void searchForEmployee(Admin* admin);
	static void editEmployeeInfo(Admin* admin);
};
