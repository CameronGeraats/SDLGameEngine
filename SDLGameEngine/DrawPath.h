#pragma once
#include "Behaviour.h"
#include "Pathfinder.h"
class DrawPath :
	public Behaviour
{
public:
	DrawPath();
	~DrawPath();

	Vector2 start;
	Vector2 end;
	Pathfinder* finder;

	void Update();
};

