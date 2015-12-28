#pragma once
#include "SteeringBehaviour.h"

class FleeBehaviour :
	public SteeringBehaviour
{
public:
	FleeBehaviour(ForceDrivenEntity* _owner);
	Vector2 Calculate();
	Vector2 Flee(Vector2 TargetPos);
	void CheckState();
	std::string ToString() { return "Flee"; };
	~FleeBehaviour();
};

