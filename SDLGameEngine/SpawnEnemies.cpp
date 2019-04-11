#include "SpawnEnemies.h"
#include "Time.h"
#include <cmath>
#include "Game.h"
#include "Camera.h"
#include "Shooter.h"
#include "SceneMenu.h"

SpawnEnemies::SpawnEnemies()
{
	spawnLimit = 35;
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
	if(createReady && fmod(f,4)>3.5f)
	{
		for (int i = 0; i < 3; i++) // To generate more each tick
		{
			int x, y, z = rand() % 4;
			if (z == 0) { y = Camera::y - 100; x = Camera::x + rand() % Camera::width; }
			else if (z == 1) { y = Camera::y + rand() % Camera::height; x = Camera::x - 100; }
			else if (z == 2) { y = Camera::y + Camera::height + 100; x = Camera::x + rand() % Camera::width; }
			else if (z == 3) { y = Camera::y + rand() % Camera::height; x = Camera::x + Camera::width + 100; }

			//GameObject* enemy = Instantiate(game->Prefab("Enemy"), Camera::x + rand() % Camera::width, Camera::y + rand() % Camera::height, 0);
			GameObject* enemy = Instantiate(game->Prefab("Enemy"), x, y, 0);
			spawnLimit--;
			//enemy->GetComponent<Rigidbody>()->AddForce(50 * Vector2(rand() % 100 - 50 , rand() % 100 - 50));
		}
		createReady = false;
	}
	if (fmod(f, 4) < 3.5f) createReady = true;
	Component::Update();
	if (spawnLimit <= 0)
		dynamic_cast<Shooter*>(game)->switchSceneTo = new SceneMenu();
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
