#pragma once
#include "SearchState.h"
class ChaseRabbitState :
	public SearchState
{
public:
	ChaseRabbitState();
	void Update(float dt);
	void Move(float dt);
	std::string ToString();
	void CheckState();
	~ChaseRabbitState();
};

