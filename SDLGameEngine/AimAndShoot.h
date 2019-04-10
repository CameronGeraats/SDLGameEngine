#pragma once
#include "BTAction.h"
#include "EnemyBlackboard.h"
#include "GameObject.h"
#include "SteeringAgent.h"

class AimAndShoot :
	public BTAction
{
public:
	void OnStart();
	BTState OnUpdate();
	AimAndShoot();
	~AimAndShoot();
private:
	Enemy* enemy;
};

