// Midterm.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Human.h"
#include "Parent.h"
#include "Child.h"

int main()
{
	//Create the Simpson family
	string homerName = "Homer", margeName = "Marge";
	Parent homer(homerName, 36, 'M');
	Parent marge(margeName, 36, 'F');
	Child lisa("", 12, 'F', marge, homer);
	Child bart("", 10, 'M', marge, homer);
	Child maggie("", 3, 'F', marge, homer);
	homer.setChild(lisa);
	homer.setChild(bart);
	homer.setChild(maggie);
	marge.setChild(lisa);
	marge.setChild(bart);
	marge.setChild(maggie);
	//have March Set Maggie’s name
	marge.setChildName(2, "Maggie");
	//Have Homer set Bart and Lisa’s name
	homer.setChildName(0, "Lisa");
	homer.setChildName(1, "Bart");
	//print out Homer, Lisa, and Maggies names, age, sex and work
	cout << homer.getName() << " " << homer.getAge() << " "<< homer.getSex() << " ";
	homer.work("Safety Inspector");
	cout << endl;
	cout << lisa.getName() << " " << lisa.getAge() << " " << lisa.getSex() << " ";
	lisa.work("Student");
	cout << endl;
	cout << maggie.getName() << " " << maggie.getAge() << " " << maggie.getSex() << " ";
	maggie.work("Play");
	cout << endl;
    
	return 0;
}

