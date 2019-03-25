#pragma once
#include "Component.h"
#include "BTRoot.h"
#include "BTBlackboard.h"
#include "BTSelector.h"
#include "BTSequence.h"
#include "BTInverter.h"


class BehaviourTree :
	public Component
{
public:
	BehaviourTree();
	~BehaviourTree();
	static BTBlackboard* globalBlackboard;
	BTBlackboard* blackboard;
	BTRoot* Create();
	void Update();
private:
	BTRoot * root;
};

