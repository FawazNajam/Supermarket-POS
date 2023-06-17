#ifndef Customer_H
#define Customer_H
#include <string>

class Customer {
protected:
	int customerID;
	char cName[20];
	string phoneNum;
	string cPassword;
	int loyaltyPoint;
public:
	int getPoints();
	void resetPoints(float);
	void addPoints(float);
	void inputData(ifstream&);
	int customerLogin(Customer*, int);
	void writeToFile(Customer*, int);
	void addCustomer(Customer*, int&, float);
};


#endif
