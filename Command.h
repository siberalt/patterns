#pragma once
#include "Mode.h"
#include <vector>
#include <iostream>

using namespace std;

class Command
{
	Mode *mode;
public:
	Command(Mode *mode){
		this->mode = mode;
	}

	~Command();

	void execute(vector<double> v){
		cout << "I generate command for this mode\n";
		mode->execute(v);
	}

	void addToLog(){

	}
};

