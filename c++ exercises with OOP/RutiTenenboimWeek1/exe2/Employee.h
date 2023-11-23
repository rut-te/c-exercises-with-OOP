#pragma once
class Employee
{
private:
	int id;//ID card of the employee
	char name[21];//Employee's name
	float price;//The amount the employee earns per hour
	int hours;//The number of working hours of the employee
	int sum;//The amount the employee contributed to the association
public:
	void setId(int myId);//Initialization of the employee's identity card
	int getId();//Return of the employee's ID card
	void setName(char myName[]);//Initialization of the Employee's name
	char* getName();//Return of the Employee's name
	void setPrice(float myPrice);//Initialization of the The amount the employee earns per hour
	float getPrice();// Return of the The amount the employee earns per hour
	void setHours(int myHours);//Initialization of the The number of working hours of the employee
	int getHours();//Return of the The number of working hours of the employee
	void setSum(float mySum);//Initialization of the The amount the employee contributed to the association
	int getSum();//Return of the The amount the employee contributed to the association
	float salary();//A function that calculates the employee's salary
};

