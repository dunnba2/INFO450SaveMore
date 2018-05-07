#pragma once
#include "stdafx.h"
#include <string>
#include "BankAcct.h"


class CDAcct :public BankAcct
{
private:
	int term;

public:
	CDAcct();
	CDAcct(int a, double b, int t);
	int deposit();
	int withdraw();
	double assessInterest();
	void display();
};
