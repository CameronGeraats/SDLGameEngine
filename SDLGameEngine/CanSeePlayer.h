#pragma once
#include "BTCondition.h"
class CanSeePlayer :
	public BTCondition
{
public:
	void OnStart() {}
	BTState Update();
	CanSeePlayer();
	~CanSeePlayer();
};

