#pragma once
#include "BTNode.h"
#include <list>
class BTComposite :
	public BTNode
{
public:
	BTComposite();
	~BTComposite();
	std::list<BTNode*> children;
	virtual BTState Update();
	void AddChild(BTNode* node);
	void RemoveChild(BTNode* node);
};

