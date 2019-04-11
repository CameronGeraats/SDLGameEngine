#pragma once
#include "Scene.h"


class Game;

class SceneUpgrade :
	public Scene
{
public:
	SceneUpgrade();
	SceneUpgrade(Game*);
	~SceneUpgrade();

	void Setup();
};

