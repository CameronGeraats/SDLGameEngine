#pragma once
#include "BTNode.h"
class BTNonLeafNode :
	public BTNode
{
public:
	BTNonLeafNode();
	~BTNonLeafNode();
	virtual void OnStart();
	virtual BTNonLeafNode* AddChild(BTNode* node) = 0;
	inline virtual BTNonLeafNode* End() { return this->parent; }
	virtual BTState OnUpdate() = 0;
	inline BTNonLeafNode* ReturnReference() { return this; }
};

