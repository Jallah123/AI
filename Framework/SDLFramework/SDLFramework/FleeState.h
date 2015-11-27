#pragma once
#include "GameState.h"
class FleeState :
	public GameState
{
public:
	FleeState();
	~FleeState();
	void Update(float dt);
	void Move(float dt);
	std::string ToString();
	void CheckState();
};

