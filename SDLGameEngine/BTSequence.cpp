#include "BTSequence.h"



BTSequence::BTSequence()
{
}


BTSequence::~BTSequence()
{
}

BTNode::BTState BTSequence::OnUpdate()
{
	for (BTNode* node : children)
	{
		if (node->Update() == BTNode::BTState::Success)
		{
			continue;
		}
		else if(node->Update() == BTNode::BTState::Failure)
		{
			return BTNode::BTState::Failure;
		}
		else if (node->Update() == BTNode::BTState::Running)
		{
			return BTNode::BTState::Running;
		}
	}
	return BTNode::BTState::Success;
}
