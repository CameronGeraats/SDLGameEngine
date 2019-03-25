#pragma once
#include "BTAction.h"
class Patrol :
	public BTAction
{
public:
	void OnStart() {}
	BTState Update() { return BTState::Success; }
	Patrol();
	~Patrol();
};

