#include "Bullet.h"
#include "GameObject.h"
#include "Transform.h"
#include "Time.h"
#include "Game.h"
#include "Shooter.h"
#include "SceneMenu.h"
#include <iostream>

Bullet::Bullet()
{
}


Bullet::~Bullet()
{
}
void Bullet::Awake()
{
	Behaviour::Awake();
	triggerEventListener = std::make_shared<EventListener<Collider*>>(std::bind(&Bullet::OnTriggerEnter, this, std::placeholders::_1));
	gameObject->OnTriggerEnter.AddListener(triggerEventListener);
}

void Bullet::Cleanup()
{
	Behaviour::Cleanup();
	gameObject->OnTriggerEnter.RemoveListener(triggerEventListener);
}

void Bullet::Update()
{
	Behaviour::Update();
	Vector2 up = gameObject->transform->Up();
	gameObject->transform->SetAbsolutePositionDelta(speed * up * Time::DeltaTime());
	timer += Time::DeltaTime();
	if (timer > destroyTime)
	{
		game->Destroy(gameObject);
	}
}

void Bullet::OnTriggerEnter(Collider* col)
{
	if (col->gameObject->name == "enemy")
	{
			game->Destroy(col->gameObject);
			dynamic_cast<Shooter*>(game)->playerStats->UpdateMoney(25);
			if(gameObject->name != "laser")
				timer += 50;
	}
	else if (col->gameObject->name == "Player")
	{
		Shooter* temp = dynamic_cast<Shooter*>(game);
		float damage = 6 * (100 - temp->playerStats->GetArmor())/100;
		temp->playerStats->UpdateHealth(int(-damage));
		std::cout << temp->playerStats->GetHealth() << std::endl;
		if (temp->playerStats->GetHealth() <= 0)
		{
			//game->Destroy(col->gameObject);
			temp->switchSceneTo = new SceneMenu();
		}
		game->Destroy(gameObject);
	}
}
