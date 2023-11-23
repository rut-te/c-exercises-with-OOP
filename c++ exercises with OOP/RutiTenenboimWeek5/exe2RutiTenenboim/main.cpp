//Ruti Tenenboim 214360778
//sadna in c++
//Week 5 exe2
//המשך התוכנית משאלה 1 והוספת פונקציות גלובליות המבצעות מיזוג, החלפה והסרת איברים כפולים מהרשימה
#include <iostream>
#include "List.h"
using namespace std;
void makeSet(List &l);//פונקציה למחיקת איברים כפולים ברשימה
void reverse(List &l);//פונקציה להפיכת סדר האיברים ברשימה
List merge(const List& lst1, const  List& lst2);//פונקציה למיזוג 2 רשימות לרשימה אחת

int main()
{
	//השתמשתי בתוכנית הראשית הנתונה בדפי התרגיל
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
void makeSet(List &l)//פונקציה למחיקת איברים כפולים ברשימה
{
	List l2;//יצירת רשימה חדשה
	int temp;
	l2.add(l.firstElement());//העתקת האיבר הראשון מהרשמיה המקורית לרשימה החדשה
	temp = l.firstElement();//שמירת האיבר הראשון ברשמיה המקורית
	l.removeFirst();//מחיקת האיבר הראשון ברשמיה המקורית
	while (!l.isEmpty())//כל עוד הרשימה המקורית לא ריקה
	{
		if((l.firstElement())!=temp)//אם האיבר הנוכחי לא שווה לאיבר הקודם לו
			l2.insert(l.firstElement());//הכנסה של האיבר הנוכחי לרשימה החדשה
		temp = l.firstElement();//שמירת האיבר הנוכחי ברשימה החדשה
		l.removeFirst();//מחיקת האיבר מהרשימה הנתונה
	}
	l = l2;//השמה ברשימה המקורית את הרשימה החדשה
}
void reverse(List &l)//פונקציה להפיכת סדר האיברים ברשימה
{
	List l2;//יצירת רשימה חדשה
	if (!l.isEmpty())//אם הרשימה המקורית לא ריקה
	{
		l2.add(l.firstElement());//הכנסת האיבר הראשון מהרשימה המקורית לרשימה החדשה
		l.removeFirst();//מחיקה מהרשימה המקורית
	}
	while (!l.isEmpty())//כל עוד הרשימה המקורית לא ריקה
	{	
		l2.add(l.firstElement());//הכנסת האיבר הראשון מהרשימה המקורית לרשימה החדשה
		l.removeFirst();//מחיקה מהרשימה המקורית
	}
	l = l2;//השמה ברשימה המקורית את הרשימה החדשה
}
List merge(const List& lst1, const  List& lst2)//פונקציה למיזוג 2 רשימות לרשימה אחת
{
	List newlst, newlst1(lst1), newlst2(lst2);
	if (!newlst1.isEmpty())//אם רשימה 1 לא ריקה
	{
		newlst.add(newlst1.firstElement());//הכנסת האיבר הראשון ברשימה 1 לרשימה החדשה
		newlst1.removeFirst();//מחיקת האיבר מרשימה 1
	}
	while (!newlst1.isEmpty())//כל עוד רשימה 1 לא ריקה
	{
		newlst.insert(newlst1.firstElement());//הכנסת האיבר הראשון ברשימה 1 לרשימה החדשה
		newlst1.removeFirst();//מחיקת האיבר מרשימה 1
	}
	while (!newlst2.isEmpty())//כל עוד רשימה 2 לא ריקה
	{
		newlst.insert(newlst2.firstElement());//הכנסת האיבר הראשון ברשימה 2 לרשימה החדשה
		newlst2.removeFirst();//מחיקת האיבר מרשימה 2
	}
	return newlst;//החזרת הרשימה החדשה
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
