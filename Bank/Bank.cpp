#include "Screen.h"
#include "Admin.h"
#include "Employee.h"
#include "Client.h"
#include "FilesHelper.h"

int main() {
	Admin::allAdmins = FilesHelper::getAdmins();
	Employee::employees = FilesHelper::getEmployees();
	Client::clients = FilesHelper::getClients();
	Screen::runApp();
};