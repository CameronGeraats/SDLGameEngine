#pragma once
#include "Component.h"
#include "BTRoot.h"
#include "BTBlackboard.h"
#include "BTSelector.h"
#include "BTSequence.h"
#include "BTInverter.h"
#include <list>


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
	std::list<BTNode*> ranLastFrame;
	std::list<BTNode*> running;
private:
	BTRoot * root;
};

