#include "stdafx.h"
#include <iostream>
#include "SavingsAcct.h"


SavingsAcct::SavingsAcct()
{
	type = "Savings";
	fee = 0;
	cout << endl;
	cout << "Type in number you'd like for your account? (Ex: 100135): ";
	cin >> acctNum;
	cout << endl << "How much would you like to deposit to begin your account?: ";
	cin >> balance;
}

SavingsAcct::SavingsAcct(int a, double b)
	:BankAcct(a, b)
{

}

int SavingsAcct::deposit()
{
	float amount = 0;

	cout << endl;
	cout << "Current Balance: $" << balance << endl << endl;
	cout << "How much would you like to deposit? ";
	cin >> amount;

	balance += amount;

	SavingsAcct::assessInterest();

	return 0;
}

int SavingsAcct::withdraw()
{
	float amount = 0;
	
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
		balance -= (amount + 2);
		return 0;
	}
}

double SavingsAcct::assessInterest()
{
	if (balance < 10000)
	{
		balance = balance * (1 + (.01 / 12));
	}
	else
	{
		balance = balance * (1 + (.02 / 12));
	}
	
	cout << endl;
	cout << "Your balance after interest is $" << balance << endl;

	return 0;
}

void SavingsAcct::display()
{
	cout << endl << "**** Savings Account ****" << endl << endl;
	BankAcct::display();
	cout << endl;

}