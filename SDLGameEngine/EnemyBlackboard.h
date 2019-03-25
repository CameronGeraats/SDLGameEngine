#pragma once
#include "BTBlackboard.h"
#include "Enemy.h"
class EnemyBlackboard :
	public BTBlackboard
{
public:
	Enemy* enemy;
	EnemyBlackboard();
	~EnemyBlackboard();
};

