#include "PathfindingDemo.h"
#include "SpriteRenderer.h"
#include "Pathfinder.h"


PathfindingDemo::PathfindingDemo()
{
}


PathfindingDemo::~PathfindingDemo()
{
}

void PathfindingDemo::Awake()
{
	Camera::width = 1000;
	Camera::height = 1000;
}

void PathfindingDemo::ObstaclePrefab(GameObject* go)
{
	go->AddComponent(new SpriteRenderer("Assets/background.png"));
	go->transform->SetAbsoluteScale(Vector2(1.0f / 14.0f , 1.0f / 12.0f ));
}

void PathfindingDemo::Setup()
{
	AddPrefab("Obstacle", std::bind(&PathfindingDemo::ObstaclePrefab, this, std::placeholders::_1));

	Pathfinder* finder = new Pathfinder(this, 20, 20);
}
