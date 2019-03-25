#include "CanSeePlayer.h"
#include "EnemyBlackboard.h"


CanSeePlayer::CanSeePlayer()
{
}


CanSeePlayer::~CanSeePlayer()
{
}

BTNode::BTState CanSeePlayer::Update()
{
	Enemy* enemy = static_cast<EnemyBlackboard*>(blackboard)->enemy; 
	if (enemy->detectedPlayer != nullptr)
	{
		return BTState::Success;
	}
	return BTState::Failure;
}
