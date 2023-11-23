#include "Clock.h"

Clock::Clock()
{
	hour = 0;
	minute = 0;
	second = 0;
}

Clock::Clock(int myhour, int myminute, int mysecond)
{
	if (myhour < 0 || myhour>23 || myminute < 0 || myminute>59 || mysecond < 0 || mysecond>59)
	{
		hour = 0;
		minute = 0;
		second = 0;
		throw "Wrong time format";
	}
	else {
		hour = myhour;
		minute = myminute;
		second = mysecond;
	}

}

Clock::Clock(const Clock& temp)
{
	hour=temp.hour;
	minute = temp.minute;
	second = temp.second;
}

int Clock::getHour()
{
	return hour;
}

int Clock::getMinute()
{
	return minute;
}

int Clock::getSecond()
{
	return second;
}

void Clock::setHour(int myhour)
{
	if (myhour < 0 || myhour>23)
	{
		hour = 0;
		if (myhour < 0)
			throw "Invalid time - negative number of hours";
		else
			throw "Invalid time - more than 24 hours";
	}
	else
		hour = myhour;
}

void Clock::setMinute(int myminute)
{
	if (myminute < 0 || myminute>59)
	{
		minute = 0;
		if (myminute < 0)
			throw "Invalid time - negative number of minutes";
		else
			throw "Invalid time - more than 60 minutes." ;
	}
	else
		minute = myminute;
}

void Clock::setSecond(int mysecond)
{
	if (mysecond < 0 || mysecond>59)
	{
		second = 0;
		if (mysecond < 0)
			throw  "Invalid time - negative number of seconds";
		else
			throw  "Invalid time - more than 60 seconds";
	}
	else
		second = mysecond;
}

void Clock::operator+=(const int& num)
{
	second += num;
	if (second > 59)
	{
		second -= 59;
		minute++;
		if (minute > 59)
		{
			minute -= 59;
			hour++;
			if (hour > 23)
			{
				hour -= 23;
			}
		}

	}
}

ostream& operator<<(ostream& os, const Clock num)
{
	if (num.hour < 10)
	{
		os << 0;
		os << num.hour;
	}
	else
	{
		os << num.hour;
	}
	os << ":";
	if (num.minute < 10)
	{
		os << 0;
		os << num.minute;
	}
	else
	{
		os << num.minute;
	}
	os << ":";
	if (num.second < 10)
	{
		os << 0;
		os << num.second;
	}
	else
	{
		os << num.second;
	}
	os << endl;
	return os;
}

istream& operator>>(istream& is,  Clock& num)
{
	
		int myhour, myminute, mysecond;
		is >> myhour;
		char slash;
		is >> slash;
		is >> myminute;
		is >> slash;
		is >> mysecond;
		if (myhour < 0 || myhour>23 || myminute < 0 || myminute>59 || mysecond < 0 || mysecond>59)
		{
			num.hour = 0;
			num.minute = 0;
			num.second = 0;
			throw "Wrong time format";
		}
		else
		{
			num.hour = myhour;
			num.minute = myminute;
			num.second = mysecond;
		}
		return is;
	
}
