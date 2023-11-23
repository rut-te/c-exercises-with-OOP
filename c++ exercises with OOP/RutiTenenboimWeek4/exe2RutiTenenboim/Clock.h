#pragma once
#include <iostream>
using namespace std;
#include <ostream>
#include <istream>

class Clock
{
private:
	int hour=0;
	int minute=0;
	int second=0;
public:
	Clock();
	Clock(int hour=0, int minute=0, int second=0);
	Clock(const Clock& temp);//copy constructor
	int getHour();
	int getMinute();
	int getSecond();
	void setHour(int myhour);
	void setMinute(int myminute);
	void setSecond(int mysecond);
	void operator+=(const int& num);//operator+=
	friend ostream &operator<<(ostream& os, const Clock num);
	friend istream &operator>>(istream& is,  Clock& num);
};

