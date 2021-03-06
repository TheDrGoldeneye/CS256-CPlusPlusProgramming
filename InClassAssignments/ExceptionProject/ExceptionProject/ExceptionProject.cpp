// Fadhar Jared Castillo
// CS 256 C++ Programming
// In-Class Exercise: ExceptionProject
//

#include "stdafx.h"
#include "Employee.h"
#include "ProductionWorker.h"
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	//Normal employee with no errors
	Employee emma("Emma Myers", 5125, 5, 14, 1998);
	//Normal Production worker with no errors
	ProductionWorker buck("Buck Rodgers", 1452, 9, 22, 2007, 1, 15.50);
	cout << left << setw(15) << "Employee Name:" << setw(17) << "Employee Number:" << setw(12) << "Hire Date:" << setw(7) << "Shift:" << setw(7) << "Pay Rate:" << endl;
	cout << left << setw(15) << emma.getName() << setw(17) << emma.getEmployeeNumber() << setw(12) << emma.getHireDate() << endl;
	cout << left << setw(15) << buck.getName() << setw(17) << buck.getEmployeeNumber() << setw(12) << buck.getHireDate() << setw(7) << buck.getShift() << setw(7) << buck.getHourlyPayRate() << endl;

	//New production worker creation
	string name;
	bool validEmployeeNumber = false, validShift = false, validHourlyRate = false, validMonth = false,
		validDay = false, validYear = false;
	int number, month, day, year, shift, payRate;
	ProductionWorker w;
	cout << "\nEnter employee name: -> ";
	getline(cin, name);
	w.setName(name);

	//Employee Number input
	while (!validEmployeeNumber)
	{
		cout << "Enter employee number: -> ";
		cin >> number;
		try
		{
			w.setEmployeeNumber(number);
			validEmployeeNumber = true;
		}
		catch (Employee::InvalidEmployeeNumberException)
		{
			cout << "Invalid Employee Number. Try Again." << endl;
		}
	}
	//Employee hire date input
	while (!validMonth)
	{
		cout << "Enter integer month in which this employee was hired: -> ";
		cin >> month;
		if (month > 0 && month < 12)
		{
			validMonth = true;
		}
		else
		{
			cout << "Invalid Month. Try Again." << endl;
		}
	}
	while (!validDay)
	{
		cout << "Enter integer day employee was hired: -> ";
		cin >> day;
		if (month == 2)
		{
			if (day > 0 && day <= 28)
			{
				validDay = true;
			}
			else
			{
				cout << "Invalid day in the month. Try Again." << endl;
			}
		}
		else if (month == 4 || month == 6 || month == 9 || month == 11)
		{
			if (day > 0 && day <= 30)
			{
				validDay = true;
			}
			else
			{
				cout << "Invalid day in the month. Try Again." << endl;
			}
		}
		else if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
		{
			if (day > 0 && day <= 31)
			{
				validDay = true;
			}
			else
			{
				cout << "Invalid day in the month. Try Again." << endl;
			}
		}
	}
	while (!validYear)
	{
		cout << "Enter integer year employee was hired: -> ";
		cin >> year;
		if (year > 1970 && month < 2018)
		{
			validYear = true;
		}
		else
		{
			cout << "Invalid Year. (1970-2018) Try Again." << endl;
		}
	}
	w.setHireDate(month, day, year);

	//Employee shift input
	while (!validShift)
	{
		cout << "1. Day Shift \n2. Night Shift" << endl;
		cout << "Enter employee shift: -> ";
		cin >> shift;
		try
		{
			w.setShift(shift);
			validShift = true;
		}
		catch (ProductionWorker::InvalidShiftException)
		{
			cout << "Invalid Shift. Try Again." << endl;
		}
	}
	while (!validHourlyRate)
	{
		cout << "Enter employee hourly rate: -> ";
		cin >> payRate;
		try
		{
			w.setHourlyPayRate(payRate);
			validHourlyRate = true;
		}
		catch (ProductionWorker::InvalidHourlyPayRateException)
		{
			cout << "Invalid Employee Hourly Rate. Try Again." << endl;
		}
	}
	cout << left << setw(20) << "\nEmployee Name:" << setw(17) << "Employee Number:" << setw(12) << "Hire Date:" << setw(7) << "Shift:" << setw(7) << "Pay Rate:" << endl;
	cout << left << setw(20) << emma.getName() << setw(17) << emma.getEmployeeNumber() << setw(12) << emma.getHireDate() << endl;
	cout << left << setw(20) << buck.getName() << setw(17) << buck.getEmployeeNumber() << setw(12) << buck.getHireDate() << setw(7) << buck.getShift() << setw(7) << buck.getHourlyPayRate() << endl;
	cout << left << setw(20) << w.getName() << setw(17) << w.getEmployeeNumber() << setw(12) << w.getHireDate() << setw(7) << w.getShift() << setw(7) << w.getHourlyPayRate() << endl;
	return 0;
}

