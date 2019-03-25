#pragma once
#include "Behaviour.h"
class Transform;
class PlayerControls :
	public Behaviour
{
public:
	PlayerControls();
	~PlayerControls();

	Transform* target;

	float xSpeed = 500;
	float ySpeed = 500;

	virtual void Update();
};

