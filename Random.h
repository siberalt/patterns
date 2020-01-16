#pragma once
#include "IFunction.h"
#include <iostream>
class Random :
	public IFunction
{
	double left = 0;
	double right = 0;

public:
	void setRange(double left,double right){
		this->left = left;
		this->right = right;
	}

	double calculate(double x){
		return left + rand() % (int)right;
	}

	Random();
	~Random();
};

