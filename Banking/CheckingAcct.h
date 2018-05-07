#pragma once
#include "stdafx.h"
#include <string>
#include "BankAcct.h"


class CheckAcct :public BankAcct
{
private:
	double fee;

	//Constructors and methods for Checking Acct class
public:
	CheckAcct();
	CheckAcct(int a, double b);
	int withdraw();
	int orderChecks();
	void display();
};
