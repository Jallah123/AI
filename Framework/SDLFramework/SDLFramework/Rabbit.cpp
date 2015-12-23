#include "Rabbit.h"
#include "WanderBehaviour.h"

Rabbit::Rabbit()
{
	mTexture = mApplication->LoadTexture("rabbit-3.png");
	mX = 200;
	mY = 200;
	mWidth = 40;
	mHeight = 40;
	mApplication->AddRenderable(this);
	m_Steering = new WanderBehaviour{ this };
}

void Rabbit::Update(float dt)
{
	ForceDrivenEntity::Update(dt);
	m_Velocity = MovingEntity::Update(dt);
	m_Velocity.Truncate(GetMaxSpeed());
	mX += m_Velocity.x * dt;
	mY += m_Velocity.y * dt;
}

Rabbit::~Rabbit()
{
}
