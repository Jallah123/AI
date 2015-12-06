#include "SteeringBehaviour.h"
#include "ForceDrivenEntity.h"
#include <math.h>

Vector2 SteeringBehaviour::PointToWorldSpace(Vector2 localTarget, Vector2 heading, Vector2 side, Vector2 position)
{
	float theta = (heading + Vector2{ M_PI / 2,  M_PI / 2 }).x;
	float r00 = cos(theta);
	float r01 = -sin(theta);
	float r10 = -r01;
	float r11 = r00;
	Vector2 world{};
	world.x = localTarget.x * r00 + localTarget.y*r01 + position.x;
	world.y = localTarget.x * r10 + localTarget.y*r11 + position.y;
	return world;
}

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
