#include "Bullet.h"
#include "GameObject.h"
#include "Transform.h"
#include "Time.h"
#include "Game.h"
#include "Shooter.h"
#include "SceneMenu.h"
#include <iostream>
#include "Enemy.h"

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
	Shooter* temp = dynamic_cast<Shooter*>(game);
	if (col->gameObject->name == "enemy1" || col->gameObject->name == "enemy2" || col->gameObject->name == "enemy3")
	{
		float a, b, c;
		temp->playerStats->GetUpgradeStats(a,b,c);
		int x, y, z;
		x = a; y = (a - (float)x) * 10; z = 1 + rand() % 10;
		x += (y >= z ? 1 : 0);
		x = x > 1 ? x : 1;
		if (col->gameObject->GetComponent<Enemy>()->GetHealth() > 0)
		{
			col->gameObject->GetComponent<Enemy>()->ModHealth(-x);
			if (col->gameObject->GetComponent<Enemy>()->GetHealth() <= 0)
			{
				game->Destroy(col->gameObject);
				if (col->gameObject->name == "enemy1")
					temp->playerStats->UpdateMoney(25);
				else if (col->gameObject->name == "enemy2")
					temp->playerStats->UpdateMoney(75);
				else if (col->gameObject->name == "enemy3")
					temp->playerStats->UpdateMoney(75);
				temp->GetAM()->PlaySound(1);
			}
			if (gameObject->name != "laser")
				timer += 50;
		}
	}
	else if (col->gameObject->name == "Player")
	{
		
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
