// ADPP_3.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "ProxyGreenHouse.h"
#include "Device.h"
#include "Speaker.h"
#include "LightSensor.h"
#include "Sprinkle.h"
#include "IComponent.h"
#include "IDevice.h"
#include "PlantFactory.h"
#include "PoolDevice.h"
#include "Light.h"
#include "Linear.h"

int _tmain(int argc, _TCHAR* argv[])
{

	Device *device = new Device(new LightSensor());
	ExternalConditions *conditions = new Light();
	conditions->setFunction(new Linear());
	device->setSimulate(true);
	device->setConditions(conditions);
	conditions->update(vector<double>{0,1,2,3});


	ProxyGreenHouse *house = new ProxyGreenHouse();
	house->AddPlantGroup(new PlantGroup("North group", 20, 30, 15, 7, "Very tasty", "Tomato"));
	house->AddPlantGroup(new PlantGroup("West group", 40, 30, 15, 7, "Very tasty", "Tomato"));
	house->AddPlantGroup(new PlantGroup("South group", 200, 30, 10, 4, "Very tasty", "Potato"));
	house->AddPlantGroup(new PlantGroup("Central group", 100, 30, 13, 4, "Very tasty", "Cucumber"));

	cout << endl;
	house->AddComponent(new Composite("Green house devices"));

	Composite *east_group = new Composite("East group of devices for tomatoes");
	//Добавляем адаптеры устройств в пул
	PoolDevice::getInstance()->addDeviceAdapter(D_Sensor, DS_LightSensor, new LightSensor());
	PoolDevice::getInstance()->addDeviceAdapter(D_Execute, DS_Sprinkle, new Sprinkle());

	//IDevice *dev = new LightSensor("Sensor1234");
	//добавили сенсор датчика света
	east_group->addChild(PoolDevice::getInstance()->acquire(*new DeviceInfo(D_Sensor, DS_LightSensor, "Sensor1234")));
	house->AddComponent(east_group);

	//прикрепили к нему динамик и тоже добавили
	//house->AddComponent(new Device(new Speaker("I am a speaker for ",dev)));

	Composite *west_group = new Composite("West group of devices for potatoes");
	west_group->addChild(new Device(new Sprinkle("Chinese sprinkle")));
	west_group->addChild(new Device(new LightSensor("German light sensor")));
	west_group->addChild(PoolDevice::getInstance()->acquire(*new DeviceInfo(D_Execute, DS_Sprinkle, "Chinese sprinkle")));
	west_group->addChild(PoolDevice::getInstance()->acquire(*new DeviceInfo(D_Sensor, DS_LightSensor, "German light sensor")));

	house->AddComponent(west_group);
	house->ShowDevices();

	cout << "\nEnter component ID to turn on: ";
	int id;
	cin >> id;
	cout << endl;

	house->Turn(id, true);
	cout << endl;
	house->ShowDevices();

	cout << "\nChoose component ID to calculate consumption: ";
	cin >> id;
	double cons = house->GetPowerConsumption(id);
	cout << "\nConsumption of a component with ID " << id << " is: " << cons << endl;
	return 0;
	// взлётная 33 кабинет 216. корпус 3
}

