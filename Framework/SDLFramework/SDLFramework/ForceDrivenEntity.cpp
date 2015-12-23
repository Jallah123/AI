#include "ForceDrivenEntity.h"



ForceDrivenEntity::ForceDrivenEntity()
{
}

void ForceDrivenEntity::Update(float dt)
{
	if (mX > 800)
	{
		mX = 0;
	}
	else if (mX < 0)
	{
		mX = 800;
	}
	if (mY > 600)
	{
		mY = 0;
	}
	else if (mY < 0)
	{
		mY = 600;
	}
}


ForceDrivenEntity::~ForceDrivenEntity()
{
}