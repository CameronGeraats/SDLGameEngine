#pragma once
//#include "Component.h"
#include "Behaviour.h"

class SpawnEnemies :
	//public Component
	public Behaviour
{
public:
	SpawnEnemies();
	//SpawnEnemies(GameObject* _gameObject);
	virtual void Awake();
	virtual void Start();
	virtual void Update();
	virtual void FixedUpdate();
	virtual void Cleanup();
	virtual ~SpawnEnemies();
private:
	bool createReady = true;
};

