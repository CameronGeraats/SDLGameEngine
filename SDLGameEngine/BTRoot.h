#pragma once
#include "BTComposite.h"
#include <list>
class BTRoot :
	public BTComposite
{
public:
	BTRoot();
	~BTRoot();

	void OnStart();
	BTState OnUpdate();
};

