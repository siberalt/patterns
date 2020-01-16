#pragma once
class Vents
{
	int speed;
public:
	void SetSpeed(int speed){
		this->speed = speed;
	}

	void Reverse(){
		speed *= -1;
	}

	Vents();
	~Vents();
};

