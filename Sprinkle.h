#pragma once
#include "IDevice.h"
#include <stdio.h>
#include <vector>
#include <iostream>
#include "IListener.h"

using namespace std;

class Sprinkle : public IDevice
{
	State state = Offline;
	string desc;
	IListener *listener;

	Sprinkle(Sprinkle *sprinkle){
		this->desc = sprinkle->desc;
		this->listener = sprinkle->listener;
	}

public:
	IDevice* clone(){
		return new Sprinkle(this);
	}

	void handler(IListener* listener){
		this->listener = listener;
	}

	vector<double> execute(vector<double> v){
		if (state != Offline) {
			cout << "I execute sprinkle now\n";
			state = Working;
		}
		return v;
	}
	
	DeviceInfo GetInfo() {
		DeviceInfo info;
		info.description = desc;
		info.deviceType = D_Execute;
		info.deviceSubType = DS_Sprinkle;
		return info;
	}

	Status GetStatus(){
		Status status;
		switch (state){
		case Offline: status.consumption = 0; break;
		case Idle: status.consumption = 0.5; break;
		case Working: status.consumption = 4; break;
		case Initialization: status.consumption = 4; break;
		}
		status.message = "***";
		status.state = state;
		return status;
	}

	void TurnOn(){
		state = Idle;
		cout << "turning on sprinkle\n";
	}

	void TurnOff(){
		state = Offline;
		cout << "turning off sprinkle\n";
	}

	Sprinkle(string desc){
		this->desc = desc;
	}
	Sprinkle();
	~Sprinkle();
};

