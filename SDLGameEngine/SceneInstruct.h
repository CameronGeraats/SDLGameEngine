#pragma once
#include "Scene.h"
class Game;
class SceneInstruct :
	public Scene
{
public:
	SceneInstruct();
	SceneInstruct(Game*);
	~SceneInstruct();

	void Setup();
	void Update();
};

