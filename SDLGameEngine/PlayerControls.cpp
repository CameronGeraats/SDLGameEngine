#include "PlayerControls.h"
#include "GameObject.h"
#include "Transform.h"
#include "Time.h"
#include "Input.h"
#include "Game.h"
#include "RaycastHit.h"
#include "Shooter.h"
#include "SceneMenu.h"

PlayerControls::PlayerControls(SpriteRenderer* player)
{
	//target = new Transform();
	playerSprite = player;
}


PlayerControls::~PlayerControls()
{
}

void PlayerControls::Update()
{
	Shooter* temp = dynamic_cast<Shooter*>(game);
	//std::cout << "X: "<< Camera::x << "Y: " << Camera::y << "W: " << Camera::width << "H: " << Camera::height << std::endl;
	if (Input::GetKey(SDLK_1))
	{
		playerSprite->SetSprite(new Sprite("Assets/Player/handgun3.png"));
		temp->playerStats->currentWep = PlayerStats::pistol;
	}
	else if (Input::GetKey(SDLK_2))
	{
		playerSprite->SetSprite(new Sprite("Assets/Player/rifle3.png"));
		temp->playerStats->currentWep = PlayerStats::rifle;
	}
	else if (Input::GetKey(SDLK_3))
	{
		playerSprite->SetSprite(new Sprite("Assets/Player/shotgun3.png"));
		temp->playerStats->currentWep = PlayerStats::shotgun;
	}
	// Horizontal
	int horizontal = Input::GetKey(SDLK_d) ? 1 : Input::GetKey(SDLK_a) ? -1 : 0;
	// Vertical
	int vertical = Input::GetKey(SDLK_w) ? -1 : Input::GetKey(SDLK_s) ? 1 : 0;
	// Movement, disabled
	//gameObject->transform->SetAbsolutePositionDelta(Vector2(horizontal * xSpeed * Time::DeltaTime(), vertical * ySpeed * Time::DeltaTime()));

	// Orientation
	target->SetAbsolutePosition(Input::GetMousePosition() + Vector2(Camera::x, Camera::y));
	Vector2 toVector = target->GetAbsolutePosition() - gameObject->transform->GetAbsolutePosition();
	if (toVector.Length() > 0)
	{
		gameObject->transform->SetAbsoluteAngle(atan2(toVector.y, toVector.x) * 180 / M_PI);
	}

	RaycastHit hit = game->physics->Raycast(gameObject->transform->GetAbsolutePosition(), gameObject->transform->Right(), 10000, ~game->physics->Layer_2);

	/*if (Input::GetKey(SDLK_ESCAPE))
		dynamic_cast<Shooter*>(game)->switchSceneTo = new SceneMenu();*/
}
