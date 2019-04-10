#include "BTSelector.h"



BTSelector::BTSelector()
{
}


BTSelector::~BTSelector()
{
}

BTNode::BTState BTSelector::OnUpdate()
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

