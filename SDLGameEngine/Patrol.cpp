#include "Patrol.h"



Patrol::Patrol()
{
}


Patrol::~Patrol()
{
}

void Patrol::OnStart()
{
	
	enemy = static_cast<EnemyBlackboard*>(blackboard)->enemy;
	enemy->gameObject->GetComponent<SteeringAgent>()->enabled = true;
}

BTNode::BTState Patrol::Update()
{
	if (enemy == nullptr)
	{
		enemy = static_cast<EnemyBlackboard*>(blackboard)->enemy;
	}
	enemy->gameObject->GetComponent<SteeringAgent>()->enabled = true;
	return BTState::Running;
}
