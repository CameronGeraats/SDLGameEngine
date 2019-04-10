#include "BTRoot.h"



BTRoot::BTRoot()
{
}


BTRoot::~BTRoot()
{
}

void BTRoot::OnStart()
{
	
}

BTNode::BTState BTRoot::OnUpdate()
{
	for (BTNode* node : children)
	{
		node->Update();
	}
	return BTNode::BTState::Running;
}
