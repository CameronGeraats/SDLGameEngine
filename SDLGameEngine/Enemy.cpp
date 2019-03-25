#include "Enemy.h"
#include "Input.h"
#include "Rigidbody.h"
#include "GameObject.h"
#include "Physics.h"
#include "RaycastHit.h"
#include "Game.h"

Enemy::Enemy()
{
}


Enemy::~Enemy()
{
}

void Enemy::Awake()
{
	Behaviour::Awake();
	triggerEnterListener = std::make_shared<EventListener<Collider*>>(std::bind(&Enemy::OnTriggerEnter, this, std::placeholders::_1));
	gameObject->OnTriggerEnter.AddListener(triggerEnterListener);

	triggerExitListener = std::make_shared<EventListener<Collider*>>(std::bind(&Enemy::OnTriggerExit, this, std::placeholders::_1));
	gameObject->OnTriggerExit.AddListener(triggerExitListener);
}

void Enemy::Cleanup()
{
	Behaviour::Cleanup();
	gameObject->OnTriggerEnter.RemoveListener(triggerEnterListener);
	gameObject->OnTriggerExit.RemoveListener(triggerExitListener);
}

void Enemy::Update()
{
	Behaviour::Update();
	if (detectedPlayer != nullptr)
	{
		float length = (detectedPlayer->transform->GetAbsolutePosition() - gameObject->transform->GetAbsolutePosition()).Length();
		if ( length > 100)
		{
			detectedPlayer = nullptr;
		}
		//gameObject->GetComponent<Rigidbody>()->SetBodyType(Rigidbody::kinematicBody);
	}
	//RaycastHit hit = game->physics->Raycast(gameObject->transform->GetAbsolutePosition(), -gameObject->transform->Up(), 10000);
}

void Enemy::OnTriggerEnter(Collider* col)
{
	if (col->gameObject->name == "TankGraphic")
	{
		detectedPlayer = col->gameObject;
	}
}

void Enemy::OnTriggerExit(Collider* col)
{
	if (col->gameObject->name == "TankGraphic")
	{
		//detectedPlayer = nullptr;
	}
}