#include "PersuitBehaviour.h"
#include "Rabbit.h"

PersuitBehaviour::PersuitBehaviour(ForceDrivenEntity* _owner) : SteeringBehaviour(_owner)
{
}

Vector2 PersuitBehaviour::Calculate(float dt)
{
	return Persuit(FWApplication::GetInstance()->rabbit);
}

Vector2 PersuitBehaviour::Seek(Vector2 target)
{
	Vector2 position{ GetOwner()->getX(), GetOwner()->getY() };
	std::cout << GetOwner()->getX() << ":" << GetOwner()->getY() << '\n';
	Vector2 desiredVelocity = target - position;
	desiredVelocity.Normalize();
	return desiredVelocity - GetOwner()->GetVelocity();
}

Vector2 PersuitBehaviour::Persuit(ForceDrivenEntity* evader)
{
	//if the evader is ahead and facing the agent then we can just seek
	//for the evader's current position.
	Vector2 ToEvader = evader->GetPosition() - GetOwner()->GetPosition();
	double RelativeHeading = GetOwner()->GetHeading().Dot(evader->GetHeading());
	if ((ToEvader.Dot(GetOwner()->GetHeading()) > 0) && (RelativeHeading < -0.95)) //acos(0.95)=18 degs
	{
		return Seek(evader->GetPosition());
	}
	//Not considered ahead so we predict where the evader will be.

	//the look-ahead time is proportional to the distance between the evader
	//and the pursuer; and is inversely proportional to the sum of the
	//agents' velocities
	double LookAheadTime = ToEvader.Length() / (GetOwner()->GetMaxSpeed() + evader->GetVelocity().x + evader->GetVelocity().y);
	//now seek to the predicted future position of the evader
	return Seek(evader->GetPosition() + evader->GetVelocity() * LookAheadTime);
}

PersuitBehaviour::~PersuitBehaviour()
{

}
