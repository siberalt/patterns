#pragma once
#include <vector>

using namespace std;
class IListener
{
public:
	IListener();
	~IListener();
	virtual void update(vector<double> v) = 0;
};

