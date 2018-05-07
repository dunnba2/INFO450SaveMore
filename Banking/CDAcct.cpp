#include "stdafx.h"
#include <iostream>
#include "CDAcct.h"


CDAcct::CDAcct()
{
	type = "Certificate of Deposit";
	term = 0;
	cout << endl;
	cout << "Type in number you'd like for your account? (Ex: 100135): ";
	cin >> acctNum;
	cout << endl << "How much would you like to deposit to begin your account?: ";
	cin >> balance;
	cout << endl << "How long would you like this account to be open? ";
	cin >> term;
}

CDAcct::CDAcct(int a, double b, int t)
	:BankAcct(a, b)
{
	t = term;
}

int CDAcct::deposit()
{
	float amount = 0;

	cout << endl;
	cout << "Current Balance: $" << balance << endl << endl;
	cout << "How much would you like to deposit? ";
	cin >> amount;

	balance += amount;

	CDAcct::assessInterest();

	return 0;
}

int CDAcct::withdraw()
{
	double amount = 0;

	cout << endl;
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

double CDAcct::assessInterest()
{
	if (term < 5)
	{
		balance = balance * (1 + (.05 / 12));
	}
	else
	{
		balance = balance * (1 + (.1 / 12));
	}

	cout << endl;
	cout << "Your balance after interest is $" << balance << endl;
	return 0;
}

void CDAcct::display()
{
	cout << endl << "**** Certificate of Deposit ****" << endl;
	cout << endl << "Term: " << term << endl;
	BankAcct::display();
	cout << endl;
}