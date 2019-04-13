#include "Shoot.h"
#include "Input.h"
#include "Game.h"
#include "Time.h"
#include "Shooter.h"
#include "Scene1.h"

Shoot::Shoot()
{
}


Shoot::~Shoot()
{
}

void Shoot::Update()
{
	Behaviour::Update();
	// Shoot
	laserActive -= Time::DeltaTime();
	if (dynamic_cast<Scene1*>(dynamic_cast<Shooter*>(game)->GetCurrentScene()) != nullptr) {
		if (laserActive <= 0)
		{
			if (Input::GetMouseButton(SDL_BUTTON_LEFT))
			//if (Input::GetMouseButtonDown(SDL_BUTTON_LEFT))
				//if (Input::GetKeyDown(SDLK_SPACE))
			{
				Instantiate(game->Prefab("Bullet"), gameObject->transform->GetAbsolutePosition() + 45 * gameObject->transform->Right() + 10 * gameObject->transform->Up(), gameObject->transform->GetAbsoluteAngle() - 90); //-50, 180
				float a, b, c;
				dynamic_cast<Shooter*>(game)->playerStats->GetUpgradeStats(a, b, c);
				laserActive = 0.35f / c;
			}
		//	if (Input::GetMouseButtonDown(SDL_BUTTON_RIGHT))
		//		//if (Input::GetKeyDown(SDLK_SPACE))
		//	{
		//		// To be used for SPECIAL weapons/ items
		//		//Instantiate(game->Prefab("Bullet"), gameObject->transform->GetAbsolutePosition() - 50 * gameObject->transform->Up() + 0 * gameObject->transform->Right(), gameObject->transform->GetAbsoluteAngle() + 180);
		//		//Instantiate(game->Prefab("Bullet"), gameObject->transform->GetAbsolutePosition() - 75 * gameObject->transform->Up() + 0 * gameObject->transform->Right(), gameObject->transform->GetAbsoluteAngle() + 180);
		//		//Instantiate(game->Prefab("Bullet"), gameObject->transform->GetAbsolutePosition() - 25 * gameObject->transform->Up() - 0 * gameObject->transform->Right(), gameObject->transform->GetAbsoluteAngle() + 180);
		//		laser = Instantiate(game->Prefab("Laser"), gameObject->transform->GetAbsolutePosition() + 477 * gameObject->transform->Right() + 10 * gameObject->transform->Up(), gameObject->transform->GetAbsoluteAngle() - 90);
		//		laserActive = 1.0f;
		//	}
		}
		//else
		//{
		//	laser->transform->SetAbsolutePosition(gameObject->transform->GetAbsolutePosition() + 477 * gameObject->transform->Right() + 10 * gameObject->transform->Up()); // Update laser
		//	laser->transform->SetAbsoluteAngle(gameObject->transform->GetAbsoluteAngle() - 90);
		//}
	}
}
