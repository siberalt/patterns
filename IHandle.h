#pragma once
#include <vector>

using namespace std;

class IHandle
{
public:
	IHandle();
	~IHandle();

	virtual void setNext(IHandle*) = 0;
	virtual void handle(vector<double>) = 0;
};

