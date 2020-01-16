#pragma once
#include "GreenHouse.h"
#include "RealGreenHouse.h"

class ProxyGreenHouse :
	public GreenHouse
{
	RealGreenHouse *subject;
public:
	int CreateConnection(char IP){
		return subject->CreateConnection(IP);
	}

	void Start(){
		subject->Start();
	}

	void AddPlantGroup(PlantGroup *group){
		subject->AddPlantGroup(group);
	}

	void RemovePlantGroup(int id){
		subject->RemovePlantGroup(id);
	}

	void AddComponent(int id, IComponent* comp){
		subject->AddComponent(id, comp);
	}

	void AddComponent(IComponent* comp){
		subject->AddComponent(comp);
	}

	void ShowDevices(){
		subject->ShowDevices();
	}

	void RemoveComponent(int id){
		subject->RemoveComponent(id);
	}

	void Turn(bool turn){
		subject->Turn(turn);
	}

	void Turn(int id, bool val){
		subject->Turn(id, val);
	}

	ProxyGreenHouse(char IP){
		subject->CreateConnection(IP);
	}

	double GetPowerConsumption(int id){
		return subject->GetPowerConsumption(id);
	}

	double GetPowerConsumption(){
		return subject->GetPowerConsumption();
	}

	ProxyGreenHouse(){
		subject = new RealGreenHouse();
	}
	~ProxyGreenHouse();
};

