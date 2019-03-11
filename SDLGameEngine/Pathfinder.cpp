#include "Pathfinder.h"
#include <time.h>


Pathfinder::Pathfinder(Game* _game, int _width, int _height)
{
	m_width = _width;
	m_height = _height;
	game = _game;

	for (int i = 0; i < m_width; i++)
	{
		grid.push_back(std::vector<PathNode*>());
		for (int j = 0; j < m_height; j++)
		{
			PathNode* node = new PathNode();
			node->xCoordinate = i;
			node->yCoordinate = j;
			if (rand() % 100 < 30)
			{
				node->blocked = true;
				game->Instantiate(game->Prefab("Obstacle"), 100 * i + 50, 100 * j + 50);
			}
			grid[i].push_back(node);
		}
	}
}


Pathfinder::~Pathfinder()
{
}

std::list<PathNode*> Pathfinder::FindPath(PathNode* start, PathNode* finish)
{
	std::list<PathNode*> open;
	std::list<PathNode*> closed;

	// 
}

