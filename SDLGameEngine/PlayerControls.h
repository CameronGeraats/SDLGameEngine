#pragma once
#include "Behaviour.h"
<<<<<<< HEAD
=======
class Transform;
>>>>>>> upstream/ExampleProjects
class PlayerControls :
	public Behaviour
{
public:
	PlayerControls();
	~PlayerControls();

<<<<<<< HEAD
=======
	Transform* target;

>>>>>>> upstream/ExampleProjects
	float xSpeed = 500;
	float ySpeed = 500;

	virtual void Update();
};

