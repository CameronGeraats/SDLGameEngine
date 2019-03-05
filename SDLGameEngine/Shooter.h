#pragma once
#include "Game.h"
//#include "FSM.h"
//#include "AudioManager.h"

class Shooter :
	public Game
{
private:
//	Shooter();
public:
	Shooter();
	//static Shooter* Instance() // This static method creates the static instance that can be accessed 'globally'
	//{
	//	static Shooter* instance = new Shooter(); // C++11 will prevent this line from running more than once. Magic statics.
	//	return instance;
	//}
	~Shooter();

	void Awake();
	void Setup();
	void Update();

	GameObject* BulletPrefab();
	GameObject* EnemyPrefab();

	Scene* switchSceneTo = nullptr;

	//StateMachine* m_pFinStateMachine;
	//AudioManager* m_pAudioManager;
};

