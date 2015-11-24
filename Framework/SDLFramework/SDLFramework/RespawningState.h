#pragma once
#include "GameState.h"

class RespawningState :
	public GameState
{
public:
	RespawningState() {};
	void Update(float dt);
	void Move(float dt);
	std::string ToString();
	void CheckState();
	~RespawningState();
};