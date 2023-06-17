#ifndef Inventory_H
#define Inventory_H
#include<iostream>
#include<fstream>
using namespace std;

class Inventory {
protected:
	char itemName[50];
	int itemID;
	double unitPrice;
	int quantity;
public:
	Inventory() {}
};

class Category :public Inventory {
protected:
	string itemCategory;
public:
	Category() {}
	//void setCategory();
	string getCategory();
};

class Item :public Category {
private:

public:
	Item() {}
	void inputFromFile(Item*, int);
	//void Billing(int);
	void checkReorder();
	void display(Item*, int);
	void displayItem();
	int getID();
	int getQuantity();
	int getPrice();
	char* getName();
	void setQuantity(int);
	void inputCart(Item*, Item*, int, int&);
	int getCartItems(int);
	float calculateBill(Item*, int);
	float loyaltyBill(Item*, int, int);
	void displayCart(Item*, int, float);
};


#endif
