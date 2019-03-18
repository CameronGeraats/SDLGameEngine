#pragma once
#include "Component.h"
#include "BTRoot.h"
#include "BTBlackboard.h"
class BehaviourTree :
	public Component
{
public:
	BehaviourTree();
	~BehaviourTree();
	BTRoot* root;
	BTBlackboard* blackboard;
};

