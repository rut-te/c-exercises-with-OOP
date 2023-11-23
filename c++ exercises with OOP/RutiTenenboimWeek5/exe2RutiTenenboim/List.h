#pragma once
#include<iostream>
using namespace std;
//השתמשתי במחלקה שיצרתי בשאלה1
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
	void add(int value);
	int firstElement() const;
	bool search(const int& value) const;
	bool isEmpty() const;
	void removeFirst();
	void clear();
	void operator=(const List& l);
	void insert(int key);
	void remove(int key);
	friend ostream& operator<<(ostream& os, const List& l);
	friend istream& operator>>(istream& is, List& l);


private:
	// data field
	Link* head;
};






