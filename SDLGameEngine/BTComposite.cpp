#include "BTComposite.h"



BTComposite::BTComposite()
{
}


BTComposite::~BTComposite()
{
}

BTNonLeafNode* BTComposite::AddChild(BTNode* node)
{
	node->blackboard = blackboard;
	node->parent = this;
	children.push_back(node);
	return node->ReturnReference();
	
}

void BTComposite::RemoveChild(BTNode* node)
{
	children.remove(node);
}
