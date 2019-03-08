#pragma once
#include "Behaviour.h"
class Shoot :
	public Behaviour
{
public:
	Shoot();
	~Shoot();

	void Update();
	float laserActive = 0;
	GameObject* laser = nullptr;
};

