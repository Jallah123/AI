#pragma once
#include "SteeringBehaviour.h"
class WanderBehaviour :
	public SteeringBehaviour
{
private:
	float wanderRadius;
	float wanderDistance;
	float wanderJitter;
public:
	WanderBehaviour(ForceDrivenEntity* _owner);

	Vector2 wanderTarget;
	Vector2 Calculate() override;

	~WanderBehaviour();
};

