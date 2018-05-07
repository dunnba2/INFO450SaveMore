#ifndef BANKACCT_H
#define BANKACCT_H
#pragma once

#include "stdafx.h"
#include <string>
#include <iostream>
using namespace std;

class BankAcct
{
	//Declared base class variables that the subclasses can inherit 
protected:
	int acctNum;
	double intRate;
	double balance;
	float amount;
	string type; 
	
	//Constructors and member functions 
public:
	BankAcct();
	BankAcct(int a, double b);
	int getAcctNum();
	double getBalance();
	string getAcctType();
	int checkBalance();
	/*These are functions can be redefined within the subclasses*/
	virtual int deposit();
	virtual int withdraw();
	virtual void display();
	/*included orderChecks because the way I wrote the main function, it said 
	it wasn't defined in the base class, it's only called for checks though*/  
	virtual int orderChecks();

};

#endif
