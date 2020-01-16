#pragma once
#include <string>

using namespace std;

enum State{
	Working,
	Idle,
	Initialization,
	Offline
};

struct Status{
	State state;
	string message;
	double consumption;
};

enum DeviceType{
	D_Sensor,
	D_Execute,
	D_Device,
	D_Undefined,
	D_Additional
};

enum DeviceSubType{
	DS_Flashlight,
	DS_Fan,
	DS_Temperature,
	DS_CoolingSystem,
	DS_Undefined,
	DS_LightSensor,
	DS_Sprinkle
};

struct DeviceInfo{
	DeviceType deviceType;
	DeviceSubType deviceSubType;
	string description;

	DeviceInfo(DeviceType type,DeviceSubType stype,string desc){
		this->deviceType = type;
		this->deviceSubType = stype;
		this->description = desc;
	}

	DeviceInfo(){

	}
};



