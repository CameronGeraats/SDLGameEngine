#include "BTRoot.h"



BTRoot::BTRoot()
{
}


BTRoot::~BTRoot()
{
}

BTNode::BTState BTRoot::Update()
{
	for (BTNode* node : children)
	{
		node->Update();
	}
	return BTNode::BTState::Running;
}
