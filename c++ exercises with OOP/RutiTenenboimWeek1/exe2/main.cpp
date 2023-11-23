//Ruti Tenenboim 214360778
//sadna in c++
//week 1 exe2
//The program includes a department that contains employee details for the purpose of 
//calculating his salary. The program takes in the employee data and prints the name
//and ID number. of the employee who brought in the least amount of money to the 
//association and thus the amount he brought in. as well as the name and T.Z. of the
//employee who received the highest salary and the salary amount.
#include "Employee.h"
#include<iostream>
using namespace std;
int main()
{
	cout << "enter details, to end enter 0:" << endl;
	Employee minPrice;//Defining an employee type variable that defines the employee who brought in the least money
	Employee maxSalary;//Defining an employee type variable that defines the employee who earned the most money
	Employee person1;//Defining an employee type variable for the purpose of receiving employee data
	int id;//Changed for saving id
	char name[21];//Changed to save the employee's name
	float price;//Changed for the purpose of saving an amount that the employee earns per hour
	int hours;//Changed for the purpose of saving the number of working hours of the employee
	int sum;//Changed for the purpose of saving the amount that the employee contributed to the association
	cout << "enter id: " << endl;
	cin >> id;
	cout << "enter name: " << endl;
	cin >> name;
	cout << "enter price for hour: " << endl;
	cin >> price;
	cout << "enter hours of work: " << endl;
	cin >> hours;
	cout << "enter sum of collecting: " << endl;
	cin >> sum;
	minPrice.setId(id);//Saving the data of the first employee as the employee who brought in the least money
	minPrice.setPrice(price);
	minPrice.setName(name);
	minPrice.setHours(hours);
	minPrice.setSum(sum);
	maxSalary.setId(id);//Saving the first employee's data as the employee who earned the most money
	maxSalary.setPrice(price);
	maxSalary.setName(name);
	maxSalary.setHours(hours);
	maxSalary.setSum(sum);
	cout << "enter id: " << endl;//Continue receiving employee data
	cin >> id;
	while (id != 0)//Data reception as long as the id is not zero
	{
		cout << "enter name: " << endl;
		cin >> name;
		cout << "enter price for hour: " << endl;
		cin >> price;
		cout << "enter hours of work:: " << endl;
		cin >> hours;
		cout << "enter sum of collecting: " << endl;
		cin >> sum;
		if (id < 0 || price < 0 || hours < 0 || sum < 0)//If there is a problem of irregularity in the input of one of the fields, printing an error and re-recording the data
			cout << "ERROR" << endl;
		else//In case everything is fine
		{
			person1.setId(id);//Put the data captured in the auxiliary variable of the type of employee that I defined above
			person1.setPrice(price);
			person1.setName(name);
			person1.setHours(hours);
			person1.setSum(sum);
			if (person1.getSum() < minPrice.getSum())//Checking whether the amount brought in by the current employee is less than the amount brought in by the employee who has been saved until now as the one who brought in the least money
			{
				minPrice = person1;//Put the current employee's details in a variable that defines who brought in the least amount of money
			}
			if (person1.salary() > maxSalary.salary())//Checking whether the amount earned by the current employee is greater than the amount earned by the employee who has been kept until now as the one who earns the most money
			{
				maxSalary = person1;//Put the current employee's details in the variable that defines who earns the most money
			}
		}
		cout << "enter id: " << endl;
		cin >> id;
	}
	cout << "minimum collected: " << minPrice.getId() << " " << minPrice.getName() << " " << minPrice.getSum() << endl;
	cout << "highest salary:  " << maxSalary.getId() << " " << maxSalary.getName() << " " << maxSalary.salary() << endl;
	return 0;
}

//exemple:
//enter details, to end enter 0:
//enter id :
//444444
//enter name :
//rut
//enter price for hour :
//	30
//	enter hours of work :
//5
//enter sum of collecting :
//1500
//enter id :
//66666
//enter name :
//shevi
//enter price for hour :
//	40
//	enter hours of work::
//	7
//	enter sum of collecting :
//2000
//enter id :
//888888
//enter name :
//david
//enter price for hour :
//	10
//	enter hours of work::
//	2
//	enter sum of collecting :
//500
//enter id :
//0
//minimum collected : 888888 david 500
//highest salary : 66666 shevi 530
