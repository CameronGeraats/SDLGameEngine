#pragma once
#include "Scene.h"
class Game;
class SceneMenu :
	public Scene
{
public:
	SceneMenu();
	SceneMenu(Game*);
	~SceneMenu();

	void Setup();
	void Update();
};

