#pragma once
#include "Game.h"
class PathfindingDemo :
	public Game
{
public:
	PathfindingDemo();
	~PathfindingDemo();

	void ObstaclePrefab(GameObject* go);

	void Awake();
	void Setup();
};

