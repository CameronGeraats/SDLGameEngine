#include "Shoot.h"
#include "Input.h"
#include "Game.h"



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
	SDL_MouseButtonEvent Click;
	Click.button = SDL_BUTTON_LEFT;
	if (Input::GetMouseButtonDown(Click))
	//if (Input::GetKeyDown(SDLK_SPACE))
	{
		Instantiate(game->Prefab("Bullet"), gameObject->transform->GetAbsolutePosition() - 50 * gameObject->transform->Up(), gameObject->transform->GetAbsoluteAngle() + 180);
	}
	//Click.button = SDL_BUTTON_RIGHT;
	//if (Input::GetMouseButtonDown(Click))
		//if (Input::GetKeyDown(SDLK_SPACE))
	//{
		// To be used for SPECIAL weapons/ items
		//Instantiate(game->Prefab("Bullet"), gameObject->transform->GetAbsolutePosition() - 50 * gameObject->transform->Up(), gameObject->transform->GetAbsoluteAngle() + 180);
	//}
}
