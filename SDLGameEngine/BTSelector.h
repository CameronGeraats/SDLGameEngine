#pragma once
#include "BTComposite.h"
#include <list>
class BTSelector :
	public BTComposite
{
public:
	BTSelector();
	~BTSelector();
	BTState Update();
};

