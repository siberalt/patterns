#pragma once
#include "IFunction.h"
#include <math.h>
class Exponential :
	public IFunction
{
	double k, b;

public:
	double calculate(double x){
		return k*exp(x) + b;
	}

	Exponential(double k,double b){
		this->k = k;
		this->b = b;
	}
	~Exponential();
};

