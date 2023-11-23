//Ruti Tenenboim 214360778
//sadna in c++
//week 4 exe1
//התוכנית מכילה מחלקה שמבצעת פעולות על מחרוזות, המחלקה לקוחה 
//מהמצגת של השיעור בתוספת אופרטורים ופונקציות שהוספתי ע"י מה שהתבקשתי להוסיף בשאלה
#include<iostream>
#include"MyString.h"
using namespace std;
int main()
{
	MyString a;//הגדרת משתנה מטיפוס המחלקה
	MyString b;//כנל
	int num;
	cin >> a;//קריאה למשתנה א
	cin >> b;//קריאה למשתנה ב
	cin >> num;
	if (a > b)//בדיקה מה היחס בין א לב
		cout << "a>b" << endl;
	if (a < b)
		cout << "a<b" << endl;
	if (a == b)
		cout << "a=b" << endl;
	MyString newstr = b.insert(num, a.getstr());//הוספת משתנה א לתוך משתנה ב החל מהמיקום שנשלח
	cout << newstr;
	char tav;
	cin >> tav;
	cin >> num;
	newstr[num] = tav;//שינוי המשתנה במיקום שנשלח להיות התו שנקלט
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
