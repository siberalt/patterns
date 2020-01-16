#pragma once
#include "IDevice.h"
#include <stdio.h>
#include <vector>
#include <iostream>
#include "IListener.h"

class LightSensor :
	public IDevice
{
	State state = Offline;
	string desc;
	IListener *listener;

	LightSensor(LightSensor *sensor){
		this->desc = sensor->desc;
		this->listener = sensor->listener;
	}

public:
	IDevice* clone(){
		return new LightSensor(this);
	}

	void handler(IListener* listener){
		this->listener = listener;
	}

	DeviceInfo GetInfo() {
		DeviceInfo info;
		info.description = desc;
		info.deviceType = D_Sensor;
		info.deviceSubType = DS_LightSensor;
		return info;
	}

	Status GetStatus(){
		Status status;
		switch (state){
		case Offline: status.consumption = 0; break;
		case Idle: status.consumption = 2.5; break;
		case Working: status.consumption = 4; break;
		case Initialization: status.consumption = 4; break;
		}
		status.message = "***";
		status.state = state;
		return status;
	}

	void TurnOn(){
		state = Idle;
		cout << "turning on light sensor.\n";
	}

	void TurnOff(){
		state = Offline;
		cout << "turning off light sensor.\n";
	}

	vector<double> execute(vector<double> v){
		if (state != Offline) { 
			cout << "I give you values of light. (LightSensor).\n"; 
			state = Working;
		}
		return vector<double>({ 2, 3, 4, 5, 4 });
	}

	LightSensor(string desc){
		this->desc = desc;
	}
	LightSensor();
	~LightSensor();
};

