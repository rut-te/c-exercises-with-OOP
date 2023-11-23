#pragma once
#include<iostream>
using namespace std;
class List
{
private:
	class Link
	{
	public:
		// constructor
		Link(int linkValue, Link* nextPtr);
		Link(const Link&);
		// data areas
		int value;
		Link* next;
	};	//end of class Link
public:
	// constructors
	List();
	List(const List&);
	~List();

	// operations
	void add(int value);//הוספה להתחלה
	int firstElement() const;//בדיקה מיהו האיבר הראשון
	bool search(const int& value) const;//בדיקה אם ערך קיים ברשימה
	bool isEmpty() const;//בדיקה אם הרשימה ריקה
	void removeFirst();//מחיקת האיבר הראשון
	void clear();//ניקוי הרשימה
	void operator=(const List& l);//אופרטור השמה
	void insert(int key);//הוספת איבר
	void remove(int key);//מחיקת איבר
	friend ostream& operator<<(ostream& os,const List& l);//אופרטור הדפסה
	friend istream& operator>>(istream& is,  List& l);//אופרטור הכנסה

private:
	// data field
	Link* head;
};




