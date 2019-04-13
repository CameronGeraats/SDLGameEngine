#pragma once
#include "Scene.h"
class Game;
class Scene1 :
	public Scene
{
private:
	float time;
public:
	Scene1();
	Scene1(Game*);
	~Scene1();

	void Setup();
	void Update();
};
