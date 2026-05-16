#pragma once
#include "Employee.h"
class Admin : public Employee
{
public:

    ////// Default Constructor

    Admin() : Employee() {

    }
    Admin(int id, string name, string password, double salary) : Employee(id, name, password, salary) {

    }

    //// setter

    void setName(string name)
    {
        if (Validation::isValidName(name))
            this->name = name;
        else
            cout << "Invalid Name" << endl;
    }

    void setPassword(string password)
    {
        if (Validation::isValidPassword(password))
            this->password = password;
        else
            cout << "Invalid Password" << endl;
    }

    void setSalary(double salary)
    {
        if (Validation::isValidSalary(salary))
            this->salary = salary;
        else
        {
            cout << "Invalid Salary" << endl;
            this->salary = 5000;
        }
    }

};
