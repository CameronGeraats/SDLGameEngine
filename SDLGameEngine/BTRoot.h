#pragma once
#include "BTComposite.h"
#include <list>
class BTRoot :
	public BTComposite
{
public:
	BTRoot();
	~BTRoot();
	BTState Update();
};

