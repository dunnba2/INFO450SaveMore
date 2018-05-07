#pragma once
#include "stdafx.h"
#include <string>
#include "BankAcct.h"


class SavingsAcct :public BankAcct
{
private:
	int fee;

public:
	SavingsAcct();
	SavingsAcct(int a, double b);
	int deposit();
	int withdraw();
	double assessInterest();
	void display();
};
