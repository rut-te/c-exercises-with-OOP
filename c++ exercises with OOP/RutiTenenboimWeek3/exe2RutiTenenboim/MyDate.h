#pragma once
class MyDate
{
private:
	int day;
	int month;
	int year;
public:
	MyDate(int myday = 1, int mymonth = 1, int myyear = 1920);//constructor
	MyDate(const MyDate& temp);//copy constructor
	MyDate(const MyDate&& temp);//move constructor
	void setDte(int myday , int mymonth , int myyear );//function for set the details
	MyDate operator++();//operator ++ in the start
	MyDate operator++(int notused);//operator ++ in the end
	void operator+=(const int& num);//operator+=
	bool operator>(const MyDate& num) const;//operator >
	bool operator<(const MyDate& num) const;//operator <
	bool operator==(const MyDate& num) const;//operator ==
	void print();//print the details
};

