#include "ShouldInvestigate.h"
#include "EnemyBlackboard.h"
#include "BehaviourTree.h"



ShouldInvestigate::ShouldInvestigate()
{
}


ShouldInvestigate::~ShouldInvestigate()
{
}

void ShouldInvestigate::OnStart()
{
}

BTNode::BTState ShouldInvestigate::OnUpdate()
{
	if (static_cast<EnemyBlackboard*>(tree->blackboard)->investigate)
	{
		return BTState::Success;
	}
	return BTState::Failure;
}
