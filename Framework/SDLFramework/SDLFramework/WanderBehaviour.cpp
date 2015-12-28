#include "WanderBehaviour.h"
#include "NumberUtility.h"
#include "ForceDrivenEntity.h"
#include "FleeBehaviour.h"
#include "Cow.h"

WanderBehaviour::WanderBehaviour(ForceDrivenEntity* _owner) : SteeringBehaviour(_owner)
{
	wanderRadius = 1;
	wanderDistance = 7;
	wanderJitter = 5;
	wanderTarget = GetOwner()->GetPosition();
}

Vector2 WanderBehaviour::Calculate()
{
	wanderTarget += Vector2{ wanderJitter * NumberUtility::RandomNumber(-1.0f, 1.0f), wanderJitter * NumberUtility::RandomNumber(-1.0f, 1.0f) };
	wanderTarget.Normalize();

	wanderTarget *= wanderRadius;

	Vector2 targetLocal = wanderTarget * Vector2{ wanderDistance, wanderDistance };
	Vector2 targetWorld = PointToWorldSpace(targetLocal, GetOwner()->GetHeading(), GetOwner()->GetSide(), GetOwner()->GetPosition());

	return targetWorld - GetOwner()->GetPosition();
}

void WanderBehaviour::CheckState()
{
	Cow* c = FWApplication::GetInstance()->cow;
	float distance = c->DistanceTo(owner);

	if (distance < 50)
	{
		owner->setSteeringBehaviour(new FleeBehaviour{owner});
	}

}

WanderBehaviour::~WanderBehaviour()
{

}