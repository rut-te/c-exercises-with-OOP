#include "Circle.h"
#include "Point.h"
#include<iostream>
using namespace std;
const float PI = 3.14;

void Circle::setCenter(int x, int y)//realization the function Placement of the center point of the circle
{
	center.setX(x);
	center.setY(y);
}

void Circle::setRadius(int myRadius)//realization the function Placement of the radius of the circle
{
	radius = myRadius;
}

Point Circle::getCenter()//realization the function return of the center point of the circle
{
	return center;
}

int Circle::getRadius()//realization the function return of the radius of the circle
{
	return radius;
}

float Circle::area()//realization the function that Calculation of the area of the circle
{
	float area = radius * radius * PI;
	return area;
}

float Circle::perimeter()//realization the function that Calculating the circumference of the circle
{
	float perimeter = (radius + radius) * PI;
	return perimeter;
}

int Circle::onInOut(Point p)//realization the function that Checks whether a point is on the circle, inside the circle or outside the circle
{
	float d = sqrt(pow(center.getX() - p.getX(), 2) + pow(center.getY() - p.getY(), 2));//Calculating the distance between the point and the center of the circle using the distance formula
	if (d == radius)//If the distance is equal to the radius the function returns 0
		return 0;
	if (d > radius)//If the distance is greater than the radius the function returns 1
		return 1;
	if (d < radius)//If the distance is less than the radius the function returns -1
		return -1;
}
