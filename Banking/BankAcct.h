#ifndef BANKACCT_H
#define BANKACCT_H
#pragma once

#include "stdafx.h"
#include <string>
#include <iostream>
using namespace std;

class BankAcct
{
protected:
	int acctNum;
	double intRate;
	double balance;
	float amount;
	string type;
	
public:
	BankAcct();
	BankAcct(int a, double b);
	int getAcctNum();
	double getBalance();
	string getAcctType();
	int checkBalance();
	virtual int deposit();
	virtual int withdraw();
	virtual void display();
	virtual int orderChecks();

};

#endif
