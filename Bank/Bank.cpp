
#include "Screen.h"
#include"Parser.h"

int main() {
	//Screen::runApp();
	string line = "1-Mona-12345678-5000";

	Client c = Parser::parseToClient(line);

	c.Display();
}