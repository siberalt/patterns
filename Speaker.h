#pragma once
#include "AdditionalDevice.h"
#include "IDevice.h"

class Speaker :
	public AdditionalDevice
{
	State state = Offline;
	string desc;
	IListener *listener;

	Speaker(Speaker *speaker) :AdditionalDevice(speaker->device){
		this->desc = speaker->desc;
		this->listener = speaker->listener;
	}
public:
	Speaker(IDevice *device) : AdditionalDevice(device){};
	Speaker(string desc,IDevice *device) : AdditionalDevice(device){
		this->desc = desc;
	};

	~Speaker();
	IDevice* clone(){
		return new Speaker(this);
	}

	DeviceInfo GetInfo() {
		DeviceInfo info;
		info.description = desc + device->GetInfo().description;
		info.deviceType = D_Additional;
		return info;
	}

	void handler(IListener* listener){
		this->listener = listener;
	}

	Status GetStatus(){
		Status status;
		switch (state){
		case Offline: status.consumption = 0; break;
		case Idle: status.consumption = 1.5; break;
		case Working: status.consumption = 3; break;
		case Initialization: status.consumption = 2; break;
		}
		status.message = "doing stuff (Speaker)\n";
		status.state = state;
		return status;
	}

	void TurnOn(){
		state = Idle;
		cout << "turning on Speaker\n";
	}

	void TurnOff(){
		state = Offline;
		cout << "turning off Speaker\n";
	}

	vector<double> execute(vector<double> v){
		if (state != Offline) {
			cout << "I am making noise (Speaker)\n";
			state = Working;
		}
		return v;
	}
};

