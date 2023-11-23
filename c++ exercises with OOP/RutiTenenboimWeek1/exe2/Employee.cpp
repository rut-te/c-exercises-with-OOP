#include "Employee.h"
#include<cstring>
void Employee::setId(int myId)//realization Initialization of the employee's identity card
{
	if (myId < 0)
		id = 0;
	else
		id = myId;
}

int Employee::getId()//realization Return of the employee's ID card
{
	return id;
}

void Employee::setName(char myName[])//realization Initialization of the Employee's name
{
	strcpy_s(name,21, myName);
}

char* Employee::getName()//realization Return of the Employee's name
{
	return name;
}

void Employee::setPrice(float myPrice)//realization Initialization of the The amount the employee earns per hour
{
	if (myPrice < 0)
		price = 0;
	else
		price = myPrice;
}

float Employee::getPrice()//realization Return of the The amount the employee earns per hour
{
	return price;
}

void Employee::setHours(int myHours)//realization Initialization of the The number of working hours of the employee
{
	if (myHours < 0)
		hours = 0;
	else
		hours = myHours;
}

int Employee::getHours()//realization Return of the The number of working hours of the employee
{
	return hours;
}

void Employee::setSum(float mySum)//realization Initialization of the The amount the employee contributed to the association
{
	if (mySum < 0)
	{
		sum = 0;
	}
	else
		sum = mySum;
}

int Employee::getSum()//realization Return of the The amount the employee contributed to the association
{
	return sum;
}

float Employee::salary()//realization the function that calculates the employee's salary
{
	float basicSalary = hours * price;//Calculating the salary before adding the percentages on the amount the employee contributed to the association
	int help = sum;//Defining an auxiliary variable equal to the amount the employee contributed to the association
	float bonus=0;//Defining a variable that accumulates the amount that needs to be added to the employee
	if (sum >5000)//If the amount the employee contributed to the association is greater than 5000
	{
		bonus += (help - 5000) * 0.4;
		help -= help - 5000;
	}
	if (sum >4000)//If the amount the employee contributed to the association is greater than 4000
	{
		bonus += (help - 4000) * 0.3;
		help -= help - 4000;
	}
	if (sum > 2000)//If the amount the employee contributed to the association is greater than 2000
	{
		bonus += (help - 2000) * 0.2;
		help -= help - 2000;
	}
	if (sum > 1000)//If the amount the employee contributed to the association is greater than 1000
	{
		bonus += (help - 1000) * 0.15;
		help -= help - 1000;
	}
	if (sum > 0)//If the amount the employee contributed to the association is greater than 0
	{
		bonus += (help) * 0.1;
	}
	
	float finalSalary = basicSalary + bonus;//Calculation of the final amount
	return finalSalary;//Returning the final amount
}
