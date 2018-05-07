// Banking.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <string>
#include <iostream>
#include "CDAcct.h"
#include "SavingsAcct.h"
#include "CheckingAcct.h"
using namespace std;

int main()
{
	double amount = 0;
	char answer;
	int num = 0;
	int acctNum = 0;
	double balance = 0;
	
	cout << "How many bank accounts would you like to make? ";
	cin >> num;

	BankAcct **ptr = NULL;

	ptr = new BankAcct*[num];

	for (int i = 0; i < num; i++)
	{
		
		cout << "What type of account would you like to create? " << endl;
		cout << "For savings enter s." << endl;
		cout << "For checkings enter c." << endl;
		cout << "For certificate of deposit enter x." << endl;
		cin >> answer;

		if (answer == 's' || answer == 'S')
		{
			ptr[i] = new SavingsAcct();

			do
			{
				cout << endl << endl;
				cout << "Deposit, enter D. " << endl;
				cout << "Withdrawal, enter W." << endl;
				cout << "Check your balance, enter C. " << endl;
				cin >> answer;

				if (answer == 'D' || answer == 'd')
				{
					ptr[i]->deposit();
				}
				if (answer == 'W' || answer == 'w')
				{
					ptr[i]->withdraw();
				}
				if (answer == 'C' || answer == 'c')
				{
					ptr[i]->checkBalance();
				}

				cout << endl;
				cout << "Would you like to do anything else with this account? ";
				cin >> answer;

			} while (answer == 'Y' || answer == 'y');
		}
		else if (answer == 'c' || answer == 'C')
		{
			ptr[i] = new CheckAcct();

			do
			{
				cout << endl << endl;
				cout << "Deposit, enter D. " << endl;
				cout << "Withdrawal, enter W." << endl;
				cout << "Check your balance, enter C. " << endl;
				cout << "Order checks, enter O. " << endl;
				cin >> answer;

				if (answer == 'D' || answer == 'd')
				{
					ptr[i]->deposit();
				}
				if (answer == 'W' || answer == 'w')
				{
					ptr[i]->withdraw();
				}
				if (answer == 'C' || answer == 'c')
				{
					ptr[i]->checkBalance();
				}
				if (answer == 'O' || answer == 'o')
				{
					ptr[i]->orderChecks();
				}

				cout << endl;
				cout << "Would you like to do anything else with this account? ";
				cin >> answer;

			} while (answer == 'Y' || answer == 'y');
		}
		else if (answer == 'X' || answer == 'x')
		{
			ptr[i] = new CDAcct();

			do
			{
				cout << endl << endl;
				cout << "Deposit, enter D. " << endl;
				cout << "Withdrawal, enter W." << endl;
				cout << "Check your balance, enter C. " << endl;
				cin >> answer;

				if (answer == 'D' || answer == 'd')
				{
					ptr[i]->deposit();
				}
				if (answer == 'W' || answer == 'w')
				{
					ptr[i]->withdraw();
				}
				if (answer == 'C' || answer == 'c')
				{
					ptr[i]->checkBalance();
				}

				cout << endl;
				cout << "Would you like to do anything else with this account? ";
				cin >> answer;

			} while (answer == 'Y' || answer == 'y');
		}	
	}

	for (int i = 0; i < num; i++)
	{
		ptr[i]->display();
	}

	for (int i = 0; i < num; i++)
	{
		delete ptr[i];
	}
	delete[] ptr;


    return 0;
}

