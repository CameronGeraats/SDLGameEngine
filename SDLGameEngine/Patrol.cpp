#include "Patrol.h"
#include "BehaviourTree.h"
#include "UpdateVectorTarget.h"
#include "Camera.h"


Patrol::Patrol()
{
}


Patrol::~Patrol()
{
}

void Patrol::OnStart()
{
	enemy = static_cast<EnemyBlackboard*>(tree->blackboard)->enemy;
	enemy->gameObject->GetComponent<SteeringAgent>()->enabled = true;
}

BTNode::BTState Patrol::OnUpdate()
{
	enemy->gameObject->GetComponent<UpdateVectorTarget>()->center = Vector2(Camera::width, Camera::height) / 2;
	enemy->gameObject->GetComponent<UpdateVectorTarget>()->radius = Camera::height / 2;
	return BTState::Running;
}
