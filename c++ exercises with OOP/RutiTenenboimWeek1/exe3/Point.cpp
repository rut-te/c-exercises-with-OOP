#include "Point.h"
#include<iostream>
using namespace std;

void Point::setX(int myX)//realization Placement of parameter that expresses the X of the circle
{
	x = myX;
}

void Point::setY(int myY)//realization Placement of parameter that expresses the Y of the circle
{
	y = myY;
}

int Point::getX()//realization return of parameter that expresses the X of the circle
{
	return x;
}

int Point::getY()//realization return of parameter that expresses the Y of the circle
{
	return y;
}
