#pragma once
#include "BTNonLeafNode.h"
#include <list>
class BTComposite :
	public BTNonLeafNode
{
public:
	BTComposite();
	~BTComposite();
	std::list<BTNode*> children;
	virtual BTState Update() = 0;
	BTNonLeafNode* AddChild(BTNode* node);
	void RemoveChild(BTNode* node);
};

