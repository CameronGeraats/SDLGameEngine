#pragma once
#include "Behaviour.h"
class Cursor :
	public Behaviour
{
public:
	Cursor();
	~Cursor();

	virtual void Update();
};

