#include "stdafx.h"
#include <iostream>
#include "CheckingAcct.h"


CheckAcct::CheckAcct()
{
	type = "Checking";
	fee = 5;
	cout << endl << "Type in number you'd like for your account? (Ex: 100135): ";
	cin >> acctNum;
	cout << endl << "How much would you like to deposit to begin your account?: ";
	cin >> balance;
}

CheckAcct::CheckAcct(int a, double b)
	:BankAcct(a, b)
{

}

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

int CheckAcct::orderChecks()
{
	if (balance >= 17)
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

void CheckAcct::display()
{
	cout << endl << "**** Check Account ****" << endl << endl;
	BankAcct::display();
	cout << endl;
}