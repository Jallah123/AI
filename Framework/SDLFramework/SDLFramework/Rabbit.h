#pragma once
#include "ForceDrivenEntity.h"
class Rabbit :
	public ForceDrivenEntity
{
public:
	Rabbit();
	~Rabbit();
	virtual void Update(float dt);
};