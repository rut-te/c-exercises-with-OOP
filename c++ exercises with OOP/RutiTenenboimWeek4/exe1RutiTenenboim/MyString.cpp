#include "MyString.h"
#include<iostream>
using namespace std;
MyString::MyString(const char* s)
{
	len = strlen(s);
	if (s)
	{
		str = new char[len + 1];
		strcpy_s(str, len + 1, s);
	}
	else
		str = nullptr;
}
MyString::MyString(const MyString& ms)
{
	if (ms.str)
	{
		str = new char[len + 1];
		strcpy_s(str, len + 1, ms.str);
	}
	else
		str = nullptr;
	len = strlen(ms.str);
}
MyString& MyString::operator=(const MyString& ms)
{
	if (str)
		delete[] str;
	if (ms.str)
	{
		str = new char[ms.len + 1];
		strcpy_s(str, ms.len + 1, ms.str);
	}
	else
		str = nullptr;
	len = strlen(ms.str);
	return *this;
}
MyString::~MyString()
{
	if (str) 
		delete[] str;
	str = nullptr;
}
char* MyString::getstr()
{
	return str;
}
MyString MyString::operator*(const int num) const
{
	char* temp;
	temp = new char[len * num + 1];
	for (int i = 0; i < num; i++)
		strcpy_s(temp + i * len, len + 1, str);
	MyString s(temp);
	return s;
}
char& MyString::operator[](int index)
{
	if (index > len - 1)
		exit(0);
	else
	{
		return str[index];
	}
}
MyString MyString::insert(int index, const char* str2)
{
	MyString newstr;
	int length = strlen(str2);
	if (index > len - 1)
	{
		cout << "ERROR" << endl;
		return newstr;
	}
	else
	{
		int i,j;
		char* helpstr = new char[len + strlen(str2)];
		for (i = 0; i < index; i++)
		{
			helpstr[i] = str[i];
		}
		for (i = index, j = 0; j<length; i++, j++)
		{
			helpstr[i] = str2[j];
			
		}
		for (i = index+length,j=index; j < len; i++,j++)
		{
			helpstr[i] = str[j];
		}
		helpstr[i] = '\0';
		newstr = MyString(helpstr);
	}
	return newstr;

}
ostream& operator<<(ostream& os, const MyString& ms)
{
	if (ms.str)
		os << ms.str << endl;
	return os;
}
istream& operator>>(istream& is, MyString& ms)
{
	char help[50];
	is >> help;
	ms.len = strlen(help);
	ms.str = new char[ms.len + 1];
	strcpy_s(ms.str, ms.len + 1, help);
	return is;
}
MyString::MyString(MyString&& ms) noexcept
{
	len = ms.len;
	str = ms.str; 
	ms.str = nullptr; 
	cout << "move ctor" << endl;
}

MyString& MyString::operator=(MyString&& ms) noexcept
{
	if (str)
		delete[] str;
	len = ms.len;
	str = ms.str; 
	ms.str = nullptr; 
	cout << "move assign" << endl;;
	return *this;
}
bool MyString::operator!=(const MyString& ms) const
{
	return !(str==ms.str);
}
MyString MyString::operator+(const MyString& ms) const
{
	int sizeI = len;
	int sizeII = ms.len;
	char* temp = new char[sizeI + sizeII + 1];
	strcpy_s(temp, sizeI + 1, str);
	strcpy_s(temp + sizeI, sizeII + 1, ms.str);
	MyString x(temp);
	cout << "operator+ : " << str << endl;
	return x;
}
bool MyString::operator==(const MyString& ms) const
{
	//cout << "operator== : " << str << endl;
	if(strcmp(str, ms.str)==0)
		return true;
	return false;
}

bool MyString::operator>(const MyString& ms) const
{
	if (strcmp(str, ms.str) == 1)
		return true;
	return false;
}

bool MyString::operator<(const MyString& ms) const
{
	if (strcmp(str, ms.str) == -1)
		return true;
	return false;
}

bool MyString::operator>=(const MyString& ms) const
{
	if (strcmp(str, ms.str) == 1|| strcmp(str, ms.str)==0)
		return true;
	return false;
}

bool MyString::operator<=(const MyString& ms) const
{
	if (strcmp(str, ms.str) == -1 || strcmp(str, ms.str) == 0)
		return true;
	return false;
}
