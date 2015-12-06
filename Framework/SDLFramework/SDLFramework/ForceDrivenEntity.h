#pragma once
#include "IGameObject.h"
#include "MovingEntity.h"

class ForceDrivenEntity :
	public IGameObject, public MovingEntity
{
public:
	ForceDrivenEntity();
	virtual void Update(float dt);
	~ForceDrivenEntity();
};

