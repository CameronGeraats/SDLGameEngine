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
	root->tree = this;
	return root;
}

void BehaviourTree::Update()
{
	if (root != nullptr)
	{
		root->Update();
	}
	// Time to update for this frame. So flush data for last frame.
	ranLastFrame.clear();
	// Set it to whatever ran this frame
	ranLastFrame = std::list<BTNode*>(running);
	// Flush for next frame
	running.clear();
}
