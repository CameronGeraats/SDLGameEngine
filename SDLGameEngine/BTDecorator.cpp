#include "BTDecorator.h"



BTDecorator::BTDecorator()
{
}


BTDecorator::~BTDecorator()
{
}

void BTDecorator::SetNode(BTNode* node)
{
	node->blackboard = blackboard;
	child = node;
}

