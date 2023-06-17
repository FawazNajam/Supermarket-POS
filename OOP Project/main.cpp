#include<iostream>
#include<string>
#include<fstream>
#include"Employee.h"
#include"Inventory.h"
#include"Customer.h"

using namespace std;

int main()
{
    ifstream input;
    Cashier* cashier = nullptr;
    Manager* manager = nullptr;
    int choice;
    cout << "Who is logging in? Select :\n";
    cout << "1.Cashier\n2.Manager\n";
    cin >> choice;
    while (!(choice == 1 || choice == 2))
    {
        cout << "Enter again!\n";
        cout << "1.Cashier\n2.Manager";
        cin >> choice;
    }

    //copying cashier data to main method
    int noofcashiers = 0;
    input.open("cashier.txt");
    input >> noofcashiers;
    cashier = new Cashier[noofcashiers];
    for (int i = 0; i < noofcashiers; i++)
        cashier[i].setdata(input);
    input.close();

    //copying manager data to main method
    input.open("manager.txt");
    manager = new Manager;
    manager->setdata(input);
    input.close();

    //copying item data to main
    int numItem, tItem, tCategory;
    fstream fin;
    fin.open("inventory.txt");
    fin >> tItem;
    fin >> tCategory;
    fin.close();
    Item* items = new Item[tItem];
    items->inputFromFile(items, tItem);

    if (choice == 1) {
        int cashIndex;
        cashier->cashierLogin(cashier, noofcashiers, cashIndex);
        cashier->menu(cashier, cashIndex, items, tItem);
    }
    else if (choice == 2) {
        manager->managerLogin(manager);
        manager->menu(manager, cashier, noofcashiers, items, tItem, tCategory);
    }
    delete manager;
    delete[]cashier;
    system("pause");
    return 0;
}