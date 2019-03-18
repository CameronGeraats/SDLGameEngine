#pragma once
#include "BTComposite.h"
#include <list>
class BTSequence
	:BTComposite
{
public:
	BTSequence();
	~BTSequence();
	BTState Update();
};

