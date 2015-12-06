#pragma once
#include "SteeringBehaviour.h"
class WanderBehaviour :
	public SteeringBehaviour
{
private:
	float wanderRadius;
	float wanderdistance;
	float wanderJitter;
public:
	WanderBehaviour();

	Vector2 Calculate() override;

	~WanderBehaviour();
};

