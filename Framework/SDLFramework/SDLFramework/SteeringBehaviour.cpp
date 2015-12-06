#include "SteeringBehaviour.h"
#include "ForceDrivenEntity.h"

Vector2 SteeringBehaviour::Seek(Vector2 target)
{
	Vector2 position{ owner->getX(), owner->getY() };
	std::cout << owner->getX() << ":" << owner->getY() << '\n';
	Vector2 desiredVelocity = target - position;
	desiredVelocity.Normalize();
	return desiredVelocity - owner->GetVelocity();
}


SteeringBehaviour::~SteeringBehaviour()
{
}
