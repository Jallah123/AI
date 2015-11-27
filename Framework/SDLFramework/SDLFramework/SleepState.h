#pragma once
#include "GameState.h"
class SleepState :
	public GameState
{
public:
	SleepState();
	~SleepState();
	void Update(float dt);
	void Move(float dt);
	std::string ToString();
	void CheckState();
private:
	int sleep = 5;
};

