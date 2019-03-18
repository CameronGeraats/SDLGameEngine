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
	static BTBlackboard* globalBlackboard;
	BTBlackboard* blackboard;
};

