#pragma once
#include "Behaviour.h"
#include "SpriteRenderer.h"

class Transform;
class PlayerControls :
	public Behaviour
{
public:
	PlayerControls(SpriteRenderer*);
	~PlayerControls();

	Transform* target;
	SpriteRenderer* playerSprite;

	float xSpeed = 500;
	float ySpeed = 500;

	virtual void Update();
};
