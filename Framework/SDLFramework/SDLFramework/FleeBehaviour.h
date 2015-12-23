#pragma once
#include "SteeringBehaviour.h"

class FleeBehaviour :
	public SteeringBehaviour
{
public:
	FleeBehaviour(ForceDrivenEntity* _owner);
	Vector2 Calculate(float dt);
	Vector2 Flee(Vector2 TargetPos);
	~FleeBehaviour();
};

