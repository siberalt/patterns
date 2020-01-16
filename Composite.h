#pragma once
#include <stdio.h>
#include <vector>
#include <iostream>
#include "IDevice.h"
#include "IComponent.h"
using namespace std;

class Composite : public IComponent
{
	vector<IComponent*> children;
	string description;

public:
	Composite(string descripion) : IComponent() {
		this->description = descripion;
	}

	Composite() :IComponent(){};
	~Composite();

	vector<double> execute(int id, vector<double> v){
		vector<double> vec;
		for (IComponent *child : children) {
			vec = child->execute(id, v);
			if (vec.size() > 0)
				return vec;
		}
		return vec;
	}

	vector<double> execute(vector<double> v){
		vector<double> vec;
		for (IComponent *child : children){
			vec = child->execute(v);
			if (vec.size() > 0)
				return vec;
		}
		return vec;
	}

	ItemType getType() { return _Group; }

	void setId(int id) { this->id = id; }
	int getId(){ return id;}

	string getDescription(){ return this->description; }
	void setDescription(string desc){ this->description = desc; }

	double getPowerConsumption(int id){
		if (this->id == id)
			return getPowerConsumption();

		double sum = 0;
		for (IComponent *child : children)
			sum += child->getPowerConsumption(id);
		return sum;
	}

	double getPowerConsumption(){
		double sum = 0;
		for (IComponent *child : children)
			sum += child->getPowerConsumption();
		return sum;
	}

	bool Turn(int id,bool turn){
		if (this->id == id){
			for (IComponent *child : children)
				child->Turn(turn);
			return true;
		}
		for (IComponent *child : children)
			if (child->Turn(id, turn)) return true;
		return false;
	}

	bool Turn(bool turn){
		for (IComponent *child : children)
			child->Turn(turn);
		return true;
	}

	bool addChild(int id, IComponent *comp){
		if (this->id == id) {
			children.push_back(comp);
			return true;
		}

		for (IComponent *item : children)
			if (item->addChild(id, comp)) return true;
		return false;
	}

	bool addChild(IComponent* comp) {
		children.push_back(comp);
		return true;
	}

	IComponent* getChild(int id){
		if (this->id == id) return this;
		IComponent *res;
		for (IComponent *child : children)
			if ((res = child->getChild(id)) != NULL) return res;
		return NULL;
	}
	
	bool removeChild(int id) 
	{
		vector<IComponent*>::iterator iter = children.begin();
		while (iter != children.end()){
			if ((*iter)->getId() == id) {
				children.erase(iter);
				return true;
			}

			if ((*iter)->removeChild(id)){
				return true;
			}
			iter++;
		}
		return false;
	}

	void Display(int sh){
		for (int i = 0; i < sh; i++)
			cout << "\t";
		cout << "-G: ID = "<< id <<", info = " << this->description.c_str() << "\n";
		for (IComponent *child : children)
			child->Display(sh + 1);
	}
};

