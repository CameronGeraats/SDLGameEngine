#pragma once
#include "Behaviour.h"
class EnemyShoot :
	public Behaviour
{
public:
	EnemyShoot();
	~EnemyShoot();

	void Update();
private:
	float timer = 0;
	bool shootready = true;
};

