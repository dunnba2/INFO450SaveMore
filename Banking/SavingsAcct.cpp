#include "stdafx.h"
#include <iostream>
#include "SavingsAcct.h"


//Constructor for Savings acct
SavingsAcct::SavingsAcct()
{
	type = "Savings";
	fee = 2;

	//This is how the acct number and balance are set when a savings acct is created
	cout << endl;
	cout << "Type in the number you'd like for your account? (Ex: 100135): ";
	cin >> acctNum;
	cout << endl;
	cout << "How much would you like to deposit to begin your account?: ";
	cin >> balance;
}

SavingsAcct::SavingsAcct(int a, double b)
	:BankAcct(a, b)
{

}

//Deposit method for savings acct
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

//This withdrawal method is modified to apply the fee for withdrawing for savings
int SavingsAcct::withdraw()
{
	float amount = 0;
	
	cout << endl;
	//displays current balance for user so they can decide how much to withdraw
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
		balance -= (amount + fee);
		return 0;
	}
}

/*Method used to assess interest rate before it is applied*/
double SavingsAcct::assessInterest()
{
	double apr;
	
	if (balance < 10000)
	{
		apr = 1;
		intRate = .01 / 12;
		cout << endl;
		cout << "Interest rate (APR): " << apr << "%";
		cout << endl;
		cout << "Monthly Interest: " << intRate << "%";
		cout << endl;
	}
	else
	{
		apr = 2;
		intRate = .02 / 12;
		cout << endl;
		cout << "Interest rate (APR): " << apr << "%";
		cout << endl;
		cout << "Monthly Interest: " << intRate << "%";
		cout << endl;
	}

	return 0;
}

//method used to apply interest to savings acct
double SavingsAcct::applyInterest()
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

//Display method called for a savings acct
void SavingsAcct::display()
{
	cout << endl << "**** " << type << " Account ****" << endl << endl;
	BankAcct::display();
	SavingsAcct::assessInterest();
	cout << endl;
	
}