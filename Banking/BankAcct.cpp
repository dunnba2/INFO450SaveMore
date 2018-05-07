#include "stdafx.h"
#include <iostream>
#include "BankAcct.h"


BankAcct::BankAcct()
{
	acctNum = 0;
	intRate = 0;
	balance = 0;
	amount = 0;
}

BankAcct::BankAcct(int a, double b)
{
	acctNum = a;
	balance = b;
}

int BankAcct::getAcctNum()
{
	return acctNum;
}

double BankAcct::getBalance()
{
	return balance;

}

int BankAcct::checkBalance()
{
	cout << endl;
	cout << "You have $" << balance << " in your " << type << " account.";
	cout << endl;

	return 0;
}
string BankAcct::getAcctType()
{
	return type;
}

int BankAcct::deposit()
{
	float amount = 0;
	cout << endl;
	cout << "Current Balance: $" << balance << endl << endl;
	cout << "How much would you like to deposit? ";
	cin >> amount; 

	balance += amount;

	return 0;
}

int BankAcct::withdraw()
{
	float amount = 0;
	cout << "Current Balance: $" << balance << endl << endl;
	cout << "How much would you like to withdraw? ";
	cin >> amount;

	if (amount > balance)
	{
		cout << "You have insufficient funds!!" << endl;
		return -1;
	}	
	else
	{
		balance -= amount;
		return 0;
	}		
}

int BankAcct::orderChecks()
{
	return 0;
}

void BankAcct::display()
{
	cout << "Account Number: " << acctNum << endl;
	cout << "Balance: $" << balance << endl;
}


