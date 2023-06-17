#include <iostream>
#include <iomanip>
using namespace std;
#include "Inventory.h"
#include <fstream>
#include <cstring>

string Category::getCategory() {
	return itemCategory;
}

void Item::checkReorder() {
	const int minimum = 10;
	int c;
	if (quantity <= minimum) {
		cout << "Warning. Stock has fallen below 10.\nDo you want to restock by ordering 50 items?(1/0)";
		cin >> c;
		if (c == 1) {
			cout << "Item restocked succesfully.\n";
			quantity += 50;
		}
	}
}

void Item::inputFromFile(Item* a, int s) {
	fstream fin;
	fin.open("inventory.txt");
	int temp;
	fin >> temp;
	fin >> temp;
	for (int i = 0; i < s; i++) {
		fin >> a[i].itemID;
		fin >> a[i].itemName;
		fin >> a[i].itemCategory;
		fin >> a[i].quantity;
		fin >> a[i].unitPrice;
	}
	fin.close();
}

void Item::display(Item* a, int s) {
	cout << left << setw(7) << "ID";
	cout << left << setw(30) << "Name";
	cout << left << setw(15) << "Category";
	cout << left << setw(10) << "Quantity";
	cout << left << setw(10) << "Price";
	cout << endl << endl;
	for (int i = 0; i < s; i++) {
		int l = strlen(a[i].itemName);
		for (int j = 0; j < l; j++) {
			if (a[i].itemName[j] == '_')
				a[i].itemName[j] = ' ';
		}
		cout << left << setw(7) << a[i].itemID;
		cout << left << setw(30) << a[i].itemName;
		cout << left << setw(15) << a[i].itemCategory;
		cout << left << setw(10) << a[i].quantity;
		cout << left << setw(10) << a[i].unitPrice;
		for (int j = 0; j < l; j++) {
			if (a[i].itemName[j] == ' ')
				a[i].itemName[j] = '_';
		}
		cout << endl;
	}
	cout << endl;
}

void Item::displayItem() {
	cout << "ID: " << itemID << endl;
	cout << "Name: ";
	int n = strlen(itemName);
	for (int i = 0;i < n;i++) {
		if (itemName[i] == '_')
			cout << " ";
		else
			cout << itemName[i];
	}
	cout << endl;
	cout << "Category: " << itemCategory << endl;
	cout << "Quantity: " << quantity << endl;
	cout << "Price: " << unitPrice<<endl;
}

int Item::getID() {
	return itemID;
}

int Item::getQuantity() {
	return quantity;
}

int Item::getPrice() {
	return unitPrice;
}

char* Item::getName() {
	return itemName;
}

void Item::setQuantity(int a) {
	quantity = a;
}

void Item::inputCart(Item* c, Item* a, int tItem, int& numItem) {

	int id, qt;
	bool match;
	for (int i = 0; i < numItem; i++) {
		do {
			match = false;
			cout << "Enter item ID for item " << i + 1 << ": ";
			cin >> id;
			for (int j = 0; j < tItem; j++) {
				if (id == a[j].getID()) {
					match = true;
					do {
						cout << "Enter quantity: ";
						cin >> qt;
						if (qt > a[j].quantity)
							cout << "Not enough stock. Only " << a[j].quantity << " items remaining.\n";
					} while (qt > a[j].quantity);
					c[i] = a[j];
					c[i].quantity = qt;
					a[j].quantity -= qt;
					a[j].checkReorder();
				}
			}
			if (!match)
				cout << "No match found. please enter again.\n";
		} while (!match);

	}
}

int Item::getCartItems(int tItem) {
	int numItem;
	do {
		cout << "Enter number of items in cart : ";
		cin >> numItem;
		if (numItem > tItem)
			cout << "Items in cart exceed total number of items. Please enter again.\n";
	} while (numItem > tItem);
	return numItem;
}

float Item::calculateBill(Item* a, int s) {
	float total = 0;
	for (int i = 0; i < s; i++) {
		total += a[i].quantity * a[i].unitPrice;
	}
	return total;
}

float Item::loyaltyBill(Item* a, int s, int p) {
	float total = 0;
	for (int i = 0; i < s; i++) {
		total += a[i].quantity * a[i].unitPrice;
	}
	total -= p;
	return total;
}

void Item::displayCart(Item* a, int s, float t) {
	cout << left << setw(7) << "ID";
	cout << left << setw(30) << "Name";
	cout << left << setw(15) << "Category";
	cout << left << setw(10) << "Quantity";
	cout << left << setw(7) << "Price";
	cout << left << setw(10) << "Total";
	cout << endl << endl;
	for (int i = 0; i < s; i++) {
		int l = strlen(a[i].itemName);
		for (int j = 0; j < l; j++) {
			if (a[i].itemName[j] == '_')
				a[i].itemName[j] = ' ';
		}
		cout << left << setw(7) << a[i].itemID;
		cout << left << setw(30) << a[i].itemName;
		cout << left << setw(15) << a[i].itemCategory;
		cout << left << setw(10) << a[i].quantity;
		cout << left << setw(7) << a[i].unitPrice;
		cout << left << setw(7) << a[i].quantity * a[i].unitPrice;
		for (int j = 0; j < l; j++) {
			if (a[i].itemName[j] == ' ')
				a[i].itemName[j] = '_';
		}
		if (i < s - 1)
			cout << endl;
	}
	cout << setw(113) << " " << "------";
	cout << setw(114) << " " << "Rs " << t;
	cout << endl;
}