#pragma once
#include "Admin.h"
#include <string>
class AdminManager {
public:
	static void printEmployeeMenu();
	static Admin* login(int id, std::string password);
	static bool AdminOptions(Admin* admin);
};
