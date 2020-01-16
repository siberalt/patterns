#pragma once
#include "IDevice.h"
#include <stdio.h>
#include <vector>
#include <iostream>
#include "IListener.h"

using namespace std;

class AdditionalDevice :
	public IDevice
{
protected:
	IDevice *device;
	IListener *listener;

public:
	virtual IDevice* clone(){
		return device->clone();
	}

	AdditionalDevice(IDevice *device){ this->device = device; }
	~AdditionalDevice(){}

	virtual DeviceInfo GetInfo() {
		return device->GetInfo();
	}

	virtual void handler(IListener* listener){
		this->listener = listener;
	}

	virtual Status GetStatus(){
		return device->GetStatus();
	}

	virtual void TurnOn(){
		device->TurnOn();
	}

	virtual void TurnOff(){
		device->TurnOff();
	}

	virtual vector<double> execute(vector<double> v){
		return device->execute(v);
	}
};

