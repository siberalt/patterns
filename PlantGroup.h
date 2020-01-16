#pragma once
#include "Plant.h"
#include "PlantFactory.h"
#include <iostream>

using namespace std;

class PlantGroup
{
	string groupName;
	Plant *plant;
	int amount;
public:
	PlantGroup(string groupName,int amount, double max, double min, double humidility, string info, string name){
		cout << "Adding new plant type \"" << name << "\"\n";
		this->plant = PlantFactory::getInstance()->getPlant(name, min, max, humidility, info);
		this->groupName = groupName;
		this->amount = amount;
	}

	string getGroupName(){
		return groupName;
	}

	void setGroupName(string name){
		this->groupName = name;
	}

	~PlantGroup();
};

