#pragma once
#include "BTBlackboard.h"

class BTNonLeafNode;
class BehaviourTree;
class BTNode
{
public:
	enum BTState
	{
		Success,
		Failure,
		Running
	};

	virtual void OnStart() = 0;
	virtual BTState OnUpdate() = 0;
	BTState Update();
	BehaviourTree* tree;
	BTNonLeafNode* parent = nullptr;
	virtual BTNonLeafNode* ReturnReference() = 0;
	BTNode();
	~BTNode();
protected:
};

