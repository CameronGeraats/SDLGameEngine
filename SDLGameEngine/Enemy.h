#pragma once
#include "Behaviour.h"
#include "EventListener.h"
#include "Collider.h"
class Enemy :
	public Behaviour
{
private:
	int health;
public:
	Enemy();
	~Enemy();

	void Awake();
	void Update();
	void Cleanup();
	int GetHealth() { return health; }
	void ModHealth(int mod) { health += mod; }
	std::shared_ptr<EventListener<Collider*>> triggerEnterListener = NULL;
	void OnTriggerEnter(Collider* col);
	std::shared_ptr<EventListener<Collider*>> triggerExitListener = NULL;
	void OnTriggerExit(Collider* col);
	float range = 200;
	GameObject* player;
	GameObject* detectedPlayer = nullptr;
};
