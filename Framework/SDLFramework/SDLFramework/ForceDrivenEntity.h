#pragma once
#include "IGameObject.h"
#include "MovingEntity.h"

class ForceDrivenEntity :
	public IGameObject, public MovingEntity
{
public:
	ForceDrivenEntity();
	virtual void Update(float dt);
	Vector2 GetPosition() { return Vector2{ getX(), getY() }; };
	void AddToX(float val) { setX(getX() + val); };
	void AddToY(float val) { setY(getY() + val); };
	~ForceDrivenEntity();
};