#include "Cow.h"
#include "PersuitBehaviour.h"

Cow::Cow()
{
	mTexture = mApplication->LoadTexture("cow-1.png");
	mX = 100;
	mY = 100;
	mWidth = 40;
	mHeight = 40;
	mApplication->AddRenderable(this);
	m_Steering = new PersuitBehaviour{this};
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
