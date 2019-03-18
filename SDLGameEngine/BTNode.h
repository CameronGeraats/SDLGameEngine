#pragma once
#include "BTBlackboard.h"
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
	virtual BTState Update() = 0;
	BTBlackboard* blackboard;
	BTNode();
	~BTNode();
protected:
};

