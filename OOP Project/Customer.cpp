#include <iostream>
#include <iomanip>
using namespace std;
#include "Inventory.h"
#include"Customer.h"
#include"Employee.h"
#include <fstream>
#include <cstring>

int Customer::getPoints() {
	return loyaltyPoint;
}

void Customer::inputData(ifstream& input) {
	input >> customerID;
	input >> cPassword;
	input >> cName;
	input >> phoneNum;
	input >> loyaltyPoint;
}

int Customer::customerLogin(Customer* arr, int n) {
	bool flag = false;
	int id, index;
	cout << "Enter Your Customer ID: ";
	while (!flag) {
		cin >> id;
		bool exists = false;
		for (int i = 0;i < n && !exists;i++) {
			if (id == arr[i].customerID) {
				exists = true;
				index = i;
			}
		}
		if (!exists)
			cout << "Customer with ID " << id << " does not exist, Enter Again\n";
		else
			flag = true;
	}
	flag = false;
	string pass;
	cout << "Enter Your Password: ";
	while (!flag) {
		cin.ignore();
		getline(cin, pass);
		if (pass == arr[index].cPassword) {
			cout << "Customer ";
			int len = strlen(arr[index].cName);
			for (int i = 0;i < len;i++) {
				if (arr[index].cName[i] == '_')
					cout << " ";
				else
					cout << arr[index].cName[i];
			}
			cout << endl;
			flag = true;
		}
		else
			cout << "Incorrect Password, Enter Again\n";
	}
	return index;
}

void Customer::resetPoints(float bill) {
	cout << bill << endl;
	loyaltyPoint = bill * (0.07);
	cout << loyaltyPoint << endl;
}

void Customer::addPoints(float bill) {
	loyaltyPoint += bill * 0.07;
}

void Customer::writeToFile(Customer* arr, int n) {
	ofstream write;
	write.open("customer.txt");
	write << n << "\n";
	for (int i = 0;i < n;i++) {
		write << arr[i].customerID << " " << arr[i].cPassword << " " << arr[i].cName << " " << arr[i].phoneNum << " " << arr[i].loyaltyPoint << endl;
	}
	write << "";
	write.close();
}

void Customer::addCustomer(Customer* arr, int& n, float bill) {
	Customer* temp = new Customer[n];
	for (int i = 0;i < n;i++)
		temp[i] = arr[i];
	n++;
	arr = new Customer[n];
	for (int i = 0;i < n - 1;i++)
		arr[i] = temp[i];
	cout << "Enter ID of Customer: ";
	cin >> arr[n - 1].customerID;
	cout << "Enter Password of Customer: ";
	cin.ignore();
	getline(cin, arr[n - 1].cPassword);
	cout << "Enter Name of Customer: ";
	//cin.ignore();
	cin.getline(arr[n - 1].cName, 20);
	cout << "Enter Phone Number of Customer: ";
	getline(cin, arr[n - 1].phoneNum);
	arr[n - 1].resetPoints(bill);
	arr->writeToFile(arr, n);
}