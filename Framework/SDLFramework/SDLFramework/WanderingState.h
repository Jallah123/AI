#pragma once
#include "GameState.h"
#include "Rabbit.h"

class WanderingState :
	public GameState
{
public:
	WanderingState() {};
	WanderingState(int t) {};
	void Update(float dt);
	void Move(float dt);
	std::string ToString();
	void CheckState();
	void ChangeState(Rabbit* r);
	~WanderingState();
};

