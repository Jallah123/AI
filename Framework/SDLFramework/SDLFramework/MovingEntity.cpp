#include "MovingEntity.h"
#include "WanderBehaviour.h"
#include "ForceDrivenEntity.h"

MovingEntity::MovingEntity()
{
}

Vector2 MovingEntity::Update(float dt)
{
	Vector2 stForce = m_Steering->Calculate();
	//Acceleration = Force/Mass
	Vector2 acceleration = stForce;
	//update velocity
	m_Velocity += acceleration * dt;
	//make sure vehicle does not exceed maximum velocity
	m_Velocity.Truncate(m_MaxSpeed);
	//update the position
	m_Steering->GetOwner()->AddToX(m_Velocity.x * dt);
	m_Steering->GetOwner()->AddToY(m_Velocity.y * dt);
	//update the heading if the vehicle has a velocity greater than a very small
	//value
	if (m_Velocity.LengthSq() > 0.00000001)
	{
		m_Velocity.Normalize();
		m_Heading = m_Velocity;
		m_Side = m_Heading.Perp();
	}
	return stForce;
}

MovingEntity::~MovingEntity()
{
}
