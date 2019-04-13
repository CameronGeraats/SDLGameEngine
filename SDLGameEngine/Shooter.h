#pragma once
#include "Game.h"
//#include "FSM.h"
//#include "AudioManager.h"
#include "PlayerStats.h"

class Shooter :
	public Game
{
public:
	Shooter();
	~Shooter();

	void Awake();
	void Setup();
	void Update();//

	void EnemyBulletPrefab(GameObject* go);
	void BulletPrefab(GameObject* go);
	void LaserPrefab(GameObject* go);
	void Enemy1Prefab(GameObject* go);
	void Enemy2Prefab(GameObject* go);
	void Enemy3Prefab(GameObject* go);
	void WallPrefab(GameObject* go);

	Scene* switchSceneTo = nullptr;
	static TTF_Font* textFont;
	static std::string fontFile;
	static SDL_Color textColour;

	PlayerStats* playerStats;
	//StateMachine* m_pFinStateMachine;
	//AudioManager* m_pAudioManager;
};
