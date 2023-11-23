#pragma once
#include "Point.h"

class Polygon
{
private:
	Point* p;//A pointer to an array of vertices
	int size;//The number of vertices in the polygon
public:
	Point* getP();//Returning the array of vertices
	int getSize();//Returning the number of vertices in the polygon
	void addPoint(Point point, int index);//Adding a point to the vertex array
	float perimeter();//Calculation of the perimeter of the polygon
	bool checkIfEqual(Polygon ribbed);//Checking if 2 polygons are equal
	Polygon();//empty constructor
	Polygon(int mysize);//constructor
	Polygon(const Polygon& temp);//copy constructor
	~Polygon();//destructor
};

