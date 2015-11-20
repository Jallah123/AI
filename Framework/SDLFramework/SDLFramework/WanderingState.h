#pragma once
#include "GameState.h"

class WanderingState :
	public GameState
{
public:
	WanderingState() {};
	void Update(float dt);
	void Move(float dt);
	void CheckState();
	~WanderingState();
};

