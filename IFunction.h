#pragma once
class IFunction
{
	
public:
	virtual double calculate(double x) = 0;
	IFunction();
	~IFunction();
};

