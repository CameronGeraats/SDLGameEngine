#include "CanSeePlayer.h"
#include "BehaviourTree.h"
#include "GameObject.h"
#include "Transform.h"


CanSeePlayer::CanSeePlayer()
{
}


CanSeePlayer::~CanSeePlayer()
{
}

void CanSeePlayer::OnStart()
{
	enemy = static_cast<EnemyBlackboard*>(tree->blackboard)->enemy;
	static_cast<EnemyBlackboard*>(tree->blackboard)->investigate = true;

}

BTNode::BTState CanSeePlayer::OnUpdate()
{
	if (enemy->detectedPlayer != nullptr)
	{
		static_cast<EnemyBlackboard*>(tree->blackboard)->lastKnowPos = enemy->detectedPlayer->transform->GetAbsolutePosition();
		return BTState::Success;
	}
	return BTState::Failure;
}
