#include "EnemyShoot.h"
#include "Game.h"
#include "Time.h"


EnemyShoot::EnemyShoot()
{
}


EnemyShoot::~EnemyShoot()
{
}

void EnemyShoot::Update()
{
	Behaviour::Update(); // ?? neccesary??
	float f = Time::TimeElapsed();
	if (fmod(f, 2)>1.50 && shootready) //timer += Time::DeltaTime();	//timer += 0.033f;	//if (timer >= 20.0f && timer < 25.0f)
	{
		Instantiate(game->Prefab("Bullet"), gameObject->transform->GetAbsolutePosition() - 50 * gameObject->transform->Up(), gameObject->transform->GetAbsoluteAngle() + 180);
		//timer = 0;
		shootready = false;
	}
	else if (fmod(f, 2) < 1.5) shootready = true;
}
