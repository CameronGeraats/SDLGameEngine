#pragma once
#include "BTComposite.h"
#include <list>
class BTSequence
	:public BTComposite
{
public:
	BTSequence();
	~BTSequence();
	BTState OnUpdate();
};

