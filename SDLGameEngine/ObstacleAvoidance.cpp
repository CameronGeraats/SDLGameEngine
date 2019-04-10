#include "ObstacleAvoidance.h"
#include "Game.h"
#include "Physics.h"
#include "RaycastHit.h"
#include "Collider.h"
<<<<<<< HEAD
#include "BoxCollider.h"
=======
>>>>>>> upstream/ExampleProjects
#include "Rect.h"
#include "Arrive.h"

ObstacleAvoidance::ObstacleAvoidance()
{
}


ObstacleAvoidance::~ObstacleAvoidance()
{
}

void ObstacleAvoidance::Start()
{
	if (target == nullptr)
	{
		target = Instantiate("target")->transform;
	}
}

<<<<<<< HEAD
void ObstacleAvoidance::Update() // Changed to prevent 90degree head-on stuck collision
								// Will still clip edges of obstacles, until I switch to double raycast
	// Okay so I added the second raycast
=======
void ObstacleAvoidance::Update()
>>>>>>> upstream/ExampleProjects
{
	Vector2 direction = -gameObject->transform->Up();
	if (gameObject->GetComponent<Arrive>())
	{
		direction = gameObject->GetComponent<Arrive>()->target->GetAbsolutePosition() - gameObject->transform->GetAbsolutePosition();
		direction = direction.Normalize();
	}
<<<<<<< HEAD
	Vector2 boxCol = gameObject->GetComponent<BoxCollider>()->GetDimension() * gameObject->transform->Up();
	RaycastHit hit = game->physics->Raycast(gameObject->transform->GetAbsolutePosition()-boxCol/2, direction, lookAhead, avoidLayer);
	RaycastHit hit2 = game->physics->Raycast(gameObject->transform->GetAbsolutePosition()+boxCol/2, direction, lookAhead, avoidLayer);
	
=======
	RaycastHit hit = game->physics->Raycast(gameObject->transform->GetAbsolutePosition(), direction, lookAhead, avoidLayer);
>>>>>>> upstream/ExampleProjects
	if (hit.collider != nullptr)
	{
		Vector2 toVec = gameObject->transform->GetAbsolutePosition() - hit.point;
		float dist = toVec.Dot(hit.normal);
<<<<<<< HEAD
		float dotprodangle = acos((dist) / (hit.normal.Length()) / toVec.Length()) * 180.0f / M_PI;
		if (dotprodangle > 75.0f || dotprodangle < 115.0f)
		{
			Vector2 vecPerp(hit.point.x - toVec.y, hit.point.y - toVec.x);
			target->SetAbsolutePosition(hit.point + hit.normal * dist + vecPerp);
		}
		else
			target->SetAbsolutePosition(hit.point + hit.normal * dist);
		/*SDL_SetRenderDrawColor(Game::gRenderer, 0x00, 0x00, 0xFF, 0xFF);
		SDL_RenderDrawLine(Game::gRenderer, hit.point.x - Camera::x, hit.point.y - Camera::y, target->GetAbsolutePosition().x - Camera::x, target->GetAbsolutePosition().y - Camera::y);
		SDL_RenderDrawRect(Game::gRenderer, new Rect(target->GetAbsolutePosition().x - Camera::x - 5, target->GetAbsolutePosition().y - Camera::y - 5, 10, 10));*/
		Seek::Update();
	}
	else if (hit2.collider != nullptr)
	{
		Vector2 toVec = gameObject->transform->GetAbsolutePosition() - hit2.point;
		float dist = toVec.Dot(hit2.normal);
		float dotprodangle = acos((dist) / (hit2.normal.Length()) / toVec.Length()) * 180.0f / M_PI;
		if (dotprodangle > 75.0f || dotprodangle < 115.0f)
		{
			Vector2 vecPerp(hit2.point.x - toVec.y, hit2.point.y - toVec.x);
			target->SetAbsolutePosition(hit2.point + hit2.normal * dist + vecPerp);
		}
		else
			target->SetAbsolutePosition(hit2.point + hit2.normal * dist);
		/*SDL_SetRenderDrawColor(Game::gRenderer, 0x00, 0x00, 0xFF, 0xFF);
		SDL_RenderDrawLine(Game::gRenderer, hit.point.x - Camera::x, hit.point.y - Camera::y, target->GetAbsolutePosition().x - Camera::x, target->GetAbsolutePosition().y - Camera::y);
		SDL_RenderDrawRect(Game::gRenderer, new Rect(target->GetAbsolutePosition().x - Camera::x - 5, target->GetAbsolutePosition().y - Camera::y - 5, 10, 10));*/
=======
		target->SetAbsolutePosition(hit.point + hit.normal * dist);
		SDL_SetRenderDrawColor(Game::gRenderer, 0x00, 0x00, 0xFF, 0xFF);
		SDL_RenderDrawLine(Game::gRenderer, hit.point.x - Camera::x, hit.point.y - Camera::y, target->GetAbsolutePosition().x - Camera::x, target->GetAbsolutePosition().y - Camera::y);
		SDL_RenderDrawRect(Game::gRenderer, new Rect(target->GetAbsolutePosition().x - Camera::x - 5, target->GetAbsolutePosition().y - Camera::y - 5, 10, 10));
>>>>>>> upstream/ExampleProjects
		Seek::Update();
	}
	else
	{
		steering.linear = 0;
	}
}

