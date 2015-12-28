#pragma once
#include <iostream>
#include "SteeringBehaviour.h"

class MovingEntity
{
protected:
	Vector2 m_Velocity{ -1, 1 };
	Vector2 m_Heading;
	Vector2 m_Side;

	float m_Mass = 1;
	float m_MaxSpeed = 5;
	float m_MaxForce = 1;
	float m_MaxTurnRate = 1;

	SteeringBehaviour* m_Steering = nullptr;

	Vector2 Update(float dt);
public:
	MovingEntity();

	float GetMaxSpeed() { return m_MaxSpeed; };
	Vector2 GetVelocity() { return m_Velocity; };
	Vector2 GetHeading() { return m_Heading; };
	Vector2 GetSide() { return m_Side; };
	void SetVelocity(Vector2 velocity) { m_Velocity = velocity; };
	void SetHeading(Vector2 heading) { m_Heading = heading; };
	void SetSide(Vector2 side) { m_Side = side; };
	void setSteeringBehaviour(SteeringBehaviour* newBehaviour) { m_Steering = newBehaviour; };
	SteeringBehaviour* getSteeringBehaviour() { return m_Steering; };
	~MovingEntity();
};