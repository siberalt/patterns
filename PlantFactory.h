#pragma once
#include "Plant.h"
#include <map>
#include <iostream>

using namespace std;

class PlantFactory
{
	map<string, Plant*> plants;
	PlantFactory(){}
	~PlantFactory(){}

	PlantFactory(PlantFactory const&); // реализация не нужна
	PlantFactory& operator= (PlantFactory const&);  // и тут

public:
	Plant* getPlant(string name,double min,double max,double humidity,string info){
		//map<string, Plant*>::iterator Iter = plants.find(name);
		//auto iter = plants.find(name);
		//if (iter == plants.end())

		Plant *plant = plants[name];
		if (plant == NULL){
			cout << "Plant \"" << name << "\" is not in the factory. Adding this to the factory\n";
			plant = new Plant(max, min, humidity, info, name);
			//plants.insert(pair<string, Plant*>(name, plant));
			plants[name] = plant;
		}
		else cout << "Plant \"" << name << "\" is already in the factory\n";
		return plant;
	}
	
	static PlantFactory* getInstance(){
		static PlantFactory plantFactory;
		return &plantFactory;
	}
};

