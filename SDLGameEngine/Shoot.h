#pragma once
#include "Behaviour.h"
class Shoot :
	public Behaviour
{
public:
	Shoot();
	~Shoot();

	void Update();
<<<<<<< HEAD
	float laserActive = 0;
	GameObject* laser = nullptr;
=======
>>>>>>> upstream/ExampleProjects
};

