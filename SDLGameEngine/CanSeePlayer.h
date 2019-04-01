#pragma once
#include "BTCondition.h"
#include "EnemyBlackboard.h"
class CanSeePlayer :
	public BTCondition
{
public:
	void OnStart();
	BTState OnUpdate();
	CanSeePlayer();
	~CanSeePlayer();
private:
	Enemy * enemy;
};

