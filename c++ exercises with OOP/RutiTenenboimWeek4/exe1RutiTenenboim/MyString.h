#pragma once
#include <iostream>
#include <string.h>
using namespace std;
class MyString
{
	int len = 0;
	char* str;
public:
	MyString() : str(nullptr), len(0) {} //explicit empty constructor
	MyString(const char* s); //constructor
	MyString(const MyString& ms); //copy constructor
	MyString& operator=(const MyString& ms); //assignment operator
	~MyString(); //destructor
	char* getstr();//החזרת המחרוזת
	// move constructor
	MyString(MyString&& ms)noexcept;

	//move assignment operator
	MyString& operator=(MyString&& ms)noexcept;//השמה
	bool operator==(const MyString& ms) const;//השוואה
	bool operator>(const MyString& ms) const;//בדיקת אם גדול
	bool operator<(const MyString& ms) const;//בדיקה אם קטן
	bool operator>=(const MyString& ms) const;//בדיקה אם גדול שווה
	bool operator<=(const MyString& ms) const;//בדיקה אם קטן שווה
	bool operator!=(const MyString& ms) const;//בדיקה אם לא שווה
	MyString operator+(const MyString& ms) const;//+
	MyString operator* (const int) const;//*
	friend ostream& operator<<(ostream& os, const MyString& ms);//הדפסה
	friend istream& operator>>(istream& is, MyString& ms);//קליטת נתונים
	char& operator[](int index);//מיקום במערך המחרוזת
	MyString insert(int index, const char* str);//הוספת מחרוזת לתוך מחרוזת מהמיקום המבוקש

};

