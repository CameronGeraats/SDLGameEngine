#include "Investigate.h"
#include "BehaviourTree.h"
#include "UpdateVectorTarget.h"
#include "Camera.h"
#include "Time.h"

Investigate::Investigate()
{
}


Investigate::~Investigate()
{
}

void Investigate::OnStart()
{
	enemy = static_cast<EnemyBlackboard*>(tree->blackboard)->enemy;
	enemy->gameObject->GetComponent<SteeringAgent>()->enabled = true;
	enemy->gameObject->GetComponent<UpdateVectorTarget>()->center = static_cast<EnemyBlackboard*>(tree->blackboard)->lastKnowPos;
	enemy->gameObject->GetComponent<UpdateVectorTarget>()->radius = 150;
	timer = 0;
}

BTNode::BTState Investigate::OnUpdate()
{
	timer += Time::DeltaTime();
	if (timer >= 5)
	{
		static_cast<EnemyBlackboard*>(tree->blackboard)->investigate = false;
	}
	return BTState::Running;
}
