//Ruti Tenenboim 214360778
//sadna in c++
//Week 5 exe1
//יצירת מחלקה של רשמיה מקושרת המבצעת פעולות על הרשימה
#include <iostream>
#include "List.h"
using namespace std;


enum CHOICES { EXIT, INSERT, REMOVE, ASSIGN, PRINT };

int main() {
	//השתמשתי בתוכנית הראשית הנתונה בדפי התרגיל 
	List lst;
	List lst2;
	int choice, val;

	cout << "enter the list values\n";
	cin >> lst;
	cout << "choose 0-4\n";
	cin >> choice;
	while (choice != EXIT) {
		try {
			switch (choice) {
			case INSERT:
				cout << "enter a value to insert\n";
				cin >> val;
				lst.insert(val);
				break;
			case REMOVE:
				cout << "enter a value to remove\n";
				cin >> val;
				lst.remove(val);
				break;
			case ASSIGN:
				lst2 = lst;
				cout << "list 2: " << lst2;
				cout << "list 1: ";
			case PRINT:
				cout << lst;
				break;
			default:cout << "ERROR\n";
			}
			cout << "choose 0-4\n";
			cin >> choice;
		}
		catch(const char* s) {//add try & catch
			cout << s << endl;
		}
	}
	return 0;
}

//exemple:
//enter the list values
//30 25 20 10 6 4 5
//choose 0 - 4
//4
//30 25 20 10 6 4
//choose 0 - 4
//1
//enter a value to insert
//12
//choose 0 - 4
//4
//30 25 20 12 10 6 4
//choose 0 - 4
//2
//enter a value to remove
//20
//choose 0 - 4
//4
//30 25 12 10 6 4
//choose 0 - 4
//3
//list 2: 30 25 12 10 6 4 list 1 : 30 25 12 10 6 4
//choose 0 - 4
//0

