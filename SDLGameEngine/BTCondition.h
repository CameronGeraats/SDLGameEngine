#pragma once
#include "BTNode.h"
class BTCondition :
	public BTNode
{
public:
	BTCondition();
	~BTCondition();
	virtual void OnStart() = 0;
	virtual BTState OnUpdate() = 0;
	inline BTNonLeafNode* ReturnReference() { return this->parent; }
};

