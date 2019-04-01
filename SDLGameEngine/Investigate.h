#pragma once
#include "BTAction.h"
#include "EnemyBlackboard.h"
#include "GameObject.h"
#include "SteeringAgent.h"
class Investigate :
	public BTAction
{
public:
	Investigate();
	~Investigate();
	void OnStart();
	BTState OnUpdate();
private:
	Enemy* enemy;
	float timer = 0;
};

