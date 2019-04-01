#include "Patrol.h"
#include "BehaviourTree.h"



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
	/*if (enemy == nullptr)
	{
		enemy = static_cast<EnemyBlackboard*>(tree->blackboard)->enemy;
	}
	enemy->gameObject->GetComponent<SteeringAgent>()->enabled = true;*/
	return BTState::Running;
}
