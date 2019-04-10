#pragma once
#include "Behaviour.h"
#include "Vector2.h"
class UpdateVectorTarget :
	public Behaviour
{
public:
	UpdateVectorTarget();
	UpdateVectorTarget(GameObject* go);
	~UpdateVectorTarget();

	void Update();

	float maxTime = 1000;
	Vector2 target;
	GameObject* targetObject;

<<<<<<< HEAD
private:
	float timer = 0;
	short stage = 0;
=======
	Vector2 center;
	float radius;

private:
	float timer = 0;
>>>>>>> upstream/ExampleProjects
};

