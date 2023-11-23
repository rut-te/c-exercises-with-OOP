#pragma once
#include "Point.h"
class Circle
{
private:
	Point center;//Defining the center point of the circle
	int radius;//Setting the radius of the circle
public:
	void setCenter(int x, int y);//Placement of the center point of the circle
	void setRadius(int myRadius);//Placement of the radius of the circle
	Point getCenter();//return of the center point of the circle
	int getRadius();//return of the radius of the circle
	float area();//function that Calculation of the area of the circle
	float perimeter();//function that Calculating the circumference of the circle
	int onInOut(Point p);//function that Checks whether a point is on the circle, inside the circle or outside the circle
};


