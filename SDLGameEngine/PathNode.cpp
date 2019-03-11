#include "PathNode.h"
#include "Pathfinder.h"


PathNode::PathNode()
{
}


PathNode::~PathNode()
{
}

std::list<PathNode*> PathNode::Neighbours()
{
	std::list<PathNode*> neighbours;
	for (int i = -1; i <= 1; i++)
	{
		for (int j = -1; j <= 1; j++)
		{
			int x = xCoordinate + i;
			int y = yCoordinate + j;

			if (x < 0 || x >= 10 || y < 0 || y >= 10)
			{
				continue;
			}
			if (finder->grid[x][y]->blocked)
			{
				continue;
			}
			neighbours.push_back(finder->grid[x][y]);
		}
		return neighbours;
	}
}
