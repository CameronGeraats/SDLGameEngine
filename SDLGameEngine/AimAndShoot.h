#pragma once
#include "BTAction.h"
class AimAndShoot :
	public BTAction
{
public:
	void OnStart() {}
	BTState Update() { return BTState::Success; }
	AimAndShoot();
	~AimAndShoot();
};

