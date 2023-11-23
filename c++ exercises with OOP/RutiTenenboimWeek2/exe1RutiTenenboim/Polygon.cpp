#include "Polygon.h"
#include <iostream>
using namespace std;

Point* Polygon::getP()//Returning the array of vertices
{
	Point* temp = new Point[size];//Creating a new array
	for (int i = 0; i < size; i++)//Putting the values
		temp[i] = p[i];
	return temp;//Returning the new array
}

int Polygon::getSize()//Returning the number of vertices in the polygon
{
	return size;
}

void Polygon::addPoint(Point point, int index)//Adding a point to the vertex array
{
	if (index < size&&index>=0)//In the event that the requested index exists in the placement execution array
		p[index] = point;
}

float Polygon::perimeter()//Calculation of the perimeter of the polygon
{
	float sum = 0;
	for (int i = 0; i < size-1; i++)//Calculation of the distance between any 2 points except the distance between the first point recently
	{
		sum+=p[i].distance(p[i+1]);
	}
	sum += p[0].distance(p[size-1]);//Calculation of the distance between the first point recently
	return sum;//returning the distance
}

bool Polygon::checkIfEqual(Polygon ribbed)//Checking if 2 polygons are equal
{
	bool flag = false;
	if (size == ribbed.size)//Checking if the number of vertices is equal
		flag = true;
	if (flag)//If the number of vertices is equal, checking if the values of the points are equal
	{
		for (int i = 0; i < size; i++)
		{
			if (flag)
			{
				flag = false;
				for (int j = 0; j < size; j++)//Checking on each point if one of the points in the other polygon is equal to it
				{
					if (p[i].getX() == ribbed.p[j].getX() &&p[i].getY() == ribbed.p[j].getY())
					{
						flag = true;
						break;
					}
				}
			}
			else
				return false;
		}
	}
	else
		return false;
	return true;
}

Polygon::Polygon()//empty constructor
{
	size = 0;
	p = nullptr;
	cout << "in empty constructor" << endl;
}

Polygon::Polygon(int mysize)//constructor
{
	size = mysize;
	if(size>0)
		p = new Point[size];
	else
		p = new Point[2];
	cout << "in one parameter constructor" << endl;
}

Polygon::Polygon(const Polygon& temp)//copy constructor
{
	size = temp.size;
	p = new Point[size];
	for (int i = 0; i < size; i++)
		p[i] = temp.p[i];
	cout << "in copy constructor" << endl;
}

Polygon::~Polygon()//destructor
{
	if (p)
		delete p;
	cout << "in destructor" << endl;
}
