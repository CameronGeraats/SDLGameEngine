#pragma once
#include "BTAction.h"
#include "EnemyBlackboard.h"
#include "GameObject.h"
#include "SteeringAgent.h"
class Patrol :
	public BTAction
{
public:
	void OnStart();
	BTState Update();
	Patrol();
	~Patrol();
private:
	Enemy* enemy;
};

