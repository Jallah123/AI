#pragma once
#include "GameState.h"
class SearchPillState :
	public GameState
{
public:
	SearchPillState();
	void Update(float dt);
	void Move(float dt);
	void CheckState();
	~SearchPillState();
};

