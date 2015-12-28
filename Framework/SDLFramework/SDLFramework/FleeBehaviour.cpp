#include "FleeBehaviour.h"
#include "ForceDrivenEntity.h"
#include "Cow.h"
#include "WanderBehaviour.h"

FleeBehaviour::FleeBehaviour(ForceDrivenEntity* _owner) : SteeringBehaviour(_owner)
{
}

Vector2 FleeBehaviour::Calculate()
{
	return Flee(FWApplication::GetInstance()->cow->GetPosition());
}

Vector2 FleeBehaviour::Flee(Vector2 TargetPos)
{
	//only flee if the target is within 'panic distance'. Work in distance
	//squared space.
	const double PanicDistanceSq = 100.0 * 100.0;
	if (GetOwner()->GetPosition().Distance(TargetPos) > PanicDistanceSq)
	{
		return Vector2{ 0, 0 };
	}
	Vector2 temp = GetOwner()->GetPosition() - TargetPos;
	temp.Normalize();
	Vector2 DesiredVelocity = temp * GetOwner()->GetMaxSpeed();
	return (DesiredVelocity - GetOwner()->GetVelocity());
}

void FleeBehaviour::CheckState()
{
	Cow* c = FWApplication::GetInstance()->cow;
	float distance = c->DistanceTo(owner);

	if (distance > 300)
	{
		owner->setSteeringBehaviour(new WanderBehaviour{ owner });
	}

}

FleeBehaviour::~FleeBehaviour()
{
}