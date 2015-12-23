#pragma once
#include "SteeringBehaviour.h"
#include "ForceDrivenEntity.h"

class PersuitBehaviour :
	public SteeringBehaviour
{
public:
	PersuitBehaviour(ForceDrivenEntity* _owner);
	~PersuitBehaviour();
	Vector2 Seek(Vector2 target);
	Vector2 Persuit(ForceDrivenEntity* target);
	Vector2 Calculate(float dt);
};

