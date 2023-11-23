//Ruti Tenenboim 214360778
//sadna in c++
//week 3 exe2
//The program receives a date from the user and performs various operations on it, such as adding to subtracting the equal, etc
#include <iostream>
#include "MyDate.h"
using namespace std;
int main()
{
	cout << "Enter a date:" << endl;
	int day, month, year;
	char tav;
	cin >> day >> tav >> month >> tav >> year;//date reception
	MyDate date(day, month, year);//Class placement
	date.print();//print
	int choose;
	MyDate newdate;
	cout << "Enter an action code:" << endl;
	cin >> choose;
	while (choose != -1)//A loop that allows you to perform actions on the date
	{
		switch (choose)
		{
		case 1://Placement of new date
			cout << "Enter a date" << endl;
			cin >> day >> tav >> month >> tav >> year;
			date.setDte(day, month, year);
			date.print();
			break;
		case 2://Adding a prefix ++
			(++date).print();//
			break;
		case 3://adding a final ++
			date++.print();
			break;
		case 4://Adding a number of days to the date
			cout << "Enter # days:" << endl;
			int num;
			cin >> num;
			date += num;
			date.print();
			break;
		case 5://Checking if the existing date is greater than the new date that is entered
			cout << "Enter a date:" << endl;
			cin >> day >> tav >> month >> tav >> year;
			newdate.setDte(day, month, year);
			if (date > newdate)
				cout << ">:  " << "true" << endl;
			else
				cout << ">:  " << "false" << endl;
			break;
		case 6://Checking if the existing date is smaller than a new date that is entered
			cout << "Enter a date:" << endl;
			cin >> day >> tav >> month >> tav >> year;
			newdate.setDte(day, month, year);
			if (date < newdate)
				cout <<"<:  "<<"true" << endl;
			else
				cout << "<:  " << "false" << endl;
			break;
		case 7://Checking if the existing date is the same as a new date that is entered
			cout << "Enter a date:" << endl;
			cin >> day >> tav >> month >> tav >> year;
			newdate.setDte(day, month, year);
			if (date == newdate)
				cout << "==:  " << "true" << endl;
			else
				cout << "==:  " << "false" << endl;
			break;
		}
		cout << "Enter an action code:" << endl;
		cin >> choose;
	}
	return 0;
}

//exemple:
//Enter a date :
//-5 / 1 / 2012
//Error day
//1 / 1 / 2012
//Enter an action code :
//1
//Enter a date
//5 / 7 / 2010
//5 / 7 / 2010
//Enter an action code :
//2
//6 / 7 / 2010
//Enter an action code :
//3
//6 / 7 / 2010
//Enter an action code :
//4
//Enter # days :
//	7
//	14 / 7 / 2010
//	Enter an action code :
//5
//Enter a date :
//14 / 7 / 2010
//			> :  false
//	Enter an action code :
//7
//Enter a date :
//14 / 7 / 2010
//== : true
//Enter an action code :
//6
//Enter a date :
//20 / 6 / 2011
//< : true
//	Enter an action code :
//-1
