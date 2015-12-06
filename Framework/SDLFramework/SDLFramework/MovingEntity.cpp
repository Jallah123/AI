#include "MovingEntity.h"



MovingEntity::MovingEntity()
{
}

Vector2 MovingEntity::Update(float dt)
{
	Vector2 stForce = m_Steering.Calculate();
	// ... // Calc new position, Check p 90.

	return stForce;
}

MovingEntity::~MovingEntity()
{
}
