#include "Weapon.h"


Weapon::Weapon(Node* n)
{
	mTexture = mApplication->LoadTexture("weapon.png");
	currentNode = n;
	mX = n->GetBoundingBox().x;
	mY = n->GetBoundingBox().y;
	mWidth = 30;
	mHeight = 30;
	mApplication->AddRenderable(this);
}

Weapon::~Weapon()
{
}
