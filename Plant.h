#pragma once
#include <string>
#include <iostream>

using namespace std;

class Plant
{
	double MaxTemperature = 0;
	double MinTemperature = 0;
	double Humidility = 0;
	string info;
	string name;

public:
	double getMinT(){
		return MaxTemperature;
	}

	double getMaxT(){
		return MinTemperature;
	}

	double getHumidility(){
		return Humidility;
	}

	string getInfo(){
		return info;
	}

	string getName(){
		return name;
	}

	void Display(){
		cout << "Plant name: " << name << ", info: " << info << ", humidility: " << Humidility << ", maxT: " << MaxTemperature << ", minT: " << MinTemperature << endl;
	}

	Plant(double max, double min, double humidility, string info, string name){
		MaxTemperature = max;
		MinTemperature = min;
		Humidility = humidility;
		this->info = info;
		this->name = name;
	}

	~Plant(){}

};

