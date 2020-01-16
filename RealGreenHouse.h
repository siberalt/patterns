#pragma once
#include "GreenHouse.h"
#include <stdio.h>
#include <vector>
#include <iostream>
#include "IComponent.h"
#include "Composite.h"
#include "Device.h"
#include "PlantFactory.h"
#include "PlantGroup.h"
#include "IListener.h"

using namespace std;

class RealGreenHouse :
	public GreenHouse
{
	vector<PlantGroup*> groups;
	IComponent *devices = NULL;
	vector<IListener*> listeners;

public:
	void AddListener(IListener *listener){
		listeners.push_back(listener);
	}

	void RemoveLitener(IListener *listener){
	
	}

	void AddComponent(int group_id, IComponent *comp){
		if (devices == NULL) devices = comp;
		else devices->addChild(group_id, comp);
	}

	void AddComponent(IComponent *comp){
		if (devices == NULL) devices = comp;
		else devices->addChild(comp);
	}

	void RemoveComponent(int id){
		if (devices != NULL) devices->removeChild(id);
	}

	int CreateConnection(char IP){
		cout << "Connecting to: " << IP << "...\n";
		cout << "Connection established\n";
		return 1;
	}

	void Start(){
		devices->execute({ 1, 2, 3, 4 });
	}

	void AddPlantGroup(PlantGroup *group){
		groups.push_back(group);
	}

	void ShowDevices(){
		if (devices != NULL) devices->Display(0);
	}

	void RemovePlantGroup(int ind){	
		groups.erase(groups.begin() + ind);
	}

	void Turn(bool val){
		devices->Turn(val);
	}

	void Turn(int id,bool val){
		devices->Turn(id, val);
	}

	double GetPowerConsumption(int id){
		IComponent *cons = devices->getChild(id);
		cons->Display(0);
		return cons->getPowerConsumption();
	}

	double GetPowerConsumption(){
		devices->Display(0);
		return devices->getPowerConsumption();
	}
	
	RealGreenHouse();
	~RealGreenHouse();
};

