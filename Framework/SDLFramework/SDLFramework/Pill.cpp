#include "Pill.h"



Pill::Pill(Node* n)
{
	mTexture = mApplication->LoadTexture("pill.png");
	currentNode = n;
	mX = n->GetBoundingBox().x;
	mY = n->GetBoundingBox().y;
	mWidth = 30;
	mHeight = 30;
	mApplication->AddRenderable(this);
}


Pill::~Pill()
{
}
