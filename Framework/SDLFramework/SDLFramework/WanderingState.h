#pragma once
#include "GameState.h"

class WanderingState :
	public GameState
{
public:
	WanderingState() {};
	WanderingState(int t) {};
	void Update(float dt);
	void Move(float dt);
	void CheckState();
	~WanderingState();
};

