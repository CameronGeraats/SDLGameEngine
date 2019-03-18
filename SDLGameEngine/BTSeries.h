#pragma once
#include "BTComposite.h"
#include <list>
class BTSeries :
	public BTComposite
{
public:
	BTSeries();
	~BTSeries();
	BTState Update();
};

