#include "BehaviourTree.h"

BTBlackboard* BehaviourTree::globalBlackboard = nullptr;


BehaviourTree::BehaviourTree()
{
}


BehaviourTree::~BehaviourTree()
{
}

BTRoot* BehaviourTree::Create()
{
	root = new BTRoot();
	return root;
}

void BehaviourTree::Update()
{
	if (root != nullptr)
	{
		root->Update();
	}
}
