#pragma once
#include "BTNode.h"
class BTDecorator :
	public BTNode
{
public:
	BTDecorator();
	~BTDecorator();
	virtual BTState Update();
	void SetNode(BTNode* node);
protected:
	BTNode* child;
};

