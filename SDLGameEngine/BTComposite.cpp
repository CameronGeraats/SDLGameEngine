#include "BTComposite.h"



BTComposite::BTComposite()
{
}


BTComposite::~BTComposite()
{
}

BTNonLeafNode* BTComposite::AddChild(BTNode* node)
{
	node->tree = tree;
	node->parent = this;
	children.push_back(node);
	return node->ReturnReference();
	
}

void BTComposite::RemoveChild(BTNode* node)
{
	children.remove(node);
}
