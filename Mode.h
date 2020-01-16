#pragma once
#include "IComponent.h"
#include "PlantGroup.h"
#include "IListener.h"
#include <iostream>

using namespace std;

class Mode : IListener
{
	PlantGroup *parent;
	IComponent *comp;

public:
	Mode(IComponent *comp,PlantGroup *group){
		this->parent = group;
		this->comp = comp;
	}
	~Mode();

	void update(vector<double> v){
		cout << "I handle event for " << this->parent->getGroupName() << " group" << endl;
	}

	string getDescription(){
		return "standard mode";
	}

	void handle(){

	}

	void monitor(){

	}

	void execute(vector<double> v){

	}
};

