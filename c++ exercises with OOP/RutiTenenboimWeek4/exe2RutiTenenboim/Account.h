#pragma once
#include<iostream>
#include<string>
using namespace std;
class Account
{
private:
	int accountNumber;
	int code;
	int balance;
	string mail;
	static int sumWithdraw;
	static int sumDeposit;
public:
	Account();
	Account(int myaccountNumber, int mycode, int mybalance, string mymail);
	void setMail(string mymail);
	void setBalance(int mybalance);
	int getAccountNumber();
	int getCode();
	int getBalance();
	string getMail();
	void withdraw(int nis);
	void deposit(int sheck);
	friend istream& operator>>(istream& is, Account& num);
	static int getSumWithdraw();
	static int getSumDeposit();
};

