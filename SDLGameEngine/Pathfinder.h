#pragma once

#include <list>
#include "PathNode.h"
#include <vector>
#include "Game.h"

class Pathfinder
{
public:
	Pathfinder(Game* game, int _width = 10, int _height = 10);
	~Pathfinder();


	std::vector<std::vector<PathNode*>> grid;

	bool FindPath(PathNode* start, PathNode* finish);

	friend class PathNode;

	int m_width = 10;
	int m_height = 10;
	Game* game;
};

