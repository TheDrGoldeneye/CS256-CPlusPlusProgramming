/*	Fadhar J. Castillo	
	CS 256 C++ Programming
	PreferredCustomer Class*/

#include "stdafx.h"
#include <string>
#include <iostream>
#include<cstdlib>
#include<ctime>
#include "PersonData.h"
#include "CustomerData.h"
#include "PreferredCustomer.h"

using namespace std;

int main()
{
	string fn, ln, addr, city, state, phone;
	int zip = -1;
	double amount = -1.0;
	
	cout << "Please enter the customer's information below: " << endl;
	cout << "First name: -> " << endl;
	getline(cin, fn);
	cout << "Last name: -> " << endl;
	getline(cin, ln);
	cout << "Address: -> " << endl;
	getline(cin, addr);
	cout << "City: -> " << endl;
	getline(cin, city);
	cout << "State: -> " << endl;
	getline(cin, state);
	do {
		cout << "Zip: -> " << endl;
		cin >> zip;
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		if (zip < 0)
		{
			cout << "Invalid transaction amount. Try again." << endl;
		}
	} while (zip < 0);
	cout << "Phone number (###)###-####: -> " << endl;
    getline(cin, phone);
	cout << endl;
	do {
		cout << "Enter the amount for this transaction: -> " << endl;
		cin >> amount;
		if (amount < 0)
		{
			cout << "Invalid transaction amount. Try again." << endl;
		}
	} while (amount < 0);

	srand(time(0));
	int customerNumber = rand()/ RAND_MAX * 50000 + 1;
	PreferredCustomer pf(ln, fn, addr, city, state, zip, phone, customerNumber, false, amount);

	cout << endl;
	cout << "----------------Customer's Information---------------" << endl;
	cout << "Name:		" << pf.getFirstName() << " " << pf.getLastName() << endl;
	cout << "Address:	" << pf.getAddress() << endl;
	cout << "		" << pf.getCity() << ", " << pf.getState() << " " << pf.getZip() << endl;
	cout << "Phone:		" << pf.getPhone() << endl;
	cout << "Customer ID:	" << pf.getCustomerNumber() << endl;
	if (pf.getMailingList() == true)
		cout <<"		In Mailing List" << endl;
	else
		cout <<"		Not in Mailing List"  << endl;
	cout << "Total Spent:	$" << pf.getPurchasesAmount() << endl;
	cout << "Discount Level: " << pf.getDiscountLevel() * 100 << "%" << endl;
	
    return 0;
}

