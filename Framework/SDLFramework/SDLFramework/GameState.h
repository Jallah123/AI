#pragma once
#include "AliveGameObject.h"

class GameState
{
public:
	GameState() {};
	void SetOwner(AliveGameObject* _owner) { owner = _owner; };
	virtual void Update(float dt) = 0;
	virtual void CheckState() = 0;
	virtual void Move(float dt) = 0;
	virtual std::string ToString() = 0;
	AliveGameObject* GetOwner() { return owner; };
	~GameState();
protected:
	AliveGameObject* owner;
};

