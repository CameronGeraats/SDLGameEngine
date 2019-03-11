#pragma once
#include <list>

class Pathfinder;
class PathNode
{
public:
	PathNode();
	~PathNode();

	bool blocked;

	int xCoordinate;
	int yCoordinate;

	std::list<PathNode*> Neighbours();

	PathNode* parent = nullptr;
	Pathfinder* finder;

	int hCost;
	int gCost;

	int CalculateCost(int destX, int destY);
	inline int FCost() { return hCost + gCost; }
};

