#pragma once
#include "SearchState.h"

class SearchPillState :
	public SearchState
{
public:
	SearchPillState();
	void Update(float dt);
	void Move(float dt);
	void CheckState();
	~SearchPillState();
};

