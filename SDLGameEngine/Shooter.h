#pragma once
#include "Game.h"
//#include "FSM.h"
//#include "AudioManager.h"

class Shooter :
	public Game
{
public:
	Shooter();
	~Shooter();

	void Awake();
	void Setup();

	void BulletPrefab(GameObject* go);
	void EnemyPrefab(GameObject* go);
	void WallPrefab(GameObject* go);
	Scene* switchSceneTo = nullptr;

	//StateMachine* m_pFinStateMachine;
	//AudioManager* m_pAudioManager;
};

