// ParkingTicketSimulator.cpp : Defines the entry point for the console application.
/*Fadhar J.Castillo
CS 256 C++ Programming
ParkingTicketSimulator*/


#include "stdafx.h"
#include <string>
#include <iostream>
#include "ParkedCar.h"
#include "ParkingMeter.h"
#include "ParkingTicket.h"
#include "PoliceOfficer.h"

using namespace std;

int main()
{
	string make = "Aston Martin", model = "DB11", color = "Grey", licensePlate = "7XB8574";
	string policeOfficerName = "John Doe", badgeNumber = "2211";
	int minutesParked = 128;
	ParkedCar car(make, model, color, licensePlate, minutesParked);
	ParkingMeter meter(60);
	PoliceOfficer fiveO(policeOfficerName, badgeNumber);
	bool giveTicket = fiveO.inspectParkedCar(car, meter);
	
	cout << "Officer " << fiveO.getOfficerName() << " is walking down the street checking parking meters." << endl;
	if (giveTicket)
	{
		cout << "He encounters a vehicle parked on the street whose parking meter reads 'Expired'" << endl;
		cout << "He checks nearby cameras and sees that the car has been parked for " << minutesParked << endl;
		cout << "The parking meter's maximum allowed time is 60 minutes. The officer proceeds to write a citation." << endl;
		cout << "The citation reads: " << endl;
		cout << endl;
		ParkingTicket ticket(car, fiveO, meter);
		cout << ticket.printTicket() << endl;
	}
	else
	{
		cout << "The Officer does not find any illegally parked cars." << endl;
	}


    return 0;
}

