// BankAccountsProject.cpp : Defines the entry point for the console application.
/*	Fadhar J. Castillo
	CS256 C++ Programming
	Project 2: Bank Account
*/

#include "stdafx.h"
#include "BankAccount.h"
#include "CheckingAccount.h"
#include "SavingsAccount.h"
#include <iostream>
using namespace std;

double getAmount()
{
	double input = -1;
	do
	{
		cin >> input;
		if (input < 0)
		{
			cout << "Please enter a non negative amount." << endl;
		}
	} while (input < 0);
	
	return input;
}

int getChoice(int lowerBound, int upperBound)
{
	int input = -1;
	do
	{
		cin >> input;
		if (input < lowerBound || input > upperBound)
		{
			cout << "Please enter a number in the range." << endl;
		}
	} while (input < lowerBound || input > upperBound);

	return input;
}

int main()
{
	
	cout << "--------------------PolyBank---------------------" << endl;
	cout << "Enter starting amount for Savings Account: $";
	double savingsAmount = getAmount();
	cout << "Enter starting amount for Checking Account: $";
	double checkingAmount = getAmount();

	const double savingsAnnualInterestRate = 0.07;
	const double checkingAnnualInterestRate = 0.02;
	
	SavingsAccount savingsAccount(savingsAmount, savingsAnnualInterestRate);
	CheckingAccount checkingAccount(checkingAmount, checkingAnnualInterestRate);

	bool done = false;

	//Simulate 5 transactions per month
	int transactions = 1;
	while (!done)
	{
		int months = transactions % 5;
		if (months == 0)
		{
			//A month has passed, reduce fees from balance.
			savingsAccount.monthlyProc();
			checkingAccount.monthlyProc();
			cout << "\n Monthly Fees have been withdrawed from your accounts." << endl;
		}
		//UI Start
		cout << "\nChoose an accout to view options: " << endl;
		cout << "1. Savings Account \n2. Checking Account \n-->";
		int accountChoice = getChoice(1, 2);
		
		cout << " 1. Deposit \n 2. Withdraw \n 3. Diplay Monthly Account Statistics \n 4. Log Out \n-->";
		int choice = getChoice(1, 4);
		switch (choice)
		{
		//Deposit menu
		case 1:
			cout << "Enter amount to be deposited: $";
			double depositAmount;
			depositAmount = getAmount();
			if (accountChoice == 1)
			{
				savingsAccount.deposit(depositAmount);
			}
			else
			{
				checkingAccount.deposit(depositAmount);
			}
			break;
		//Withdrawal menu
		case 2:
			cout << "Enter amount to be withdrawed: $";
			double withdrawAmount, balance;
			withdrawAmount = getAmount();
			//Check which account was selected
			if (accountChoice == 1)
			{
				balance = savingsAccount.withdraw(withdrawAmount);
			}
			else
			{
				balance = checkingAccount.withdraw(withdrawAmount);
			}
			
			//Account balance is deactivated
			if (balance == -1.0)
			{
				cout << "Not enough funds deposited to withdraw such amount\n or account has been deactivated." << endl;
				cout << " Account is flagged inactive if the available balance\n is under $25.";
				cout << " Please deposit more funds to\n reactivate your account." << endl;
			}
			else{ cout << "Remaining Balance: $" << balance << endl; }
			break;
		case 3:
			if (accountChoice == 1)
			{
				cout << "----------Savings Account Statistics----------" << endl;
				cout << "Starting Balance This Month: $" << savingsAccount.getStartingBalance() << endl;
				cout << "Available Balance: $" << savingsAccount.seeBalance() << endl;
				cout << "Deposits This Month: " << savingsAccount.getNumberOfDeposits() << endl;
				cout << "Withdrawals This Month: " << savingsAccount.getNumberOfWithdrawals() << endl;
				cout << "Total Interest Earned: $" << savingsAccount.getEarnedInterest() << endl;
				cout << "Service Charges This Month: $" << savingsAccount.getServiceCharges() << endl;
				cout << "Service Charges Last Month: $" << savingsAccount.getLastMonthServiceCharges() << endl;;
			}
			else
			{
				cout << "----------Checking Account Statistics----------" << endl;
				cout << "Starting Balance This Month: $" << checkingAccount.getStartingBalance() << endl;
				cout << "Available Balance: $" << checkingAccount.seeBalance() << endl;
				cout << "Deposits This Month: " << checkingAccount.getNumberOfDeposits() << endl;
				cout << "Withdrawals This Month: " << checkingAccount.getNumberOfWithdrawals() << endl;
				cout << "Total Interest Earned: $" << checkingAccount.getEarnedInterest() << endl;
				cout << "Service Charges This Month: $" << checkingAccount.getServiceCharges() << endl;
				cout << "Service Charges Last Month: $" << checkingAccount.getLastMonthServiceCharges() << endl;
			}
			break;
		case 4:
			done = true;
			break;
		}
		transactions++;
	}
    return 0;
}

