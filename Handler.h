#pragma once
#include "IHandle.h"
class Handler :
	public IHandle
{
	IHandle *next;
public:

	Handler();
	~Handler();

	IHandle* getNext(){
		return next;
	}

	virtual void setNext(IHandle *next){
		if (this->next != NULL)
			this->next->setNext(next);
		else
			this->next = next;
	}

	virtual void handle(vector<double> v){
		if (v[0] == 1) v[1]++;
		else next->handle(v);
	}
};

