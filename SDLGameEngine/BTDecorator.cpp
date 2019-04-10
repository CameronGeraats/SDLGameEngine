#include "BTDecorator.h"



BTDecorator::BTDecorator()
{
}


BTDecorator::~BTDecorator()
{
}

BTNonLeafNode* BTDecorator::AddChild(BTNode* node)
{
	node->tree = tree;
	node->parent = this;
	child = node;
	return node->ReturnReference();
}

