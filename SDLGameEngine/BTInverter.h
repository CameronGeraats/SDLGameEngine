#pragma once
#include "BTDecorator.h"
class BTInverter :
	public BTDecorator
{
public:
	BTInverter();
	~BTInverter();
	BTState OnUpdate();
};

