#pragma once
#include <math.h>
#include <functional>
#include <vector>
#include <numeric>
#include "Vector2.h"

class ForceDrivenEntity;

class SteeringBehaviour
{
public:
	SteeringBehaviour(ForceDrivenEntity* _owner) { owner = _owner; };
	Vector2 PointToWorldSpace(Vector2 localTarget, Vector2 heading, Vector2 side, Vector2 position);
	void SetOwner(ForceDrivenEntity* newowner) { owner = newowner; };
	ForceDrivenEntity* GetOwner() { return owner; };
	virtual Vector2 Calculate() = 0;
	Vector2 Seek(Vector2 Target);
	~SteeringBehaviour();
protected:
	ForceDrivenEntity* owner;
};

