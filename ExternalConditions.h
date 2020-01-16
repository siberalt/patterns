#pragma once
#include "IFunction.h"
#include "IListener.h"
#include <vector>

using namespace std;

class ExternalConditions
{
	IFunction *func;
	double step = 1;
	double start = 0;
	vector<IListener*> listeners;

public:
	void addHandler(IListener *listener){
		listeners.push_back(listener);
	}

	void update(vector<double> v){
		for (IListener *listener : listeners)
			listener->update(v);
	}

	void setFunction(IFunction *func){
		this->func = func;
	}

	void setStep(double step){
		this->step = step;
	}

	void setStart(double start){
		this->start = start;
	}

	double inc(){
		return func->calculate(start += step);
	}

	double dec(){
		return func->calculate(start -= step);
	}

	ExternalConditions();
	~ExternalConditions();
};

