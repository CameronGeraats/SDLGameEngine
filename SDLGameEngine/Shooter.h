#pragma once
#include "Game.h"
<<<<<<< HEAD
//#include "FSM.h"
//#include "AudioManager.h"

=======
>>>>>>> upstream/ExampleProjects
class Shooter :
	public Game
{
public:
	Shooter();
	~Shooter();

	void Awake();
	void Setup();
<<<<<<< HEAD
	void Update();//

	void EnemyBulletPrefab(GameObject* go);
	void BulletPrefab(GameObject* go);
	void LaserPrefab(GameObject* go);
	void EnemyPrefab(GameObject* go);
	void WallPrefab(GameObject* go);
	
	Scene* switchSceneTo = nullptr;
	static TTF_Font* textFont;
	static SDL_Color textColour;

	//StateMachine* m_pFinStateMachine;
	//AudioManager* m_pAudioManager;
=======

	void BulletPrefab(GameObject* go);
	void EnemyPrefab(GameObject* go);
	void WallPrefab(GameObject* go);
>>>>>>> upstream/ExampleProjects
};

