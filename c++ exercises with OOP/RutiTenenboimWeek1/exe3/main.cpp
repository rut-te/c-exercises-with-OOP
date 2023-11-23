//Ruti Tenenboim 214360778
//sadna in c++
//week 1 exe3
//The program includes a class of a point as well as a class of a circle. The program 
//receives details of 3 circles and prints for each circle the perimeter and the area. 
//After that, the program receives an unknown number of points until the point is
//received (0,0) for each circle, the program will print the number of points that are on or inside the circle
#include<iostream>
#include "Circle.h"
#include "Point.h"
using namespace std;
int main()
{
	cout << "enter the center point and radius of 3 circles:" << endl;
	Circle circle1;//Circle definition 1
	Circle circle2;//Circle definition 2
	Circle circle3;//Circle definition 3
	int x1, y1, radius1, x2, y2, radius2, x3, y3, radius3;//Defining points and radius for each circle
	char tav;
	cin >>tav>> x1 >>tav>> y1 >> tav>>radius1;//Receiving the details of the first circle
	while (radius1 <= 0)//Input integrity check for the radius
	{
		cout << "error" << endl;
		cin >> radius1;
	}
	cin >> tav >> x2 >> tav >> y2 >> tav >> radius2;//Receiving the details of the second circle
	while (radius2 <= 0)//Input integrity check for the radius
	{
		cout << "error" << endl;
		cin >> radius2;
	}
	cin >> tav >> x3 >> tav >> y3 >> tav >> radius3;//Receiving the details of the third circle
	while (radius3 <= 0)//Input integrity check for the radius
	{
		cout << "error" << endl;
		cin >> radius3;
	}
	circle1.setCenter(x1, y1);//Putting the data in circle 1
	circle2.setCenter(x2, y2);//Putting the data in circle 2
	circle3.setCenter(x3, y3);//Putting the data in circle 3
	circle1.setRadius(radius1);//Putting the data in circle 1
	circle2.setRadius(radius2);//Putting the data in circle 2
	circle3.setRadius(radius3);//Putting the data in circle 3
	cout << "perimeter: " << "A: " << circle1.perimeter() << " B: " << circle2.perimeter() << " C: " << circle3.perimeter() << endl;
	cout << "area: " << "A: " << circle1.area() << " B: " << circle2.area() << " C: " << circle3.area() << endl;
	cout << "enter points until (0,0):" << endl;
	int counter1=0,counter2=0, counter3=0;//Defining variables that will count the number of points that are on each circle
	Point temp;//Reference point definition
	int x=1, y=1;
	while (x != 0 || y != 0)//As long as the point (0,0) has not been captured
	{
		cin >> tav>>x>>tav>>y>>tav;//Receiving the point details
		temp.setX(x);//Entering the data
		temp.setY(y);//Entering the data
		if (x != 0 || y != 0)//If the captured point is not (0,0)
		{
			if (circle1.onInOut(temp) <= 0)//If the point is on circle 1, added to the parameter that counts the number of times of circle 1
				counter1++;
			if (circle2.onInOut(temp) <= 0)//If the point is on circle 2, added to the parameter that counts the number of times of circle 2
				counter2++;
			if (circle3.onInOut(temp) <= 0)//If the point is on circle 3, added to the parameter that counts the number of times of circle 3
				counter3++;
		}
	}
	cout << "num of points in circle: " << "A: " << counter1 << " B: " << counter2 << " C: " << counter3 << endl;
	return 0;
}

//exemple:
//enter the center pointand radius of 3 circles:
//(0, 0)3
//(1, 1)2
//(5, 5)2
//perimeter : A : 18.84 B : 12.56 C : 12.56
//area : A : 28.26 B : 12.56 C : 12.56
//enter points until(0, 0) :
//	(0, 1)
//	(1, 0)
//	(0, 4)
//	(0, 0)
//	num of points in circle : A: 2 B : 2 C : 0
