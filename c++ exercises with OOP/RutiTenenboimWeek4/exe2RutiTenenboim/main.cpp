//Ruti Tenenboim 214360778
//sadna in c++
//week 4 exe2
//לבודקת היקרה- היו שתי גרסאות של תרגילים, התחלתי עם הגרסא הראשונה-שקיבלנו בסמינר,
//ואחכ שלחו לי את הגרסא המעודכנת מסמינרים אחרים, אז המשכתי לפי המעודכן
//לכן חלק מהתרגיל הוא לפי גרסא1 וחלק לפי גרסא2
//דבר זה מתבטא בפונקציות מעט שונות ובבדיקות מעט שונות בחלק מהמקומות
//צירפתי לתקיה את שתי הגרסאות של התרגילים. תודה
#include <iostream>
#include "Clock.h"
#include "Account.h"

using namespace std;

enum ACTION {
	STOP,
	BALANCE,
	DEPOSIT,
	WITHDRAW,
	SUM_DEPOSIT,
	SUM_WITHDRAW
};
ACTION menu() {
	cout << "enter 1 to get account balance" << endl;
	cout << "enter 2 to deposit money" << endl;
	cout << "enter 3 to withdraw money" << endl;
	cout << "enter 4 to see the sum of all deposits" << endl;
	cout << "enter 5 to see the sum of all withdrawals" << endl;
	cout << "enter 0 to stop" << endl;
	int x;
	cin >> x;
	return (ACTION)x;
}
int findAccount(Account* bank, int size) {
	int number, code;
	cout << "please enter account number:\n";
	cin >> number;
	int i = 0;
	while (i < size && bank[i].getAccountNumber() != number)
		i++;
	if (i >= size)
		throw "ERROR: no such account number\n";
	cout << "please enter the code:\n";
	cin >> code;
	if (bank[i].getCode() == code)
		return i;
	throw "ERROR: wrong code!\n";
}
void printTransaction(Account a, ACTION ac, Clock& c) {
	cout << c << "\t";
	switch (ac) {
	case BALANCE: cout << "account #: " << a.getAccountNumber() << "\t";
		cout << "balance: " << a.getBalance() << endl;
		break;
	case DEPOSIT:
	case WITHDRAW: cout << "account #: " << a.getAccountNumber() << "\t";
		cout << "new balance: " << a.getBalance() << endl;
		break;
	case SUM_DEPOSIT:
		cout << "sum of all deposits: " << Account::getSumDeposit() << endl;
		break;
	case SUM_WITHDRAW:
		cout << "sum of all withdrawals: " << Account::getSumWithdraw() << endl;
		break;
	}
}
void getBalance(Account* bank, int size, Clock& c) {
	int i = findAccount(bank, size);
	c += 20;
	printTransaction(bank[i], BALANCE, c);
}
void cashDeposit(Account* bank, int size, Clock& c) {
	int i = findAccount(bank, size);
	float amount;
	cout << "enter the amount of the deposit:\n ";
	cin >> amount;
	bank[i].deposit(amount);
	c += 30;
	printTransaction(bank[i], DEPOSIT, c);
}
void cashWithdraw(Account* bank, int size, Clock& c) {
	int i = findAccount(bank, size);
	float amount;
	cout << "enter the amount of money to withdraw:\n ";
	cin >> amount;
	bank[i].withdraw(amount);
	c += 50;
	printTransaction(bank[i], WITHDRAW, c);
}
void checkAccount(Account bank[], int i) {
	for (int j = 0; j < i; j++)
		if (bank[i].getAccountNumber() == bank[j].getAccountNumber())
			throw "ERROR: account number must be unique!\n";
}
int main() {
	const int SIZE = 3;
	Clock c(8, 0, 0);
	Account bank[SIZE];
	cout << "enter account number, code and email for " << SIZE << " accounts:\n";
	for (int i = 0; i < SIZE; i++) {
		try {
			cin >> bank[i];
			checkAccount(bank, i);
		}
		catch (const char* msg) {
			cout << c << '\t' << msg;
			i--;
		}
	}
	ACTION ac = menu();
	while (ac) {
		try 
		{
			switch (ac) {
			case BALANCE: getBalance(bank, SIZE, c);
				break;
			case WITHDRAW:cashWithdraw(bank, SIZE, c);
				break;
			case DEPOSIT:cashDeposit(bank, SIZE, c);
				break;
			case SUM_DEPOSIT:c += 60;
				printTransaction(bank[0], SUM_DEPOSIT, c);
				break;
			case SUM_WITHDRAW:c += 60;
				printTransaction(bank[0], SUM_WITHDRAW, c);
			}

			ac = menu();
		}
		catch (const char* error) {
			cout << c << '\t' << error << endl;
		}
	}


	return 0;
}

//exemple:
//enter account number, codeand email for 3 accounts:
//123 4444 me@gmail.com
//234 5555 you@walla.co.il
//345 6666 us@g.com
//enter 1 to get account balance
//enter 2 to deposit money
//enter 3 to withdraw money
//enter 4 to see the sum of all deposits
//enter 5 to see the sum of all withdrawals
//enter 0 to stop
//1
//please enter account number :
//123
//please enter the code :
//4444
//08 : 00 : 20
//account # : 123  balance : 0
//enter 1 to get account balance
//enter 2 to deposit money
//enter 3 to withdraw money
//enter 4 to see the sum of all deposits
//enter 5 to see the sum of all withdrawals
//enter 0 to stop
//2
//please enter account number :
//234
//please enter the code :
//5555
//enter the amount of the deposit :
//500
//08 : 00 : 50
//account # : 234  new balance : 500
//enter 1 to get account balance
//enter 2 to deposit money
//enter 3 to withdraw money
//enter 4 to see the sum of all deposits
//enter 5 to see the sum of all withdrawals
//enter 0 to stop
//3
//please enter account number :
//345
//please enter the code :
//6666
//enter the amount of money to withdraw :
//100
//08 : 01 : 40
//account # : 345  new balance : -100
//enter 1 to get account balance
//enter 2 to deposit money
//enter 3 to withdraw money
//enter 4 to see the sum of all deposits
//enter 5 to see the sum of all withdrawals
//enter 0 to stop
//4
//08:02 : 41
//sum of all deposits : 500
//enter 1 to get account balance
//enter 2 to deposit money
//enter 3 to withdraw money
//enter 4 to see the sum of all deposits
//enter 5 to see the sum of all withdrawals
//enter 0 to stop
//5
//08:03 : 42
//sum of all withdrawals : -100
//enter 1 to get account balance
//enter 2 to deposit money
//enter 3 to withdraw money
//enter 4 to see the sum of all deposits
//enter 5 to see the sum of all withdrawals
//enter 0 to stop
//0
