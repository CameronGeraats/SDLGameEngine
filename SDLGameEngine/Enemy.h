#pragma once
#include "Behaviour.h"
#include "EventListener.h"
#include "Collider.h"
class Enemy :
	public Behaviour
{
public:
	Enemy();
	~Enemy();

	void Awake();
	void Update();
	void Cleanup();
	std::shared_ptr<EventListener<Collider*>> triggerEnterListener = NULL;
	void OnTriggerEnter(Collider* col);
	std::shared_ptr<EventListener<Collider*>> triggerExitListener = NULL;
	void OnTriggerExit(Collider* col);
	float range = 200;
	GameObject* player;
	GameObject* detectedPlayer = nullptr;
};
