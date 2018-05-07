#include "stdafx.h"
#include <iostream>
#include "CheckingAcct.h"

//Constructor for a checking acct
CheckAcct::CheckAcct()
{
	type = "Checking";
	fee = 5;
	//This is how the acct number and balance are set when a checking acct is created
	cout << endl << "Type in the number you'd like for your account? (Ex: 100135): ";
	cin >> acctNum;
	cout << endl << "How much would you like to deposit to begin your account?: ";
	cin >> balance;
}

CheckAcct::CheckAcct(int a, double b)
	:BankAcct(a, b)
{

}

//This method is similar to the rest but implements the fee if it drops below $500
int CheckAcct::withdraw()
{
	char answer;
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
		balance -= amount;
		
		if (balance >= 500)
		{
			return 0;
		}
		else
		{
			balance -= fee;
			return 0;
		}
	}
}

//Here's where I defined the order check method 
int CheckAcct::orderChecks()
{
	if (balance >= 17)//used 17 as the minimum that way fee wouldn't make the balance go negative
	{
		balance -= 15;
		
		cout << endl;
		cout << "Your checks have been ordered. " << endl << endl;
		cout << "Your current balance is now $" << balance << endl;

		if (balance >= 500)
		{
			return 0;
		}
		else
		{
			balance -= fee;
			return 0;
		}
	}
	else
	{
		cout << "You have insufficient funds to order checks. " << endl << endl;
		cout << "You must deposit money, then try again. " << endl;
		return -1;
	}
}

//this display method is called when a checking acct is created
void CheckAcct::display()
{
	cout << endl << "**** " << type << " ****" << endl << endl;
	BankAcct::display();//calls the bank acct class to finish off the info displayed
	cout << endl;
}