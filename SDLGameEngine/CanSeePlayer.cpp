#include "CanSeePlayer.h"
#include "EnemyBlackboard.h"
#include "BehaviourTree.h"


CanSeePlayer::CanSeePlayer()
{
}


CanSeePlayer::~CanSeePlayer()
{
}

BTNode::BTState CanSeePlayer::OnUpdate()
{
	Enemy* enemy = static_cast<EnemyBlackboard*>(tree->blackboard)->enemy;
	if (enemy->detectedPlayer != nullptr)
	{
		return BTState::Success;
	}
	return BTState::Failure;
}
