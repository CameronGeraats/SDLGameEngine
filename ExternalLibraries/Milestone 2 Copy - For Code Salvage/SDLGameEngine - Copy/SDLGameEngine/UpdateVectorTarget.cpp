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
	if ((gameObject->transform->GetAbsolutePosition() - target).Length() <= 650 && stage == 0)
	{
		/*SteeringAgent* steerAgent = gameObject->GetComponent<Arrive>()->agent;
		steerAgent->steerings.remove(gameObject->GetComponent<Arrive>());
		steerAgent->steerings.remove(gameObject->GetComponent<ObstacleAvoidance>());
		steerAgent->steerings.clear();
		gameObject->GetComponent<Rigidbody>()->SetVelocity(Vector2(0, 0));*/
	}
	//timer += Time::DeltaTime();	//if ((gameObject->transform->GetAbsolutePosition() - target).Length() <= 10 || timer > maxTime)
	/*
	//SDL_SetRenderDrawColor(game->gRenderer, 0xFF, 0x00, 0x00, 0xFF);
	//for (int i = 0; i < 3; i++)// Render pivots point
	//{
	//	for (int j = 0; j < 3; j++)
	//	{
	//		SDL_RenderDrawPoint(Game::gRenderer, targetObject->transform->GetAbsolutePosition().x - i, targetObject->transform->GetAbsolutePosition().y - j);
	//		SDL_RenderDrawPoint(Game::gRenderer, targetObject->transform->GetAbsolutePosition().x + i, targetObject->transform->GetAbsolutePosition().y - j);
	//		SDL_RenderDrawPoint(Game::gRenderer, targetObject->transform->GetAbsolutePosition().x + i, targetObject->transform->GetAbsolutePosition().y + j);
	//		SDL_RenderDrawPoint(Game::gRenderer, targetObject->transform->GetAbsolutePosition().x - i, targetObject->transform->GetAbsolutePosition().y + j);
	//	}
	//}*/
	/*
	//if ((gameObject->transform->GetAbsolutePosition() - targetObject->transform->GetAbsolutePosition()).Length() <= 450 && stage == 0)
	//if ((gameObject->transform->GetAbsolutePosition() - target).Length() <= 650 && stage == 0)
	//{
	//	
	//	target = targetObject->transform->GetAbsolutePosition() - gameObject->transform->GetAbsolutePosition();
	//	target -= target.Normalized() * 350;
	//	targetObject->transform->SetAbsolutePosition(target); // update the targetObject alongside this classes own target Vector2
	//	stage++;
	//}*/
	//if ((gameObject->transform->GetAbsolutePosition() - target).Length() <= 5 && stage == 1)
	if ((gameObject->transform->GetAbsolutePosition() - target).Length() <= 350 && stage == 0)
	{
			//gameObject->transform->SetAbsoluteAngle(atan2((Camera::y+Camera::height/2)-gameObject->transform->GetAbsolutePosition().y, (Camera::x + Camera::width / 2) - gameObject->transform->GetAbsolutePosition().x));
			//gameObject->transform->SetAbsoluteAngle(atan2((target.y)-gameObject->transform->GetAbsolutePosition().y, (target.x) - gameObject->transform->GetAbsolutePosition().x) * 180 / M_PI); 
			gameObject->transform->SetAbsoluteAngle(atan2(((target.x) - gameObject->transform->GetAbsolutePosition().x)*-1, (target.y) - gameObject->transform->GetAbsolutePosition().y) * 180 / M_PI + 180);
			// Getting overwritten somewhere
			//gameObject->transform->SetAbsoluteAngle(atan2((Camera::y+Camera::height/2)-gameObject->transform->GetAbsolutePosition().y, 
			//(Camera::x+Camera::width/2) - gameObject->transform->GetAbsolutePosition().x) * 180 /M_PI);
			//gameObject->GetComponent<Arrive>()->target = gameObject->transform;
			//gameObject->GetComponent<Arrive>();
				
				//SteeringAgent* steerAgent = gameObject->GetComponent<Arrive>()->agent;
				//steerAgent->steerings.remove(gameObject->GetComponent<Arrive>());
				//steerAgent->steerings.remove(gameObject->GetComponent<ObstacleAvoidance>());
				//gameObject->RemoveComponent<Arrive>();
				//gameObject->RemoveComponent<ObstacleAvoidance>();
				//Stop* stop = new Stop(gameObject);
				//stop->target = targetObject->transform;
				////stop->maxAccelaraction = 1;
				////stop->slowRadius = 30;
				////stop->targetRadius = 10;
				//stop->steering.weight = 0.5f;
				//gameObject->AddComponent(stop);
				//steerAgent->steerings.push_back(stop);
				//stop->agent = steerAgent;

				/*SteeringAgent* steerAgent = gameObject->GetComponent<Arrive>()->agent;
				Stop* stop = new Stop(gameObject);
				stop->target = targetObject->transform;
				stop->steering.weight = 0.5f;
				gameObject->AddComponent(stop);
				stop->agent = steerAgent;
				steerAgent->steerings.push_back(stop);*/
				//
				//gameObject->GetComponent<Arrive>()->agent->steerings.clear();
				//gameObject->GetComponent<Arrive>()->maxAccelaraction = 0;
				//gameObject->GetComponent<SteeringAgent>()->velocity = 0;
				//gameObject->RemoveComponents<SteeringAgent>();
				SteeringAgent* steerAgent = gameObject->GetComponent<Arrive>()->agent;
				steerAgent->steerings.remove(gameObject->GetComponent<Arrive>());
				steerAgent->steerings.remove(gameObject->GetComponent<ObstacleAvoidance>());
				steerAgent->steerings.clear();
				steerAgent->steerings.resize(0);
				gameObject->GetComponent<Rigidbody>()->SetVelocity(Vector2(0, 0));
				gameObject->RemoveComponents<Arrive>();
				gameObject->RemoveComponents<ObstacleAvoidance>();
				//game->Destroy(targetObject);
				//
				

				//gameObject->RemoveComponent<Arrive>();
				//gameObject->RemoveComponent<ObstacleAvoidance>();
				//gameObject->RemoveComponent<SteeringAgent>();
				//gameObject->RemoveComponent<Rigidbody>();
				//gameObject->RemoveComponent<BoxCollider>();

				//target.x = Camera::x + rand() % Camera::width;
				//target.y = Camera::y + rand() % Camera::height;
				//targetObject->transform->SetAbsolutePosition(target); // update the targetObject alongside this classes own target Vector2
				//timer = 0;
		gameObject->AddComponent(new EnemyShoot());
		stage++;
			//target.x = gameObject->transform->GetAbsolutePosition().x;
	}
	if (stage == 1)
	{
		gameObject->GetComponent<Rigidbody>()->SetVelocity(Vector2(0,0));
		gameObject->transform->SetAbsoluteAngle(atan2(((target.x) - gameObject->transform->GetAbsolutePosition().x)*-1, (target.y) - gameObject->transform->GetAbsolutePosition().y) * 180 / M_PI + 180);
	}
	//SDL_SetRenderDrawColor(game->gRenderer, 0xFF, 0x00, 0x00, 0xFF);
	//SDL_RenderDrawPoint(game->gRenderer, target.x - Camera::x, target.y - Camera::y);
	Behaviour::Update();
}
