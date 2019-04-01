#include "BTNode.h"
#include "BTNonLeafNode.h"
#include "BehaviourTree.h"
#include <algorithm>


BTNode::BTNode()
{
}


BTNode::~BTNode()
{
}

BTNode::BTState BTNode::Update()
{	
	if (!(std::find(tree->ranLastFrame.begin(), tree->ranLastFrame.end(), this) != tree->ranLastFrame.end()))
	{
		OnStart();
	}
	tree->running.push_back(this);
	return OnUpdate();
}

