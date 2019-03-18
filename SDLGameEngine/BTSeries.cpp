#include "BTSeries.h"



BTSeries::BTSeries()
{
}


BTSeries::~BTSeries()
{
}

BTNode::BTState BTSeries::Update()
{
	for (BTNode* node : children)
	{
		if (node->Update() == BTNode::BTState::Failure)
		{
			continue;
		}
		else if (node->Update() == BTNode::BTState::Success)
		{
			return BTNode::BTState::Success;
		}
		else if (node->Update() == BTNode::BTState::Running)
		{
			return BTNode::BTState::Running;
		}
	}
	return BTNode::BTState::Failure;
}

