// Fadhar J. Castillo
// CS 256 C++ Programming 
// Quiz2
//

#include "stdafx.h"
#include <stdio.h>
#include <iostream>

using namespace std;

class Circle {
private:
	double radius;
	const double pi = 3.14159;

public:
	Circle();
	Circle(double radius);

	void setRadius(double radius);
	double getRadius();
	double getArea();
	double getDiameter();
	double getCircumference();
};

Circle::Circle()
{
	radius = 0.0;
}
Circle::Circle(double radius)
{
	this->radius = radius;
}

void Circle::setRadius(double radius)
{
	this->radius = radius;
}
double Circle::getRadius()
{
	return radius;
}
double Circle::getArea()
{
	return (pi * radius * radius);
}
double Circle::getDiameter()
{
	return (radius * 2);
}
double Circle::getCircumference()
{
	return (2 * pi * radius);
}

int main()
{
	double radius;
	cout << "Enter the radius of a circle: " << endl;
	cin >> radius;
	
	Circle circle(radius);
	cout << "The area of the circle is: " << circle.getArea() << endl;
	cout << "The diameter of the circle is: " << circle.getDiameter() << endl;
	cout << "The circumference of the circle is: " << circle.getCircumference() << endl;
	return 0;
}

