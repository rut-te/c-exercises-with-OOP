//Ruti Tenenboim 214360778
//sadna un c++
//week 2 exe 1
//The program has 2 classes, one representing a point and the other representing a polygon
//The program receives classes of points for each polygon, calculates the perimeter of the polygon, and checks between 2 polygons if they are the same
#include <iostream>
#include "Point.h"
#include "Polygon.h"
#include <cmath>
using namespace std;
int main()
{
	int num = 0,temp;
	char tav;
	Point point;//point definition
	cout << "enter number of sides:" << endl;
	cin >> num;
	while (num <= 0)
	{
		cout << "ERROR" << endl;
		cin >> num;
	}
	Polygon ribbed1(num);//Defining a polygon the size of the number of points the user selected
	cout << "enter the point values:" << endl;
	for (int i = 0; i < num; i++)//Receiving the point values and placing them
	{
		cin >> tav;
		cin >> temp;
		point.setX(temp);
		cin >> tav;
		cin >> temp;
		point.setY(temp);
		cin >> tav;
		ribbed1.addPoint(point, i);
	}
	cout << "enter number of sides:" << endl;//Likewise for the second polygon
	cin >> num;
	while (num <= 0)
	{
		cout << "ERROR" << endl;
		cin >> num;
	}
	Polygon ribbed2(num);
	cout << "enter the point values:" << endl;
	for (int i = 0; i < num; i++)
	{
		cin >> tav;
		cin >> temp;
		point.setX(temp);
		cin >> tav;
		cin >> temp;
		point.setY(temp);
		cin >> tav;
		ribbed2.addPoint(point, i);
	}
	if(ribbed1.checkIfEqual(ribbed2) == true)//Checking if the values are the same, if so, printing their circumference
	{
		float per = ribbed1.perimeter();//Keeping the scope with the values after the dot
		int per1 = ribbed1.perimeter();//Keeping the scope without the values after the dot
		if (per - per1 >= 0.5)//Check if you need to round up
			per1 = per1 + 1;
		cout << "equal" << endl;
		cout << "perimeter: " << per1 << endl;//Printing the final extent after rounding down/up
	}
	else//If the polygons are not the same, check the perimeter as for each polygon separately
	{
		float per = ribbed1.perimeter();
		int per1 = ribbed1.perimeter();
		if (per - per1 >= 0.5)
			per = per1 + 1;
		cout << "not equal" << endl;
		cout << "perimeter: " << per1 << endl;
		per = ribbed2.perimeter();
		per1 = ribbed2.perimeter();
		if (per - per1 >= 0.5)
			per1 = per1 + 1;
		cout << "perimeter: " << per1 << endl;
	}
	
	return 0;
}

//exemple1:
// 
//enter number of sides :
//4
//in one parameter constructor
//enter the point values :
//(0, 0) (0, 2) (2, 2) (2, 0)
//enter number of sides :
//3
//in one parameter constructor
//enter the point values :
//(1, 1) (2, 0) (3, 1)
//in copy constructor
//in destructor
//not equal
//perimeter : 8
//perimeter : 5
//in destructor
//in destructor


//exemple 2
// 
//enter number of sides :
//3
//in one parameter constructor
//enter the point values :
//(10, 10) (10, 14) (13, 10)
//enter number of sides :
//3
//in one parameter constructor
//enter the point values :
//(13, 10) (10, 10) (10, 14)
//in copy constructor
//in destructor
//equal
//perimeter : 12
//in destructor
//in destructor

