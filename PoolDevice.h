#pragma once
#include "Device.h"
#include <map>

using namespace std;
class PoolDevice
{
	PoolDevice();
	~PoolDevice();
	map<pair<DeviceType, DeviceSubType>,Device*> devices;
	map<pair<DeviceType, DeviceSubType>, IDevice*> adapters;

public:
	static PoolDevice* getInstance(){
		static PoolDevice pool;
		return &pool;
	}

	IDevice* getDeviceAdapter(DeviceType devType,DeviceSubType devSubType){
		return adapters[make_pair(devType, devSubType)]->clone();
	}

	void addDeviceAdapter(DeviceType devType, DeviceSubType devSubType,IDevice *adapter){
		adapters.insert(make_pair(make_pair(devType, devSubType), adapter));
	}

	Device* acquire(DeviceInfo info){
		cout << "Getting device out of pool..." << endl;
		Device *device = devices[make_pair(info.deviceType, info.deviceSubType)];
		if (device == NULL){
			IDevice *adapter = getDeviceAdapter(info.deviceType, info.deviceSubType);
			if (adapter == NULL){
				cout << " In the pool there is no appropriate adapter for this type of devices" << endl; 
				return NULL;
			}
			device = new Device(adapter);
			device->setDescription(info.description);
		}
		else devices.erase(devices.erase(devices.find(make_pair(info.deviceType, info.deviceSubType))));
		cout << "Device: " << device->getInfo().description << endl;
		return device;
	}

	void release(Device *device){
		devices.insert(make_pair(make_pair(device->getInfo().deviceType,device->getInfo().deviceSubType),device));
	}
};

