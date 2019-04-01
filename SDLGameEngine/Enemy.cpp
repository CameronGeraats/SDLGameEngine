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
	if (player != nullptr)
	{
		float length = (player->transform->GetAbsolutePosition() - gameObject->transform->GetAbsolutePosition()).Length();
		/*if ( length > 100)
		{
			detectedPlayer = nullptr;
		}*/
		detectedPlayer = length > range ? nullptr : player;
		//gameObject->GetComponent<Rigidbody>()->SetBodyType(Rigidbody::kinematicBody);
	}

	SDL_SetRenderDrawColor(Game::gRenderer, 0xFF, 0x00, 0x00, 0xFF);
	int maxPoints = 100;
	Vector2 pos;
	for (int i = 0; i < maxPoints; i++)
	{
		pos = gameObject->transform->GetAbsolutePosition() + range * Vector2(cos(i * 2 * M_PI / maxPoints), sin(i * 2 * M_PI / maxPoints));
		SDL_RenderDrawPoint(Game::gRenderer, pos.x - Camera::x, pos.y - Camera::y);
		SDL_RenderDrawPoint(Game::gRenderer, pos.x + 1 - Camera::x, pos.y - Camera::y);
		SDL_RenderDrawPoint(Game::gRenderer, pos.x - 1 - Camera::x, pos.y - Camera::y);
		SDL_RenderDrawPoint(Game::gRenderer, pos.x - Camera::x, pos.y + 1 - Camera::y);
		SDL_RenderDrawPoint(Game::gRenderer, pos.x - Camera::x, pos.y - 1 - Camera::y);
	}
	//RaycastHit hit = game->physics->Raycast(gameObject->transform->GetAbsolutePosition(), -gameObject->transform->Up(), 10000);
}

void Enemy::OnTriggerEnter(Collider* col)
{
	if (col->gameObject->name == "TankGraphic")
	{
		//detectedPlayer = col->gameObject;
	}
}

void Enemy::OnTriggerExit(Collider* col)
{
	if (col->gameObject->name == "TankGraphic")
	{
		//detectedPlayer = nullptr;
	}
}