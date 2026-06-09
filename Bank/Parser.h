#pragma once

#include <vector>
#include <string>
#include "Client.h"
#include "Employee.h"
#include "Admin.h"

using namespace std;

class Parser
{
public:
	//split the line by '-' and return the data in vector of string
    static vector<string> split(string line)
    {
        vector<string> data;
        string temp = "";

        for (int i = 0; i < line.length(); i++)
        {
            if (line[i] == '-')

            {
                data.push_back(temp);
                temp = "";
            }
            else
            {
                temp += line[i];
            }
        }

        data.push_back(temp);
        return data;
    }

	//parse the line to client object
    static Client parseToClient(string line)
    {
        vector<string> data = split(line);

        Client c;

        c.setId(stoi(data[0]));
        c.setName(data[1]);
        c.setPassword(data[2]);
        c.setBalance(stod(data[3]));

        return c;
    }

	//parse the line to employee object
    static Employee parseToEmployee(string line)
    {
        vector<string> data = split(line);

        Employee e;

        e.setId(stoi(data[0]));
        e.setName(data[1]);
        e.setPassword(data[2]);
        e.setSalary(stod(data[3]));

        return e;
    }


	//parse the line to admin object
    static Admin parseToAdmin(string line)
    {
        vector<string> data = split(line);

        Admin a;

        a.setId(stoi(data[0]));
        a.setName(data[1]);
        a.setPassword(data[2]);
        a.setSalary(stod(data[3]));

        return a;
    }
};