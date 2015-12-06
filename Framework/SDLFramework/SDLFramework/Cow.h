#pragma once
#include "ForceDrivenEntity.h"

class Cow: public ForceDrivenEntity
{
public:
	Cow();
	~Cow();
protected:
	virtual void Update(float dt);
};

