//Ruti Tenenboim 214360778
//sadna in c++
//week 4 exe1
//������� ����� ����� ������ ������ �� �������, ������ ����� 
//������ �� ������ ������ ��������� ��������� ������� �"� �� �������� ������ �����
#include<iostream>
#include"MyString.h"
using namespace std;
int main()
{
	MyString a;//����� ����� ������ ������
	MyString b;//���
	int num;
	cin >> a;//����� ������ �
	cin >> b;//����� ������ �
	cin >> num;
	if (a > b)//����� �� ���� ��� � ��
		cout << "a>b" << endl;
	if (a < b)
		cout << "a<b" << endl;
	if (a == b)
		cout << "a=b" << endl;
	MyString newstr = b.insert(num, a.getstr());//����� ����� � ���� ����� � ��� ������� �����
	cout << newstr;
	char tav;
	cin >> tav;
	cin >> num;
	newstr[num] = tav;//����� ������ ������ ����� ����� ��� �����
	cout << newstr;

	return 0;
}

//exemple:
//  Hello
//  World
//  2
//  a < b
//	move assign
//	move ctor
//	WoHellorld
//	!
//	1
//	W!Hellorld
