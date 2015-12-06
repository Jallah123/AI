#include "Cow.h"

Cow::Cow()
{
	mTexture = mApplication->LoadTexture("cow-1.png");
	mX = 0;
	mY = 0;
	mWidth = 40;
	mHeight = 40;
	mApplication->AddRenderable(this);
	m_Steering.SetOwner(this);
}

void Cow::Update(float dt)
{
	ForceDrivenEntity::Update(dt);
	m_Velocity = MovingEntity::Update(dt);
	m_Velocity.Truncate(GetMaxSpeed());
	mX += m_Velocity.x * dt;
	mY += m_Velocity.y * dt;
}

Cow::~Cow()
{
}
