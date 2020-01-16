#pragma once
#include <string>
#include <vector>
#include "States.cpp"
#include "IListener.h"

using namespace std;

class IDevice
{
public:
	IDevice(){}
	~IDevice(){}

	virtual DeviceInfo GetInfo() = 0;
	virtual Status GetStatus() = 0;
	virtual void TurnOn() = 0;
	virtual void TurnOff() = 0;
	virtual vector<double> execute(vector<double> v) = 0;
	virtual void handler(IListener*) = 0;
	virtual IDevice* clone() = 0;
};