#pragma once
#include <iostream>
#include "SteeringBehaviour.h"

class MovingEntity
{
protected:
	Vector2 m_Velocity{ 1, 1 };
	Vector2 m_Heading{ 1, 3 };
	Vector2 m_Side;

	float m_Mass = 1;
	float m_MaxSpeed = 10;
	float m_MaxForce;
	float m_MaxTurnRate;

	SteeringBehaviour m_Steering;

	Vector2 Update(float dt);
public:
	MovingEntity();

	float GetMaxSpeed() { return m_MaxSpeed; };
	Vector2 GetVelocity() { return m_Velocity; };

	~MovingEntity();
};