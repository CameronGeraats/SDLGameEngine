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

			if (x < 0 || x >= finder->m_width || y < 0 || y >= finder->m_height)
			{
				continue;
			}
			if (i == 0 && j == 0)
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


int PathNode::CalculateCost(int destX, int destY)
{
	int deltaX = abs(xCoordinate - destX);
	int deltaY = abs(yCoordinate - destY);

	int min = std::min(deltaX, deltaY);
	int max = std::max(deltaX, deltaY);
	
	return 14 * min + 10 * (max - min);
}
