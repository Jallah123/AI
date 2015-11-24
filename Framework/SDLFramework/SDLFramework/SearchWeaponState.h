#pragma once
#include "SearchState.h"

class SearchWeaponState :
	public SearchState
{
public:
	SearchWeaponState();
	void Update(float dt);
	void Move(float dt);
	std::string ToString();
	void CheckState();
	~SearchWeaponState();
};