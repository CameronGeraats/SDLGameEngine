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
	void Update();//

	void BulletPrefab(GameObject* go);
	void EnemyPrefab(GameObject* go);
	void WallPrefab(GameObject* go);
	
	Scene* switchSceneTo = nullptr;
	TTF_Font* textFont;
	SDL_Color* textColour;
	//StateMachine* m_pFinStateMachine;
	//AudioManager* m_pAudioManager;
};

