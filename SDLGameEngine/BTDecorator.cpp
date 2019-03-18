#include "BTDecorator.h"



BTDecorator::BTDecorator()
{
}


BTDecorator::~BTDecorator()
{
}

BTNonLeafNode* BTDecorator::AddChild(BTNode* node)
{
	node->blackboard = blackboard;
	node->parent = this;
	child = node;
	return node->ReturnReference();
}

