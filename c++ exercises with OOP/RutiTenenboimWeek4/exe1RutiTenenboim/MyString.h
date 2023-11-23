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
	char* getstr();//����� �������
	// move constructor
	MyString(MyString&& ms)noexcept;

	//move assignment operator
	MyString& operator=(MyString&& ms)noexcept;//����
	bool operator==(const MyString& ms) const;//������
	bool operator>(const MyString& ms) const;//����� �� ����
	bool operator<(const MyString& ms) const;//����� �� ���
	bool operator>=(const MyString& ms) const;//����� �� ���� ����
	bool operator<=(const MyString& ms) const;//����� �� ��� ����
	bool operator!=(const MyString& ms) const;//����� �� �� ����
	MyString operator+(const MyString& ms) const;//+
	MyString operator* (const int) const;//*
	friend ostream& operator<<(ostream& os, const MyString& ms);//�����
	friend istream& operator>>(istream& is, MyString& ms);//����� ������
	char& operator[](int index);//����� ����� �������
	MyString insert(int index, const char* str);//����� ������ ���� ������ ������� ������

};

