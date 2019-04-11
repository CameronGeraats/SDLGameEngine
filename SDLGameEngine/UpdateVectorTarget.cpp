#include "UpdateVectorTarget.h"
#include <stdlib.h>
#include <time.h>
#include "Vector2.h"
#include "GameObject.h"
#include "Transform.h"
#include "Time.h"
#include "Camera.h"
#include "Game.h"
#include "EnemyShoot.h"
#include "Arrive.h"
#include "ObstacleAvoidance.h"
#include "SteeringAgent.h"
#include "BoxCollider.h"
#include "Rigidbody.h"
#include "Stop.h"

UpdateVectorTarget::UpdateVectorTarget()
{
}

UpdateVectorTarget::UpdateVectorTarget(GameObject* go) : Behaviour(go)
{
}

UpdateVectorTarget::~UpdateVectorTarget()
{
}

void UpdateVectorTarget::Update()
{
/*timer += Time::DeltaTime();
if ((gameObject->transform->GetAbsolutePosition() - target).Length() <= 10 || timer > maxTime)
{
	//target.x = Camera::x + rand() % Camera::width;
	//target.y = Camera::y + rand() % Camera::height;
	float theta = rand();
	target.x = Camera::x + center.x + radius * cos(theta);
	target.y = Camera::y + center.y + radius * sin(theta);

	targetObject->transform->SetAbsolutePosition(target);
	timer = 0;
}*/
	if ((gameObject->transform->GetAbsolutePosition() - target).Length() <= 650 && stage == 0)
	{

	}

	if (stage == 0 && (gameObject->transform->GetAbsolutePosition() - target).Length() <= 350)
	{
		gameObject->transform->SetAbsoluteAngle(atan2(((target.x) - gameObject->transform->GetAbsolutePosition().x)*-1, (target.y) - gameObject->transform->GetAbsolutePosition().y) * 180 / M_PI + 180);
		SteeringAgent* steerAgent = gameObject->GetComponent<Arrive>()->agent;
		steerAgent->steerings.remove(gameObject->GetComponent<Arrive>());
		steerAgent->steerings.remove(gameObject->GetComponent<ObstacleAvoidance>());
		steerAgent->steerings.clear();
		steerAgent->steerings.resize(0);
		gameObject->GetComponent<Rigidbody>()->SetVelocity(Vector2(0, 0));
		gameObject->RemoveComponents<Arrive>();
		gameObject->RemoveComponents<ObstacleAvoidance>();
		gameObject->AddComponent(new EnemyShoot());
		stage++;
			//target.x = gameObject->transform->GetAbsolutePosition().x;
	}
	if (stage == 1) // Should be a behaviour tree action? Used to stop movement
	{
		gameObject->GetComponent<Rigidbody>()->SetVelocity(Vector2(0,0));
		gameObject->transform->SetAbsoluteAngle(atan2(((target.x) - gameObject->transform->GetAbsolutePosition().x)*-1, (target.y) - gameObject->transform->GetAbsolutePosition().y) * 180 / M_PI + 180);
	}
	//SDL_SetRenderDrawColor(game->gRenderer, 0xFF, 0x00, 0x00, 0xFF);
	//SDL_RenderDrawPoint(game->gRenderer, target.x - Camera::x, target.y - Camera::y);
	Behaviour::Update();
}
