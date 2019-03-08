#pragma once
#include "SteeringBehaviour.h"
class Stop :
	public SteeringBehaviour
{
public:
	Stop();
	Stop(GameObject* go);
	~Stop();

	virtual void Update();

	Transform* target;
	float maxAccelaraction = 200;
	float slowRadius = 400;
	float targetRadius = 350;
	float timeToTarget = 1.0f;
};

