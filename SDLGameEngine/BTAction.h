#pragma once
#include "BTNode.h"
class BTAction :
	public BTNode
{
public:
	BTAction();
	~BTAction();
	virtual void OnStart() = 0;
	virtual BTState Update();
};

