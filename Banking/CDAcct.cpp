#include "stdafx.h"
#include <iostream>
#include "CDAcct.h"


//Constructor for Certificate of Deposit acct
CDAcct::CDAcct()
{
	type = "Certificate of Deposit"; //
	term = 0;
	cout << endl;
	//This is how the acct number, balance, and term are set when a CD acct is created
	cout << "Type in the number you'd like for your account? (Ex: 100135): ";
	cin >> acctNum;
	cout << endl;
	cout << "How much would you like to deposit to begin your account?: ";
	cin >> balance;
	cout << endl;
	cout << "How long would you like this account to be open? ";
	cin >> term;
}


CDAcct::CDAcct(int a, double b, int t)
	:BankAcct(a, b)
{
	t = term;
}

//deposit method used for CD acct
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

//This assess interest method uses the term as the parameter
double CDAcct::assessInterest()
{
	if (term < 5)
	{
		//applies 5% monthly interest for CD accts with a term under 5 years
		balance = balance * (1 + (.05 / 12));
	}
	else
	{
		//For CD accts that are 5 years or longer get 10% monthly interest
		balance = balance * (1 + (.1 / 12));
	}

	cout << endl;
	cout << "Your balance after interest is $" << balance << endl;
	return 0;
}

//Display method called for CD accts modified to include the term length
void CDAcct::display()
{
	cout << endl << "****" << type << " Account****" << endl;
	cout << endl << "Term: " << term << endl;
	BankAcct::display();
	cout << endl;
}