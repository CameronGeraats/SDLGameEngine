#include "Shoot.h"
#include "Input.h"
#include "Game.h"
#include "Time.h"



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
	if (laserActive <= 0)
	{
		SDL_MouseButtonEvent Click;
		Click.button = SDL_BUTTON_LEFT;
		if (Input::GetMouseButtonDown(Click))
			//if (Input::GetKeyDown(SDLK_SPACE))
		{
			Instantiate(game->Prefab("Bullet"), gameObject->transform->GetAbsolutePosition() - 50 * gameObject->transform->Up(), gameObject->transform->GetAbsoluteAngle() + 180);
		}
		Click.button = SDL_BUTTON_RIGHT;
		if (Input::GetMouseButtonDown(Click))
			//if (Input::GetKeyDown(SDLK_SPACE))
		{
			// To be used for SPECIAL weapons/ items
			//Instantiate(game->Prefab("Bullet"), gameObject->transform->GetAbsolutePosition() - 50 * gameObject->transform->Up() + 0 * gameObject->transform->Right(), gameObject->transform->GetAbsoluteAngle() + 180);
			//Instantiate(game->Prefab("Bullet"), gameObject->transform->GetAbsolutePosition() - 75 * gameObject->transform->Up() + 0 * gameObject->transform->Right(), gameObject->transform->GetAbsoluteAngle() + 180);
			//Instantiate(game->Prefab("Bullet"), gameObject->transform->GetAbsolutePosition() - 25 * gameObject->transform->Up() - 0 * gameObject->transform->Right(), gameObject->transform->GetAbsoluteAngle() + 180);
			laser = Instantiate(game->Prefab("Laser"), gameObject->transform->GetAbsolutePosition() - 462 * gameObject->transform->Up() + 5 * gameObject->transform->Right(), gameObject->transform->GetAbsoluteAngle() + 180);

			laserActive = 1.0f;
		}
	}
	else
	{
		laser->transform->SetAbsolutePosition(gameObject->transform->GetAbsolutePosition() - 462 * gameObject->transform->Up() + 5 * gameObject->transform->Right()); // Update laser
		laser->transform->SetAbsoluteAngle(gameObject->transform->GetAbsoluteAngle() + 180);
	}
}
