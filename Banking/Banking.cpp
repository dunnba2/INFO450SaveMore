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
	char answer;
	int num = 0;//resets the number of accts you want to create when using the program

	//this is where you choose the number of accounts you want to create
	cout << "How many bank accounts would you like to make? ";
	cin >> num;

	BankAcct **ptr = NULL; //double pointer list for run time polymorphism

	ptr = new BankAcct*[num]; //array of pointers so dynamically create accts

	//for loop used to iterate through pointer array for however many accts you decide to create
	for (int i = 0; i < num; i++)
	{
		//This is where you choose what type of acct you want to create.
		cout << "What type of account would you like to create? " << endl;
		cout << "For savings enter S." << endl;
		cout << "For checkings enter C." << endl;
		cout << "For certificate of deposit enter X." << endl;
		cin >> answer;

		if (answer == 's' || answer == 'S')//condition for a savings acct to be created
		{
			ptr[i] = new SavingsAcct();/*this creates a savings acct, it is also where
									   the acct number and balance are set*/

			/*used a do..while loop so that you can do as many operations to the acct you want
			 before you move onto creating a new acct*/
			do
			{
				//These are the actions that can be performed 
				cout << endl << endl;
				cout << "Deposit, enter D. " << endl;
				cout << "Withdrawal, enter W." << endl;
				cout << "Check your balance, enter C. " << endl;
				cout << "Want to know your interest rate, enter R.";
				cout << endl;
					cin >> answer;

				//Based on there response they can do different things
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
				if (answer == 'R' || answer == 'r')
				{
					ptr[i]->assessInterest();
				}

				cout << endl;
				cout << "Would you like to do anything else with this account? ";
				cin >> answer;

			} while (answer == 'Y' || answer == 'y');

			/*applies interest after user is through with operations
			done to the account.*/
			ptr[i]->applyInterest();
		}
		else if (answer == 'c' || answer == 'C') //condition for a checking acct
		{
			ptr[i] = new CheckAcct(); /*this creates a checking acct, it is also where 
									  the acct number and balance are set*/

			 /*used a do..while loop so that you can do as many operations to the acct you want
			 before you move onto creating a new acct*/
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
		else if (answer == 'X' || answer == 'x')/*This creates a certificate of deposit acct, it also sets the term, balance, acct number*/
		{
			ptr[i] = new CDAcct();/*This creates a certificate of deposit acct, 
								  it also sets the term, balance, acct number*/

			/*used a do..while loop so that you can do as many operations to the acct you want
			before you move onto creating a new acct*/
			do
			{
				cout << endl << endl;
				cout << "Deposit, enter D. " << endl;
				cout << "Withdrawal, enter W." << endl;
				cout << "Check your balance, enter C. " << endl;
				cout << "Want to know your interest rate, enter R.";
				cout << endl;
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
				if (answer == 'R' || answer == 'r')
				{
					ptr[i]->assessInterest();
				}

				cout << endl;
				cout << "Would you like to do anything else with this account? ";
				cin >> answer;

			} while (answer == 'Y' || answer == 'y');

			/*applies interest after user is through with operations 
			done to the account */
			ptr[i]->applyInterest();
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

