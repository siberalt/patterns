#pragma once
#include <stdio.h>
#include <vector>
#include "IDevice.h"

using namespace std;

enum ItemType{
	_Group,
	_SensorDevice,
	_ExecuteDevice,
	_Device,
	_Undefined,
	_AdditionalDevice
};

class IComponent
{
protected:
	static int sec;
	int id;
public:
	IComponent(){
		id = sec++;
	}
	~IComponent(){}

	virtual vector<double> execute(int id,vector<double> v) = 0;
	virtual vector<double> execute(vector<double> v) = 0;
	virtual ItemType getType() = 0;
	virtual void setId(int id) = 0;
	virtual int getId() = 0;
	virtual string getDescription() = 0;
	virtual bool Turn(bool turn) = 0;
	virtual bool Turn(int id, bool turn) = 0;
	virtual bool addChild(IComponent* comp) = 0;
	virtual bool addChild(int id,IComponent* comp) = 0;
	virtual bool removeChild(int id) = 0;
	virtual IComponent* getChild(int id) = 0;
	virtual void Display(int sh) = 0;
	virtual double getPowerConsumption(int) = 0;
	virtual double getPowerConsumption() = 0;
};


