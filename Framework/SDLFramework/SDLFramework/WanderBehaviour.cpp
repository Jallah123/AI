#include "WanderBehaviour.h"
#include "NumberUtility.h"

WanderBehaviour::WanderBehaviour()
{
}

Vector2 WanderBehaviour::Calculate()
{
	Vector2 wanderTarget{ wanderJitter * NumberUtility::RandomNumber(0.0f, 1.0f), wanderJitter * NumberUtility::RandomNumber(0.0f, 1.0f) };
	wanderTarget.Normalize();

	wanderTarget *= wanderRadius;

	Vector2 targetLocal = wanderTarget * Vector2{ wanderdistance, 0 };
	Vector2 targetWorld = PointToWorldSpace(targetLocal, heading, side, position);

	return targetWorld - position;
}

WanderBehaviour::~WanderBehaviour()
{
}
