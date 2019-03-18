#include "BTComposite.h"



BTComposite::BTComposite()
{
}


BTComposite::~BTComposite()
{
}

BTNode::BTState BTComposite::Update()
{
	return Running;
}

void BTComposite::AddChild(BTNode* node)
{
	node->blackboard = blackboard;
	children.push_back(node);
}

void BTComposite::RemoveChild(BTNode* node)
{
	children.remove(node);
}
