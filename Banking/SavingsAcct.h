#pragma once
#include "stdafx.h"
#include <string>
#include "BankAcct.h"


class SavingsAcct :public BankAcct
{
private:
	int fee;

	//Constructors and methods used in the Savings acct class
public:
	SavingsAcct();
	SavingsAcct(int a, double b);
	int deposit();
	int withdraw();
	double assessInterest();
	double applyInterest();
	void display();
};
