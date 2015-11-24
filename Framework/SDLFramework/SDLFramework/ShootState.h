#pragma once
#include "GameState.h"

class ShootState :
	public GameState
{
public:
	ShootState() {};
	ShootState(int t) {};
	void Update(float dt);
	void Move(float dt);
	std::string ToString();
	void CheckState();
	~ShootState();
};

