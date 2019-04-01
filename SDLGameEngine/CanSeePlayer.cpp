#include "CanSeePlayer.h"
#include "BehaviourTree.h"


CanSeePlayer::CanSeePlayer()
{
}


CanSeePlayer::~CanSeePlayer()
{
}

void CanSeePlayer::OnStart()
{
	enemy = static_cast<EnemyBlackboard*>(tree->blackboard)->enemy;
}

BTNode::BTState CanSeePlayer::OnUpdate()
{
	if (enemy->detectedPlayer != nullptr)
	{
		return BTState::Success;
	}
	return BTState::Failure;
}
