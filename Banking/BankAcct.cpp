#include "stdafx.h"
#include <iostream>
#include "BankAcct.h"

//Constructor for bank account
BankAcct::BankAcct()
{
	acctNum = 0;
	intRate = 0;
	apr = 0;
	balance = 0;
	amount = 0;
}

BankAcct::BankAcct(int a, double b)
{
	acctNum = a;
	balance = b;
}

//used to check the balance of whichever account calls the method
int BankAcct::checkBalance()
{
	cout << endl;
	cout << "You have $" << balance << " in your " << type << " account.";
	cout << endl;

	return 0;
}

//Base deposit method for base class
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

//Withdrawal method for base class
int BankAcct::withdraw()
{
	float amount = 0;
	cout << "Current Balance: $" << balance << endl << endl;
	cout << "How much would you like to withdraw? ";
	cin >> amount;

	if (amount > balance) //Doesn't allow the user to overdraft
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
 
double BankAcct::assessInterest()
{
	return 0;
}

double BankAcct::applyInterest()
{
	return 0;
}

//No definition for this function bc its only used by the Checking account class
int BankAcct::orderChecks()
{
	return 0;
}

//Basic way to display bank info
void BankAcct::display()
{
	cout << "Account Number: " << acctNum << endl;
	cout << "Balance: $" << balance << endl;
}


