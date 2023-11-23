#include "MyDate.h"
#include <iostream>
using namespace std;

MyDate::MyDate(int myday, int mymonth, int myyear)//constructor
{
	if (myday > 30 || myday < 1)//check if the month is good
	{
		cout << "Error day" << endl;
		day = 1;
	}
	else//In case the input is incorrect
		day = myday;
	if (mymonth > 12 || mymonth < 1)//check if the month is good
	{
		cout << "Error month" << endl;
		month = 1;
	}
	else//In case the input is incorrect
		month = mymonth;
	if (myyear > 2099 || myyear < 1920)//check if the year is good
	{
		cout << "Error year" << endl;
		year = 1;
	}
	else//In case the input is incorrect
		year = myyear;
}

MyDate::MyDate(const MyDate& temp)//copy constructor
{
	day = temp.day;
	month = temp.month;
	year = temp.year;
}

MyDate::MyDate(const MyDate&& temp)//move constructor
{
	day = temp.day;
	month = temp.month;
	year = temp.year;
}

void MyDate::setDte(int myday, int mymonth, int myyear)//function for set the details
{
	if (myday > 0 && myday < 31 && mymonth>0 && mymonth < 13 && myyear>1919 && myyear <= 2099)
	{
		day = myday;
		month = mymonth;
		year = myyear;
	}
}

MyDate MyDate::operator++()//operator ++ in the start
{
	
	day++;
	if (day > 30)//Check if a day should pass
	{
		month++;
		day = 1;
	}
	if (month > 12)//Check if a month should pass
	{
		year++;
		month = 1;
	}
	if (year > 2099)//Checking if the year is too big
	{
		day = 1;
		month = 1;
		year = 1920;
	}
	return *this;//Returning the promoted date
}

MyDate MyDate::operator++(int notused)//operator ++ in the end
{
	//Like ++ only return the previous date and not the date we advanced
	MyDate newDate(day, month, year);
	day++;
	if (day > 30)//Check if a day should pass
	{
		month++;
		day = 1;
	}
	if (month > 12)//Check if a month should pass
	{
		year++;
		month = 1;
	}
	if (year > 2099)//Checking if the year is too big
	{
		day = 1;
		month = 1;
		year = 1920;
	}
	return newDate;
}

void MyDate::operator+=(const int& num)//operator+=
{
	day+=num;//add to the day
	if (day > 30)//Check if a day should pass
	{
		month++;
		day = 1;
	}
	if (month > 12)//Check if a month should pass
	{
		year++;
		month = 1;
	}
	if (year > 2099)//Checking if the year is too big
	{
		day = 1;
		month = 1;
		year = 1920;
	}
	setDte(day, month, year);//Put the date
}

bool MyDate::operator>(const MyDate& date) const//operator >
{
	if (year > date.year)//If the year is greater
		return true;
	if (year == date.year)//If the year is equal
	{
		if (month > date.month)//If the month is greater
			return true;
		if (month == date.month)//If the month is equal
		{
			if (day > date.day)//If the day is greater
				return true;
		}
	}
	return false;
}

bool MyDate::operator<(const MyDate& date) const//operator <
{
	if (year < date.year)
		return true;
	if (year == date.year)
	{
		if (month < date.month)
			return true;
		if (month == date.month)
		{
			if (day < date.day)
				return true;
		}
	}
	return false;
}

bool MyDate::operator==(const MyDate& date) const//operator ==
{
	if (day == date.day && month == date.month && year == date.year)
		return true;
	return false;
}

void MyDate::print()//print the details
{
	cout << day << "/" << month << "/" << year << endl;
}
