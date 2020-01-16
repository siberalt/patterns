#pragma once
#include "IFunction.h"
class Linear :
	public IFunction
{
	double k, b;

public:
	double calculate(double x){
		return k*x + b;
	}

	Linear();
	~Linear();
};