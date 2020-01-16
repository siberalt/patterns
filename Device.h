#pragma once
#include <stdio.h>
#include <iostream>
#include <vector>
#include "IDevice.h"
#include "IComponent.h"
#include "IListener.h"
#include "ExternalConditions.h"
using namespace std;

class Device : public IComponent , public IListener
{
	DeviceInfo info;
	Status status;
	IDevice *device;
	ExternalConditions *conditions;
	
	vector<IListener*> listeners;
	static char states[Offline + 1][20];
	static char types[D_Additional + 2];
	bool simulate = false;

public:

	void setConditions(ExternalConditions *conditions){
		this->conditions = conditions;
		this->conditions->addHandler(this);
	}

	void setSimulate(bool simulate){
		this->simulate = simulate;
	}

	Device(IDevice *device) :IComponent(){
		setDeviceAdapter(device);
		Init();
	}

	void Init(){
		status = device->GetStatus();
		info = device->GetInfo();
	}
	~Device();

	void update(vector<double> v){
		for (IListener *el : listeners)
			el->update(v);
	}

	void setDeviceAdapter(IDevice *device){
		this->device = device;
		this->device->handler(this);
		Init();
	}

	int getId(){
		return id;
	}

	vector<double> execute(int id, vector<double> v){
		if (this->id == id) return execute(v);
		return vector<double>();
	}

	virtual vector<double> execute(vector<double> v){
		if (simulate) return vector<double>(conditions->inc());
		return device->execute(v);
	}

	void setDescription(string desc){
		info.description = desc;
	}
	
	ItemType getType(){
		return (ItemType)(_SensorDevice + info.deviceType);
	}

	void setId(int id){
		this->id = id;
	}

	string getDescription(){
		return info.description;
	}

	bool Turn(bool turn){
		if (turn) 
			device->TurnOn();
		else
			device->TurnOff();
		return true;
	}

	bool Turn(int id, bool turn){
		if (this->id == id) return Turn(turn);
		return false;
	}

	bool addChild(IComponent *comp){
		return false;
	}

	bool addChild(int id, IComponent *comp){
		return false;
	}

	bool removeChild(int id){
		return false;
	}

	double getPowerConsumption(int id){
		if (this->id == id) return getPowerConsumption();
		return 0;
	}

	double getPowerConsumption(){
		status = device->GetStatus();
		return status.consumption;
	}

	virtual DeviceInfo getInfo() {
		return info;
	}

	virtual Status getStatus() {
		return status;
	}

	IComponent* getChild(int id) {
		if (this->id == id) return this;
		return NULL;
	};
	
	virtual void Display(int sh){
		Init();
		for (int i = 0; i < sh; i++)
			cout << "\t";
		cout << "-" << types[info.deviceType] << ": ID = " << id << ", info = " << getDescription().c_str() << ", status = " << states[status.state] << ", consumption = " << status.consumption << endl;
	}

	virtual bool TurnOn(){
		device->TurnOn();
		return true;
	}

	virtual bool TurnOff(){
		device->TurnOff();
		return true;
	}

	virtual DeviceType getDeviceType() { return info.deviceType; }


};



