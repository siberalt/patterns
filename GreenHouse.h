#pragma once  
#include "Plant.h"
#include "IComponent.h"
#include <vector>
#include "PlantGroup.h"

using namespace std;

class GreenHouse
{
	double Square = 0;
public:

	GreenHouse();
	~GreenHouse();

	virtual int CreateConnection(char) = 0;
	virtual void Start() = 0;
	virtual void AddPlantGroup(PlantGroup*) = 0;
	virtual void RemovePlantGroup(int) = 0;
	virtual void AddComponent(int, IComponent*) = 0;
	virtual void AddComponent(IComponent*) = 0;
	virtual void ShowDevices() = 0;
	virtual void RemoveComponent(int) = 0;
	virtual void Turn(bool) = 0;
	virtual void Turn(int, bool) = 0;
	virtual double GetPowerConsumption(int) = 0;
	virtual double GetPowerConsumption() = 0;
	//virtual vector<double> Execute(vector<double>) = 0;
	//virtual vector<double> Execute(int,vector<double>) = 0;
};

