#include "PlayerControls.h"
#include "GameObject.h"
#include "Transform.h"
#include "Time.h"
#include "Input.h"
#include "Game.h"
#include "RaycastHit.h"

PlayerControls::PlayerControls()
{
}


PlayerControls::~PlayerControls()
{
}

void PlayerControls::Update()
{
<<<<<<< HEAD
	//// Horizontal
	//int horizontal = Input::GetKey(SDLK_d) ? 1 : Input::GetKey(SDLK_a) ? -1 : 0;
	//
	//// Vertical
	//int vertical = Input::GetKey(SDLK_w) ? -1 : Input::GetKey(SDLK_s) ? 1 : 0;

	//gameObject->transform->SetAbsolutePositionDelta(Vector2(horizontal * xSpeed * Time::DeltaTime(), vertical * ySpeed * Time::DeltaTime()));
	//
	//// Orientation
	//if (vertical != 0 || horizontal != 0)
	//{
	//	gameObject->transform->SetAbsoluteAngle(atan2(vertical, horizontal) * 180 / M_PI);
	//}

	//gameObject->transform->SetAbsoluteAngle(atan2(float(Input::GetMousePosition().y)-(Camera::height/2), float(Input::GetMousePosition().x) - (Camera::width/2)) * 180 / M_PI);
	gameObject->transform->SetAbsoluteAngle(atan2(float(Input::GetMousePosition()->GetAbsolutePosition().y)-(Camera::height/2), float(Input::GetMousePosition()->GetAbsolutePosition().x) - (Camera::width/2)) * 180 / M_PI);
	
=======
	// Horizontal
	int horizontal = Input::GetKey(SDLK_d) ? 1 : Input::GetKey(SDLK_a) ? -1 : 0;
	
	// Vertical
	int vertical = Input::GetKey(SDLK_w) ? -1 : Input::GetKey(SDLK_s) ? 1 : 0;

	gameObject->transform->SetAbsolutePositionDelta(Vector2(horizontal * xSpeed * Time::DeltaTime(), vertical * ySpeed * Time::DeltaTime()));
	
	// Orientation
	target->SetAbsolutePosition(Input::GetMousePosition() + Vector2(Camera::x, Camera::y));
	Vector2 toVector = target->GetAbsolutePosition() - gameObject->transform->GetAbsolutePosition();
	if (toVector.Length() > 0)
	{
		gameObject->transform->SetAbsoluteAngle(atan2(toVector.y, toVector.x) * 180 / M_PI);
	}
>>>>>>> upstream/ExampleProjects

	RaycastHit hit = game->physics->Raycast(gameObject->transform->GetAbsolutePosition(), gameObject->transform->Right(), 10000, ~game->physics->Layer_2);
}
