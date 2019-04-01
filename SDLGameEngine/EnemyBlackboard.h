#pragma once
#include "BTBlackboard.h"
#include "Enemy.h"
class EnemyBlackboard :
	public BTBlackboard
{
public:
	Enemy* enemy;
	bool investigate = false;
	Vector2 lastKnowPos;
	EnemyBlackboard();
	~EnemyBlackboard();
};

