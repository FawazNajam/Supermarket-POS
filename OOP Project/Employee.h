#ifndef Employee_H
#define Employee_H
#include"Inventory.h"
#include"Customer.h"
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

class Employee
{
protected:
    int ID;
    string name;
    double salary;
    double annual_salary;
    string password;
public:
    void display();
    void setdata(ifstream&);
    void setID(int);
    void setname(string);
    void setsalary(double);
    void setannualsalary(double);
    void setpassword(string);
    string getpassword();
    string getname();
    int getID();
    double getSalary();
    double getAnnualSalary();
    void billing(Item*, int);
    //void addCustomer(Customer*, int&);
};


class Cashier : public Employee
{
public:
    void cashiers(int);
    void cashierLogin(Cashier*, int, int&);
    //void copyCashierData(Cashier*, int&);
    void menu(Cashier*, int, Item*, int);
    //void billing(Item*, int);
    void viewByCategory(Item*, int);
};

class Manager : public Employee
{
public:
    void menu(Manager*, Cashier*, int&, Item*, int&, int);
    //void copyManagerData(ifstream&, Manager*);
    void managerLogin(Manager*);
    void updatecashiermenu(Manager*, Cashier*, int&);
    void addCashier(Cashier*, int&);
    void removeCashier(Cashier*, int&);
    void changeSalary(Cashier*, int);
    //void billing();
    void viewByCategory(Item*, int);
    void editInventory(Manager*, Item*, int&, int);
    void addItem(Item*, int&, int);
    void removeItem(Item*, int&, int);
};
#endif