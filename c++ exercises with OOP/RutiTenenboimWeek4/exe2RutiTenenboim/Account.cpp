#include "Account.h"

int Account::sumDeposit = 0;
int Account::sumWithdraw = 0;
Account::Account()
{
	accountNumber = 0;
	code = 0;
	balance = 0;
	mail = " ";
}

Account::Account(int myaccountNumber, int mycode, int mybalance, string mymail)
{
	if (myaccountNumber < 0)
		accountNumber = 0;
	else
		accountNumber = myaccountNumber;
	if (mycode > 9999 || mycode < 1000)
	{
		code = 0;
		throw "ERROR: code must be of 4 digits!";
	}
	else
		code = mycode;
	balance = mybalance;
	if (mymail.find("@") == string::npos)
	{
		mail = " ";
		throw "ERROR: email must contain @!";
	}
	if (mymail.find(".com") != mymail.length() - 4 && mymail.find(".co.il") != mymail.length() - 6)
	{
		mail = " ";
		throw "ERROR: email must end at .com or .co.il!";
	}
	if (mymail.find(" ") != string::npos)
	{
		mail = " ";
		throw "ERROR: email must not contain a space!";
	}
	mail = mymail;
}

void Account::setMail(string mymail)
{
	if (mymail.find("@") == string::npos)
		throw "ERROR: email must contain @!";
	if (mymail.find(".com") != mymail.length() - 4 && mymail.find(".co.il") != mymail.length() - 6)
		throw "ERROR: email must end at .com or .co.il!";
	if (mymail.find(" ") != string::npos)
		throw "ERROR: email must not contain a space!";
	mail = mymail;
}

void Account::setBalance(int mybalance)
{
	balance = mybalance;
	
}

int Account::getAccountNumber()
{
	return accountNumber;
}

int Account::getCode()
{
	return code;
}

int Account::getBalance()
{
	return balance;
}

string Account::getMail()
{
	return mail;
}

void Account::withdraw(int nis)
{
	if (nis<2500 && balance>-6000)
	{
		balance -= nis;
		sumWithdraw += balance;
	}
	else
	{
		if (nis > 2500)
			throw "ERROR: cannot withdraw more than 2500 NIS!";
		else
			throw "ERROR: cannot have less than - 6000 NIS!";
	}
}

void Account::deposit(int sheck)
{
	if (sheck <= 10000)
	{
		balance += sheck;
		sumDeposit += sheck;
	}
	else
		throw "ERROR: cannot deposit more than 10000 NIS!";
}

int Account::getSumWithdraw()
{
	return sumWithdraw;
}

int Account::getSumDeposit()
{
	return sumDeposit;
}


istream& operator>>(istream& is, Account& num)
{
	int myAccount, myCode;
	string mail;
	is >> myAccount >> myCode >> mail;
	num.accountNumber = myAccount;
	if (myCode < 1000 || myCode>9999)
		throw "ERROR: wrong code!\n";
	num.code = myCode;
	num.setMail(mail);
	return is;
}
