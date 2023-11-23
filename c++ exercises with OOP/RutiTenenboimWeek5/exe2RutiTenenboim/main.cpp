//Ruti Tenenboim 214360778
//sadna in c++
//Week 5 exe2
//���� ������� ����� 1 ������ �������� �������� ������� �����, ����� ����� ������ ������ �������
#include <iostream>
#include "List.h"
using namespace std;
void makeSet(List &l);//������� ������ ������ ������ ������
void reverse(List &l);//������� ������ ��� ������� ������
List merge(const List& lst1, const  List& lst2);//������� ������ 2 ������ ������ ���

int main()
{
	//������� ������� ������ ������ ���� ������
	List lst1, lst2, mergedList;

	cout << "enter sorted values for the first list:" << endl;
	cin >> lst1;
	cout << "enter sorted values for the second list:" << endl;
	cin >> lst2;

	mergedList = merge(lst1, lst2);
	cout << "the new merged list: " << mergedList << endl;
	makeSet(mergedList);
	cout << "the new merged set: " << mergedList << endl;
	reverse(mergedList);
	cout << "the new merged reverse: " << mergedList << endl;

	return 0;
}
void makeSet(List &l)//������� ������ ������ ������ ������
{
	List l2;//����� ����� ����
	int temp;
	l2.add(l.firstElement());//����� ����� ������ ������� ������� ������ �����
	temp = l.firstElement();//����� ����� ������ ������ �������
	l.removeFirst();//����� ����� ������ ������ �������
	while (!l.isEmpty())//�� ��� ������ ������� �� ����
	{
		if((l.firstElement())!=temp)//�� ����� ������ �� ���� ����� ����� ��
			l2.insert(l.firstElement());//����� �� ����� ������ ������ �����
		temp = l.firstElement();//����� ����� ������ ������ �����
		l.removeFirst();//����� ����� ������� ������
	}
	l = l2;//���� ������ ������� �� ������ �����
}
void reverse(List &l)//������� ������ ��� ������� ������
{
	List l2;//����� ����� ����
	if (!l.isEmpty())//�� ������ ������� �� ����
	{
		l2.add(l.firstElement());//����� ����� ������ ������� ������� ������ �����
		l.removeFirst();//����� ������� �������
	}
	while (!l.isEmpty())//�� ��� ������ ������� �� ����
	{	
		l2.add(l.firstElement());//����� ����� ������ ������� ������� ������ �����
		l.removeFirst();//����� ������� �������
	}
	l = l2;//���� ������ ������� �� ������ �����
}
List merge(const List& lst1, const  List& lst2)//������� ������ 2 ������ ������ ���
{
	List newlst, newlst1(lst1), newlst2(lst2);
	if (!newlst1.isEmpty())//�� ����� 1 �� ����
	{
		newlst.add(newlst1.firstElement());//����� ����� ������ ������ 1 ������ �����
		newlst1.removeFirst();//����� ����� ������ 1
	}
	while (!newlst1.isEmpty())//�� ��� ����� 1 �� ����
	{
		newlst.insert(newlst1.firstElement());//����� ����� ������ ������ 1 ������ �����
		newlst1.removeFirst();//����� ����� ������ 1
	}
	while (!newlst2.isEmpty())//�� ��� ����� 2 �� ����
	{
		newlst.insert(newlst2.firstElement());//����� ����� ������ ������ 2 ������ �����
		newlst2.removeFirst();//����� ����� ������ 2
	}
	return newlst;//����� ������ �����
}

//exemple:
/*
enter sorted values for the first list :
9 5 3 1 6
enter sorted values for the second list :
8 5 4 2 1 9
the new merged list : 9 8 5 5 4 3 2 1 1

the new merged set : 9 8 5 4 3 2 1

the new merged reverse : 1 2 3 4 5 8 9
*/
