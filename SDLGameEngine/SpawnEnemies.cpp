#include "SpawnEnemies.h"
#include "Time.h"
#include <cmath>
#include "Game.h"
#include "Camera.h"
#include "Shooter.h"
#include "SceneMenu.h"
#include "SceneUpgrade.h"

SpawnEnemies::SpawnEnemies()
{
	spawnLimit = 10;
}

//SpawnEnemies::SpawnEnemies(GameObject * _gameObject) : Component(_gameObject)
//SpawnEnemies::SpawnEnemies()
//{
//}

void SpawnEnemies::Awake()
{
	Component::Awake();
}

void SpawnEnemies::Start()
{
	Component::Start();
}

void SpawnEnemies::Update()
{
	float f = Time::TimeElapsed();
	if(spawnLimit > 0 && createReady && fmod(f,5)>4.5f)
	{
		int max = 1 + rand() % 5;
		for (int i = 0; i < max; i++) // To generate more each tick
		{
			int x, y, z = rand() % 4;
			if (z == 0) { y = Camera::y - 100; x = Camera::x + rand() % Camera::width; }
			else if (z == 1) { y = Camera::y + rand() % Camera::height; x = Camera::x - 100; }
			else if (z == 2) { y = Camera::y + Camera::height + 100; x = Camera::x + rand() % Camera::width; }
			else if (z == 3) { y = Camera::y + rand() % Camera::height; x = Camera::x + Camera::width + 100; }

			//GameObject* enemy = Instantiate(game->Prefab("Enemy"), Camera::x + rand() % Camera::width, Camera::y + rand() % Camera::height, 0);
			int type = rand() % 3;
			GameObject* enemy = Instantiate(game->Prefab( type == 0 ? "Enemy1" : type == 1 ? "Enemy2" : "Enemy3"), x, y, 0);
			spawnLimit--;
			//enemy->GetComponent<Rigidbody>()->AddForce(50 * Vector2(rand() % 100 - 50 , rand() % 100 - 50));
		}
		createReady = false;
	}
	if (fmod(f, 5) < 4.5f) createReady = true;
	Component::Update();
	if (spawnLimit <= 0)
	{
		spawnLimit--;
		if (spawnLimit <= -180)
			;
		//dynamic_cast<Shooter*>(game)->switchSceneTo = new SceneUpgrade();
		//dynamic_cast<Shooter*>(game)->switchSceneTo = new SceneMenu();
	}
}

void SpawnEnemies::FixedUpdate()
{
	Component::Update();
}

void SpawnEnemies::Cleanup()
{
	Component::Cleanup();
}


SpawnEnemies::~SpawnEnemies()
{
}
