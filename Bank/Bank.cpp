
//#include "Screen.h"
//#include"Parser.h"
#include "FileManager.h"

//#include "FilesHelper.h"

int main() {
	//Screen::runApp();
	//test parser
	//string line = "1-Mona-12345678-5000";

	//Client c = Parser::parseToClient(line);

	//c.Display();


	//test write in files helper 
	//Client c;

	//c.setName("Mona");
	//c.setPassword("12345678");
	//c.setBalance(5000);

	//FilesHelper::saveClient(c);


	//test read from files helper
	//vector<Client> clients = FilesHelper::getClients();

	//for (Client c : clients)
	//{
	//	c.Display();
	//}

	//return 0;	


	//test file manager 
	FileManager fm;

	Client c;
	c.setName("Mona");
	c.setPassword("12345678");
	c.setBalance(5000);

	fm.addClient(c);

	vector<Client> clients = fm.getAllClients();

	for (Client c : clients)
	{
		c.Display();
		cout << "-------------------" << endl;
	}
}
