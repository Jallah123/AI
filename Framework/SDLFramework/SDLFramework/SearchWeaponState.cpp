#include "SearchWeaponState.h"
#include "Weapon.h"
#include <iostream>
#include "StateFactory.h"

SearchWeaponState::SearchWeaponState()
{
	SetTarget(FWApplication::GetInstance()->GetWeapon()->GetNode());
}

void SearchWeaponState::Update(float dt)
{
	CheckState();
	if (target == nullptr)
	{
		SetTarget(FWApplication::GetInstance()->GetWeapon()->GetNode());
	}
}

void SearchWeaponState::Move(float dt)
{
	SearchState::Move(dt);
}

void SearchWeaponState::CheckState()
{
	if (owner->GetCurrentNode() == target)
	{
		std::cout << "new wandering state" << std::endl;
		owner->ChangeState(StateFactory::Create(State::SHOOT_COW, owner));
		FWApplication::GetInstance()->GetWeapon()->Respawn();
	}
}

std::string SearchWeaponState::ToString()
{
	return "Searching weapon";
}

SearchWeaponState::~SearchWeaponState()
{
}
