#pragma once
#include "Scene.h"
#include "TextRenderer.h"

class Game;

class SceneUpgrade :
	public Scene
{
private:
	TextRenderer* updateStats[5];
public:
	SceneUpgrade();
	SceneUpgrade(Game*);
	~SceneUpgrade();

	void Setup();
	void Update();
};

